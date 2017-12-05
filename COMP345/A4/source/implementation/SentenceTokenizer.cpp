//
//  Sentence_tokenizer.cpp
//  COMP345A3
//
//  Created by Zhao Rui on 2017-11-02.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <sstream>
#include <fstream>
#include <algorithm>
#include "../headers/SentenceTokenizer.h"

using namespace std;

ostream &operator<<(ostream &output, const SentenceTokenizer &obj) {
    output << "Sentence tokens are: ";
    for (string element:obj.getTokens()) {
        output << element << " ";
    }
    return output;
}

SentenceTokenizer::SentenceTokenizer() {
}

SentenceTokenizer::SentenceTokenizer(const std::string &inputString) {
    string content = inputString;
    std::replace(content.begin(), content.end(), '\n', ' ');
    istringstream text(content);
    string word;
    string sentence;
    string para;
    while (getline(text, para)) {
        istringstream paragraph(para);
        while (getline(paragraph, word, ' ')) {
            if (word[word.length() - 1] == '!' || word[word.length() - 1] == '?' ||
                word[word.length() - 1] == '.') {//ending a sentence by ! ? .
                if (isSpecialCase(word)) {
                    sentence = sentence + word + " ";
                } else {
                    sentence += word;
                    trim(sentence);
                    tokens.push_back(sentence);
                    sentence = "";
                }
            } else if (word.length() >= 2 && word[word.length() - 1] == '\'' &&
                       (word[word.length() - 2] == '!' || word[word.length() - 2] == '?' ||
                        word[word.length() - 2] == '.')) {//ending a sentence by !' ?' .'
                sentence += word;
                trim(sentence);
                tokens.push_back(sentence);
                sentence = "";
            } else if (word.length() >= 2 && word[word.length() - 1] == '"' &&
                       (word[word.length() - 2] == '!' || word[word.length() - 2] == '?' ||
                        word[word.length() - 2] == '.')) {//ending a sentence by !" ?" ."
                sentence += word;
                trim(sentence);
                tokens.push_back(sentence);
                sentence = "";
            } else if (word.length() >= 3 && word[word.length() - 1] == '\'' && word[word.length() - 2] == '\'' &&
                       (word[word.length() - 3] == '!' || word[word.length() - 3] == '?' ||
                        word[word.length() - 3] == '.')) {//ending a sentence by !'' ?'' .''
                sentence += word;
                trim(sentence);
                tokens.push_back(sentence);
                sentence = "";
            } else {
                sentence = sentence + word + " ";
            }

        }
    }
}

bool SentenceTokenizer::isSpecialCase(const string &s) const {
    vector<string> specialCase;
    ifstream inputFile("abbreviation.txt");
    if (!inputFile) {
        cerr << "Cannot open abbreviation file." << endl;
        exit(EXIT_FAILURE);
    }
    string word;
    while (inputFile >> word) {
        specialCase.push_back(word);
    }
    inputFile.close();

    if (find(begin(specialCase), end(specialCase), s) != end(specialCase)) {
        return true;
    } else return false;
}
