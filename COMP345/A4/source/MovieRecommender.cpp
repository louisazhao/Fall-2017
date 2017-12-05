/*! \mainpage Movie Recommender
 *
 * \section Introduction
 *
 * 1. Read a set of movie descriptions into an index;
 * 2. Ask a user about a movie s/he likes (which must be one in the index);
 * 3. Recommend a list of top-n other movies that s/he would also like.
 *
 * \section Authors
 * 40014082    Ling Tan
 * \n
 * 40018813    Rui Zhao
 * \n
 * 27419694    Vincent Boivin
 */


#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <assert.h>
#include <future>
#include <chrono>
#include <thread>
#include <functional>

#include "headers/Indexer.h"
#include "headers/SentenceIndexer.h"
#include "headers/IndexItem.h"
#include "headers/Document.h"
#include "headers/QueryResult.h"
#include "headers/IndexException.h"
#include <mutex>
#include "headers/Movie.h"

using namespace std;


/**
* index movie data (id and description)
*/
void indexMovieDescription();//42306

/**
* index movie
*/
void indexMovie();

void indexMovieThread(int start, int end);

/**
* index movie metadata (id and name)
*/
void indexMovieMeta();//81741


const string getInputName();

const unsigned long findIdByName(string name);

const string findDescription(unsigned long);


vector<string> split(const string &s, char delimiter);

void print(vector<QueryResult>);

/**
* Metadata of movies, contains name and id.
*/
const string movieMetaFileName = "movie.metadata.tsv";

/**
* contains movie id and its description.
*/
const string movieDataFileName = "plot_summaries.txt";

map<const unsigned long, const string> movieDescriptionMap;
map<const unsigned long, const string> movieMetaMap;
vector<Movie> movieVector;
map<const unsigned long, Movie> movieMap;
vector<IndexItem> docVector;
vector<thread> threadVector;

Indexer *indexer;
std::mutex docVector_mutex;
bool keepQuery = true;

int main() {
    indexer = new SentenceIndexer();
    indexMovieMeta();
    indexMovieDescription();
    indexMovie();
    while (keepQuery) {
        unsigned long movieId = 0;
        string name = getInputName();

        try {
            movieId = findIdByName(name);
            vector<QueryResult> qrVector = indexer->queryByCount(findDescription(movieId), 5);
            print(qrVector);
        } catch (IndexException* e) {
            cout << "Could not find the movie: " << name << endl;
            delete e;
        }
        // 2940516	Ghost In The Noonday Sun
    }
    delete indexer;
    return 0;
}


void indexMovieDescription() {
    ifstream inputFile(movieDataFileName);
    if (!inputFile) {
        cout << "Cannot open file:" << movieDataFileName << ", program will terminate." << endl;
        exit(EXIT_FAILURE);
    }
    string line;
    while (getline(inputFile, line)) {
        vector<string> fields = split(line, '\t');
        assert(fields.size() == 2 && "Encountered an error when reading movies' description.");
        unsigned long id = stoul(fields[0]);
        movieDescriptionMap.insert({id, fields[1]});
        Movie m(id, fields[0], "");
        m.setContent(fields[1]);
        movieVector.push_back(m);
        auto got = movieMap.find(id);
        if (got != movieMap.end()) {
            got->second.setContent(fields[1]);
        }
    }
    inputFile.close();
    cout << "------------->indexed movies: " << movieDescriptionMap.size() << endl;
}

/*
Add ids and titles to the database.
The ids are the keys.
The titles are the values.
e.g. 253298532 -> Ironman
*/
void indexMovieMeta() {
    std::ifstream ifs(movieMetaFileName);
    if (!ifs) {
        cerr << "Cannot open file:" << movieMetaFileName << ", program will terminate." << endl;
        exit(EXIT_FAILURE);
    }
    string line;
    while (getline(ifs, line)) {
        vector<string> fields;
        fields = split(line, '\t');
        assert(fields.size() == 9 && "Encountered an error when reading movies' metadata.");
        /**
        *
        1. Wikipedia movie ID
        2. Freebase movie ID
        3. Movie name
        4. Movie release date
        5. Movie box office revenue
        6. Movie runtime
        7. Movie languages (Freebase ID:name tuples)
        8. Movie countries (Freebase ID:name tuples)
        9. Movie genres (Freebase ID:name tuples)
        */
        movieMetaMap.insert({stoul(fields[0]), fields[2]});
        unsigned long id = stoul(fields[0]);
        movieMap.insert({id, Movie(id, fields[2], fields[3])});
    }
    cout << "------------->indexed movies meta: " << movieMetaMap.size() << endl;
    ifs.close();
}

void indexMovie() {
    //map<const unsigned long, const string> movieDescriptionMap;
    /*
    for (auto key : movieDescriptionMap) {
        thread t(indexMovieThread, std::to_string(key.first), key.second);
        threadVector.push_back(std::move(t));
    }
     */

    size_t size = movieVector.size();
    size_t pthreadNumber = size / 10;
    for (int i = 0; i < 9; i++) {
        int indexBegin = i * pthreadNumber;
        int indexEnd = (i + 1) * pthreadNumber;
        thread t(indexMovieThread, indexBegin, indexEnd);
        threadVector.push_back(std::move(t));
    }

    int indexBegin = 9 * pthreadNumber;
    int indexEnd = size - 1;
    thread t(indexMovieThread, indexBegin, indexEnd);
    threadVector.push_back(std::move(t));

    for (auto &t : threadVector) {
        t.join();
    }

    for (const IndexItem &s : docVector) {
        s >> *indexer;// read one sentence
    }

    //indexer->normalize();

}

void indexMovieThread(int from, int to) {
    for (int i = from; i < to; ++i) {
        Movie m = movieVector[i];
        Document d;
        d.tokenizeByContent(m.getFileName(), m.getContent());
        std::lock_guard<std::mutex> guard(docVector_mutex);
        docVector.push_back(d);
    }

}

const unsigned long findIdByName(string name) {
    auto it = movieMetaMap.begin(); // internalMap is std::map
    while (it != movieMetaMap.end()) {
        if (it->second == name) {
            return it->first;
        }
        ++it;
    }
    throw new IndexException("Invalid movie number");
}

const string findDescription(unsigned long serialNum)//2940516
{
    map<const unsigned long, const string>::const_iterator got = movieDescriptionMap.find(serialNum);
    if (got != movieDescriptionMap.end()) {
        return got->second;
    } else {
        //return "Invalid movie number";
        throw new IndexException("Invalid movie number");
    }
}

const string getInputName() {
    string name;
    cout << "Enter the name of one of your favourite movie: " << endl;
    getline(cin, name);
    return name;
}

vector<string> split(const string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void print(vector<QueryResult> qrVector) {
    cout << "Recommended movies:" << endl;
    for (const QueryResult &qr : qrVector) {
        IndexItem d = qr.doc;
        const unsigned long id = std::stoul(d.getFileName());
        auto got = movieMap.find(id);
        if (got != movieMap.end()) {
            cout << "\t" << got->second.getName() << "\t" << got->second.getReleaseDate() << "\t" << got->second.getId()<< "\t" << got->second.getContent() << endl;
        }

    }
}
