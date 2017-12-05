/**
 *
            40014082    Ling Tan
            27419694    Vincent Boivin
            40018813    Rui Zhao
 *
 *
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <regex>
#include "Stopword.h"
#include "Indexer.h"

using namespace std;


vector<Document> docVector;
string stopwordFile = "stopwords.txt";
Indexer indexer;
Stopword sw;

void readfileList();
Stopword readStopwords();
void processFile();
void print(bool);

int main()
{
    //read file list
    readfileList();

    //read words from each file in the file list into #wordMap#
    processFile();

    //print out the table
    print(true);
    sw = readStopwords();
    //print(false);

    return 0;
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
        Document d(line);
        docVector.push_back(d);
    }
    ifs.close();
}

Stopword readStopwords()
{
    Stopword s(stopwordFile);
    return s;
}

void processFile()
{
    for(const Document & doc : docVector)
    {
        doc >> indexer;
    }

    indexer.normalize();
}

void print(bool withStopwords)
{
    cout.precision(5);
    unsigned int width = static_cast<unsigned int>(20 + 15 * docVector.size() + 17);
    char f_char = std::cout.fill();

    cout << "\n";
    cout << "\t" << "Dictionary with" << (withStopwords? "" : "out") << " stopwords\n";
    cout << "\t" << setfill('-') << setw(width) << "\n";
    cout << setfill(f_char);

    // show file names
    cout << "\t" << "|"  << setw(20) << left << "Dictionary" << "|";

    unsigned int i_1=1;
    for(const Document & doc : docVector)
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
    for (const auto &kv : indexer.dic.getMap()) {
        string w = kv.first;
        if(!withStopwords)
        {
            if (sw(w))
            {
                continue;
            }
        }

        cout << "\t" << "|" << setw(20) << left << w << "|";; //this will show the words

        for(const Document & doc : docVector)
        {
            double weight = indexer.weight(w, doc);
            cout << right << setw(5) << doc.getDocDic().search(w) << ":" << setw(8) << weight << "|"; //this will show the number of times a word is found in a doc
        }
        cout << setw(14) << indexer.docFre(w) << "|";
        cout << "\n";
    }

    cout << "\t" << setfill('-') << setw(width) << "\n";
    cout << setfill(f_char);

    // show total
    cout << "\t" << "|" << setw(20) << left << "Total" << "|";
    if(withStopwords)
    {
        for(const Document & doc : docVector)
        {
            unsigned countWords = 0;
            for(const auto& elem:doc.getDocDic().getMap()){
                countWords+=elem.second;
            }
            cout << right << setw(14) << countWords << "|";
        }
    }
    else
    {
        for(const Document & doc : docVector)
        {
            unsigned countWords = 0;
            for(const auto& elem:doc.getDocDic().getMap()){
                if(!sw(elem.first)){
                    countWords+=elem.second;
                }
            }
            cout << right << setw(14) << countWords << "|";
        }
    }


    cout << "\n";
    cout << "\t" << setfill('-') << setw(width) << "\n";
    cout << setfill(f_char);


    unsigned int i_2=1;
    for(const Document & doc : docVector)
    {
        string s = "Doc";
        s += to_string(i_2);
        cout << "\t" << s << ":"<< doc.getFileName() << "\n";
        ++i_2;

    }

}