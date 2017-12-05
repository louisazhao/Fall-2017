//
//  Document.cpp
//  COMP345A3
//
//  Created by Zhao Rui on 2017-11-02.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "../headers/Document.h"
#include "../headers/WordTokenizer.h"

/*
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>
*/

using namespace std;

ostream &operator<<(ostream &output, const Document &d) {
    output << "File name of this document is " << d.getFileName()
           << "\nThe stopwordVector of this file(after tokenization is:\n";
    output << d.getContent();
    return output << endl;
}

Document::Document() {}

Document::Document(const std::string &fileName) {

    /*char buff[FILENAME_MAX];
    GetCurrentDir( buff, FILENAME_MAX );
    std::string current_working_dir(buff);*/

    Document::fileName = fileName;
    ifstream input(fileName);
    if (!input) {
        cout << "Cannot open the file: " << fileName << ", program will terminate.";
        exit(EXIT_FAILURE);
    }

    content = string((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));

    tokens = WordTokenizer(content).getTokens();//tokenize the stopwordVector
    size = content.length();//!!! size is in characters !!!//
    for (const string token : tokens) {
        ++(dictionary[token]);
    }
    input.close();
}

const void Document::tokenizeByContent(const std::string &fileName, const std::string &content) {
    Document::fileName = fileName;
    Document::content = content;
    tokens = WordTokenizer(content).getTokens();
    size = tokens.size();//!!! size is in wrods !!!//
    for (const string token : tokens) {
        ++(dictionary[token]);
    }
}

const size_t Document::getSize() const {
    return size;
}






