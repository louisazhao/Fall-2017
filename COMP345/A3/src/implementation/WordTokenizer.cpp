//
//  Word_tokenizer.cpp
//  COMP345A3
//
//  Created by Zhao Rui on 2017-11-02.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <sstream>
#include <algorithm>
#include "../headers/WordTokenizer.h"

using namespace std;

ostream &operator<<(ostream &output, const WordTokenizer &obj) {
    output << "Word tokens are: ";
    for (string elements:obj.tokens) {
        output << elements << " ";
    }
    return output;
}

WordTokenizer::WordTokenizer() {
    tokens=vector<string>();//empty
}

WordTokenizer::WordTokenizer(const std::string &inputString) {
    istringstream text(inputString);
    string word;
    while (getline(text, word, ' ')) {
        word.erase(std::remove(word.begin(), word.end(), '\n'), word.end());
        if (isDelimiter(word[0]))//if the first character is not an alpha, delete it
            word = word.substr(1, (word.length() - 1));
        if (isDelimiter(word[0]))//if the second first is also not an alpha, delete it
            word = word.substr(1, (word.length() - 1));
        if (isDelimiter(word[word.length() - 1]) && (word[word.length() - 1] !=
                                                     '\''))//if the last one is not an alpha and it's not a "'", delete it(for example students')
            word = word.substr(0, (word.length() - 1));
        if (isDelimiter(word[word.length() - 1]) && (word[word.length() - 1] !=
                                                     '\''))//if the second last one is not an alpha and it's not a "'", delete it(for example students'.)
            word = word.substr(0, (word.length() - 1));
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        tokens.push_back(word);
    }
}

