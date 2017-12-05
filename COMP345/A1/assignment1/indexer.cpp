/**
@author
            40014082    Ling Tan
            27419694    Vincent Boivin
            40018813    Rui Zhao


@date       09/21/2017
@version    1.0
@complier   gcc 4.9.2
@due        October 3

********************************************************************************************************************************************************
                                                    Assignment #1 description


Task 1: “Document Indexing”
    You have to build a dictionary, which is a set of all words that appear across all documents.
    To build the dictionary:
        (i) process all input documents;
        (ii) split the input text into tokens using whitespace and punctuation; and
        (iii) convert all characters to lower case. Count the occurrence of each token per document and print the results in a table sorted by token.


Input:
    Read a configuration file (e.g., index.txt) that specifies which documents to index.
        Each line in this file contains the filename of a document.
        That is, you have open each document listed in this configuration file and add it to your document-term matrix.

Processing:
    Compute two versions of the document-term matrix:
        (i) A complete matrix, which contains all tokens.
        (ii) A filtered matrix, where you remove all tokens that come from a list of stopwords.

Output:
    Print the two versions of the document-term matrix as defined in the pdf.
        Use stream manipulators to format the table entries:
            dictionary words left-adjusted, fixed length,
            numbers right-adjusted,
            same width for each column.
        Additionally, print a legend indicating the file name for each document (column in the table).

Coding guidelines:
    Submit a single file indexer.cpp, which must include your indexing functions, as well as a main() function to run your code.
    Include the group members (names, ids) in a comment at the top of the file.
    Your code must be possible to compile your code on any platform using the gcc compiler.
********************************************************************************************************************************************************
**/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <regex>
#include <unordered_set>

using namespace std;

/* A map using a filename as a key, and a number as this key's value. This number is how many times a specific word has been found in this file.
* This map would be initialized when reading the configuration file. The keys are filenames, the values are 0.
*
* We need this map to simply the situation that (a new word is found, and we need to add a new entry to wordMap).
* We also need this map to simply the display.
*/
map<string, unsigned int> fileAndCountMap;
map<string, unsigned int> fileAndTotalMap;

string stopwordFile = "stopwords.txt";
unordered_set<string> stopwords;

// A map using a word as a key, and a map (i.e., #fileAndCountMap#) as this key's value.
map<string, map<string, unsigned int>> wordMap;

void readfileList();
void readStopwords();
void processFile();
string matchWord(string);
bool isDelimiter(char);
void updateWordMap(string, string);
void print(bool);

string stringProcess1(string);
string stringProcess2(string);
string stringProcess3(string);

int main()
{
    //read file list
    readfileList();

    //read words from each file in the file list into #wordMap#
    processFile();

    //print out the table
    print(true);
    readStopwords();
    print(false);
}

void readfileList()
{
    string config;
    cout << "Enter the configuration file: "<<endl;
    cin >> config;
    ifstream ifs(config.c_str());
    if(!ifs)
    {
        cerr << "The configuration file: " << config << " cannot be opened. The program would terminate." << endl;
        exit(EXIT_FAILURE);
    }
    string line;
    while(getline(ifs, line))
    {
        fileAndCountMap.insert({line, 0});
        fileAndTotalMap.insert({line, 0});
    }
    ifs.close();
}

void readStopwords()
{
    ifstream ifs(stopwordFile);
    if(!ifs)
    {
        cerr << "The stopwords file: " << stopwordFile << " cannot be opened. The program would terminate." << endl;
        exit(EXIT_FAILURE);
    }
    string line;
    while(getline(ifs, line))
    {
        stopwords.insert(line);
    }
    ifs.close();
}

void processFile()
{
    for(map<string, unsigned int>::const_iterator it = fileAndCountMap.begin(); it != fileAndCountMap.end(); ++it)
    {
        string filename = it->first;
        ifstream inputFile(filename);
        if(!inputFile)
        {
            cerr << "The file: " << filename << " cannot be opened. The program would terminate." << endl;
            exit(EXIT_FAILURE);
        }
        string word;
        while(inputFile >> word)
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            word = matchWord(word);
            updateWordMap(word, filename);
        }
        inputFile.close();
    }
}

string matchWord(string word)
{//const vector<char> delim={',','.','!','?','\"','\'','(',')',':',';'}; //delimiter list
    if(isDelimiter(word[0]))//if the first character is not an alpha, delete it
        word=word.substr(1,(word.length()-1));
    if(isDelimiter(word[0]))//if the second first is also not an alpha, delete it
        word=word.substr(1,(word.length()-1));
    if(isDelimiter(word[word.length()-1])&&(word[word.length()-1]!='\''))//if the last one is not an alpha and it's not a "'", delete it(for example students')
        word=word.substr(0,(word.length()-1));
    if(isDelimiter(word[word.length()-1])&&(word[word.length()-1]!='\''))//if the second last one is not an alpha and it's not a "'", delete it(for example students'.)
        word=word.substr(0,(word.length()-1));
    return word;
}

bool isDelimiter(char c)
{
    const vector<char> delim={',','.','!','?','\"','\'','(',')',':',';'}; //delimiter list
    for(size_t i=0;i<delim.size();i++)
    {
        if(c==delim[i])
            return true;
    }
    return false;
}

