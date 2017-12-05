//
//  Sentence.cpp
//  COMP345A3
//
//  Created by Zhao Rui on 2017-11-02.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//


#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "../headers/Sentence.h"
#include "../headers/SentenceTokenizer.h"

using namespace std;

ostream &operator<<(ostream &output, const Sentence &d) {
    output << "File name of this document is " << d.getFileName()
           << "\nThe stopwordVector of this file(after tokenization is:\n";
    output << d.getContent();
    return output << endl;
}

Sentence::Sentence() {};

Sentence::Sentence(const std::string &name) {
    fileName = name;
    ifstream input(name);
    if (!input) {
        cout << "Cannot open the file: " << fileName << ", program will terminate.";
        exit(EXIT_FAILURE);
    }
    content = string((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));
    tokens = SentenceTokenizer(content).getTokens();
    size = tokens.size(); // how many setences we have
    /*for (const string token : tokens) {
        ++(dictionary[token]);
    }*/
    input.close();
}

const size_t Sentence::getSize() const {
    return size;
}

const size_t Sentence::getPos(const std::string &sen) const {
    auto it = find(begin(tokens), end(tokens), sen);
    size_t pos = distance(tokens.begin(), it);
    return pos;
}


