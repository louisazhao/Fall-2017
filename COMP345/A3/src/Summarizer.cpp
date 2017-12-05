
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <regex>
#include "headers/Stopword.h"
#include "headers/Indexer.h"
#include "headers/Sentence.h"
#include "headers/SentenceIndexer.h"
#include "headers/Document.h"

using namespace std;

vector<IndexItem> docVector;
Indexer* indexer;
Stopword sw;
bool keepQuery;
void readfileList();
void processFile();
void readKeywords();
void print(vector<QueryResult>);
void print(bool);

int main()
{
    //read file list
    readfileList();

    indexer = new SentenceIndexer();

    //read words from each file in the file list into #wordMap#
    processFile();

    keepQuery = true;

    //print(true);
    while(keepQuery){
        readKeywords();
    }

    delete indexer;
    return 0;
}

void readfileList()
{
    string config = "index3_1.txt";
    //cout << "Enter the configuration file: " << endl;
    //cin >> config;
    ifstream ifs(config.c_str());
    if(!ifs)
    {
        cerr << "The configuration file: " << config << " cannot be opened. The program would terminate." << endl;
        exit(EXIT_FAILURE);
    }
    string line;
    IndexItem* s;
    while(getline(ifs, line))
    {
        s = new Sentence(line);
        const vector <string> tokens = s->getTokens();// get all sentences
        for (const string token : tokens) {
            //cout << "FileName: " << s.getFileName() << ", Position is: " << s.getPos(token) << endl << "\t" << "Sentence is: " << token << endl;
            // each sentence is a document, so we put every sentence as a document into the docVector
            Document d;
            d.tokenizeByContent(s->getFileName(), token);// write filename, content (which is the sentence itself), and tokenize
            docVector.push_back(d);
        }
    }
    delete s;
    ifs.close();
    //exit(0);
}

void processFile()
{
    for(const IndexItem & s : docVector)
    {
        s >> *indexer;// read one sentence

        /*const vector <string> tokens = doc.getTokens();

        for (const string token : tokens) {
            // each sentence is a document
            Document d;

            d.tokenizeByContent(doc.getFileName(), token);// write filename, content (which is the sentence itself), and tokenize
            cout << "sentences size: " << d.getSize();

            d >> indexer;// add d to documentList
        }*/
    }

    indexer->normalize();
}

void readKeywords()
{
    string essayFile;
    cout << "Enter the file containing an essay topic: "<< endl;
    if(cin.eof()){
        keepQuery = false;
        return;
    }
    cin >> essayFile;
    IndexItem* d = new Document(essayFile);
    vector<QueryResult> qrVector = indexer->query(d->getContent(), 500);
    print(qrVector);
    delete d;
}

void print(bool withStopwords)
{
    cout.precision(5);
    unsigned int width = static_cast<unsigned int>(20 + 15 * docVector.size() + 18);
    char f_char = std::cout.fill();

    cout << "\n";
    cout << "\t" << "Dictionary with" << (withStopwords? "" : "out") << " stopwords\n";
    cout << "\t" << setfill('-') << setw(width) << "\n";
    cout << setfill(f_char);

    // show file names
    cout << "\t" << "|"  << setw(20) << left << "Dictionary" << "|";

    unsigned int i_1=1;
    for(const IndexItem & doc : docVector)
    {
        string s = "Doc";
        s += to_string(i_1);
        cout << right << setw(14) << s << "|";
        ++i_1;
    }
    cout << setw(14) << "docFre" << "|";

    cout << "\n";
    cout << "\t" << setfill('-') << setw(width) << "\n";
    cout << setfill(f_char);

    // show table
    for (const auto &kv : indexer->getDictionary()) {
        string w = kv.first;
        if(!withStopwords)
        {
            if (sw(w))
            {
                continue;
            }
        }

        cout << "\t" << "|" << setw(20) << left << w << "|";; //this will show the words

        for(const IndexItem & doc : docVector)
        {
            double weight = indexer->getWeight(w, doc);
            cout << right << setw(5) << indexer->searchDictionary(doc.getDictionary(), w) << ":" << setw(8) << weight << "|"; //this will show the number of times a word is found in a doc
        }
        cout << setw(14) << indexer->getDocumentFrequency(w) << "|";
        cout << "\n";
    }

    cout << "\t" << setfill('-') << setw(width) << "\n";
    cout << setfill(f_char);

    // show total
    cout << "\t" << "|" << setw(20) << left << "Total" << "|";
    if(withStopwords)
    {
        for(const IndexItem & doc : docVector)
        {
            unsigned countWords = 0;
            for(const auto& elem:doc.getDictionary()){
                countWords+=elem.second;
            }
            cout << right << setw(14) << countWords << "|";
        }
    }
    else
    {
        for(const IndexItem & doc : docVector)
        {
            unsigned countWords = 0;
            for(const auto& elem:doc.getDictionary()){
                if(!sw(elem.first)){
                    countWords+=elem.second;
                }
            }
            cout << right << setw(14) << countWords << "|";
        }
    }
    cout << setw(14) << " " << "|";

    cout << "\n";
    cout << "\t" << setfill('-') << setw(width) << "\n";
    cout << setfill(f_char);


    unsigned int i_2=1;
    for(const IndexItem & doc : docVector)
    {
        string s = "Doc";
        s += to_string(i_2);
        cout << "\t" << s << ":"<< doc.getFileName() << "\n";
        ++i_2;

    }

}

void print(vector<QueryResult> qrVector)
{
    //string: fileName, size_t: position, string: content of the sentence
    map<string, map<size_t, string>> mapPrinter;
    for(const QueryResult & qr : qrVector)
    {
        IndexItem d = qr.doc;
        Sentence s(d.getFileName());// read I/O again to find Position.
        size_t p = s.getPos(d.getContent());
        //cout << "\t" << "position:" << p << "\t" << "score: " << qr.score << "\t" << "fileName: " << d.getFileName()<< "\t" << "content: " << d.getContent()  << endl;
        auto searchFileName = mapPrinter.find(d.getFileName());
        if(searchFileName != mapPrinter.end()){//we found the fileName
            (searchFileName->second).insert({p, d.getContent()});
        }else{
            mapPrinter.insert({d.getFileName(), {{p, d.getContent()}}});
        }
    }

    cout << "\n" << "Generated essay: \n\t";
    for (const auto &fileName : mapPrinter) {
        for(const auto &content: fileName.second){
            cout << content.second << " ";
        }
    }

    //for debug
    cout << "\n";
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << "This is the output order:" << endl;
    for(const auto &fileName : mapPrinter)
    {

        cout << fileName.first << endl;
        for(const auto &content: fileName.second){
            cout << "\t" << "position:" << content.first << "\t\t" << "content: " << content.second << endl;
        }
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
}