void updateWordMap(string word, string filename)
{
    //update map chain
    auto searchWord = wordMap.find(word);
    if(searchWord != wordMap.end())  // we found the word!
    {

        ++(searchWord->second)[filename];
        //cout << "find: " << word << ":" << (searchWord->second)[filename] << endl;
        //wordMap[word][filename]++; //already in this filename loop.
    }
    else
    {
        //initialize the list,if the word is not in the wordMap
        wordMap.insert({word, fileAndCountMap});
        wordMap[word][filename]++;//increment the count corresponding to this filename
        //cout << "did not find: " << word << ":" << wordMap[word][filename] << endl;
    }
    fileAndTotalMap[filename]++;
}

void print(bool withStopwords)
{
    unsigned int width = static_cast<unsigned int>(20 + 15 * fileAndCountMap.size() + 3);
    char f_char = std::cout.fill();

    cout << "\n";
    cout << "\t" << "Dictionary with" << (withStopwords? "" : "out") << " stopwords\n";
    cout << "\t" << setfill('-') << setw(width) << "\n";
    cout << setfill(f_char);

    // show filenames
    cout << "\t" << "|"  << setw(20) << left << "Dictionary" << "|";

    unsigned int i_1=1;
    for(map<string,unsigned int>::const_iterator it = fileAndTotalMap.begin(); it != fileAndTotalMap.end(); ++it)
    {
        string s = "Doc";
        s += to_string(i_1);
        cout << right << setw(14) << s << "|";
        ++i_1;
    }

    /*
    for(map<string,unsigned int>::const_iterator it = fileAndCountMap.begin(); it != fileAndCountMap.end(); ++it)
    {
        cout << right << setw(14) << it->first << "|";
    }
    */

    cout << "\n";
    cout << "\t" << setfill('-') << setw(width) << "\n";
    cout << setfill(f_char);

    // show table
    for(map<string, map<string, unsigned int>>::const_iterator it = wordMap.begin(); it != wordMap.end(); ++it)
    {
        map<string,unsigned int>fileAndCountMap = it->second;
        const string w = it->first;
        if(!withStopwords)
        {
            unordered_set<string>::const_iterator got = stopwords.find(w);
            if (!(got == stopwords.end()))
            {
                continue;
            }
        }
        cout << "\t" << "|" << setw(20) << left << it->first << "|";; //this will show the words
        for(map<string,unsigned int>::const_iterator itt = fileAndCountMap.begin(); itt != fileAndCountMap.end(); ++itt)
        {
            cout << right << setw(14) << itt->second << "|"; //this will show the number of times a word is found in a doc
        }
        cout << "\n";
    }

    cout << "\t" << setfill('-') << setw(width) << "\n";
    cout << setfill(f_char);

    // show total
    cout << "\t" << "|" << setw(20) << left << "Total" << "|";
    if(withStopwords)
    {
        for(map<string,unsigned int>::const_iterator it = fileAndTotalMap.begin(); it != fileAndTotalMap.end(); ++it)
        {
            cout << right << setw(14) << it->second << "|";
        }
    }
    else
    {
        for(map<string,unsigned int>::const_iterator it = fileAndTotalMap.begin(); it != fileAndTotalMap.end(); ++it)
        {
            unsigned countStopwords = 0;
            for (const auto& elem: stopwords)
            {
                countStopwords += wordMap[elem][it->first];

            }
            cout << right << setw(14) << (it->second - countStopwords) << "|";
        }
    }


    cout << "\n";
    cout << "\t" << setfill('-') << setw(width) << "\n";
    cout << setfill(f_char);


    unsigned int i_2=1;
    for(map<string,unsigned int>::const_iterator it = fileAndTotalMap.begin(); it != fileAndTotalMap.end(); ++it)
    {
        string s = "Doc";
        s += to_string(i_2);
        cout << "\t" << s << ":"<< it->first << "\n";
        ++i_2;
    }
}

/*
**
*  for testing
*/
string stringProcess1(string word)
{
    word.erase(remove_if(word.begin(),
                         word.end(),
                         [](char c)
    {
        return !(isalpha(c) || '-' == c || '\'' == c);
    }), word.end());
    return word;
}

string stringProcess2(string word)
{
    std::regex re ("([a-zA-Z]+[^\\s]*[\\w|'])|([0-9]+[^\\s]*[a-zA-Z][^\\s]*[\\w|'])");
    // if begins with a letter, the following may contain any non-whitespace characters, and must end with a letter or a number or a "'"
    // if begins with a number, the following may contain any non-whitespace characters, and must contain one letter, and must end with a letter or a number of a "'"
    std::smatch m;

    while (std::regex_search(word, m, re))
    {
        std::cout << m[0] << '\n';
        word = m.suffix();
    }
    return word;
}

string stringProcess3(string word)
{
    std::regex re ("([a-zA-Z]+[^\\s]*[\\w|'])");
    // begins with a letter, the following may contain any non-whitespace characters, and must end with a letter or a number or a "'"
    std::smatch m;

    while (std::regex_search(word, m, re))
    {
        std::cout << m[0] << '\n';
        word = m.suffix();
    }
    return word;
}
