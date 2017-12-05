//
//  main.cpp
//  TokenTest
//
//  Created by Zhao Rui on 2017-09-26.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

bool isDelimiter(char);
const vector<char> delim={',','.','!','?','\"','\'','(',')',':',';'};
bool isSpecialCase(const string&);


int main(int argc, const char * argv[]) {
    ifstream inputFile("textFile.txt");
    if(!inputFile)
    {
        cerr<<"Cannot open the file"<<endl;
        exit(EXIT_FAILURE);
    }
//    string word;
//    vector<string> words;
//    while(inputFile>>word)
//    {
//        if(isDelimiter(word[0]))//if the first character is not a alpha, delete it
//           word=word.substr(1,(word.length()-1));
//        if(isDelimiter(word[word.length()-1])&&(word[word.length()-1]!='\''))//if the last one is not a alpha and it's not a "'", delete it(for example students')
//            word=word.substr(0,(word.length()-1));
//        if(isDelimiter(word[word.length()-1])&&(word[word.length()-1]!='\''))//if the second last one is not a alpha and it's not a "'", delete it(for example students'.)
//            word=word.substr(0,(word.length()-1));
//        words.push_back(word);
//    }
//    
//    for(string word:words)
//    {
//        cout<<word<<endl;
//    }
    string word;
    string sentence;
    vector<string> sentences;
    while(getline(inputFile,word,' '))
    {
        if(word[word.length()-1]!='!'||word[word.length()-1]!='?'||word[word.length()-1]!='.')
        {
            sentence=sentence+word+" ";
        }
        else if(isSpecialCase(word))
        {
            sentence=sentence+word+" ";
        }
        else if (word[word.length()-1]=='!'||word[word.length()-1]=='?'||word[word.length()-1]=='.')
        {
            sentence+=word;
            sentences.push_back(sentence);
            sentence="";
        }
     }
    for(string element:sentences)
    {
        cout<<element<<endl;
    }
}

bool isDelimiter(char c)
{
    for(size_t i=0;i<delim.size();i++)
    {
        if(c==delim[i])
            return true;
    }
    return false;
}

bool isSpecialCase(const string& s)
{
    ifstream inputFile("abbreviation.txt");
    if(!inputFile)
    {
        cerr<<"Cannot open abbreviation file."<<endl;
        exit(EXIT_FAILURE);
    }
    string word;
    while(inputFile>>word)
    {
        return (s==word);
    }
    inputFile.close();
    return false;
}
