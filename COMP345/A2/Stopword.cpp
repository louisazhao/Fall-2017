//
//  Stopword.cpp
//  COMP345A2
//
//  Created by Zhao Rui on 2017-10-07.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "Stopword.h"
#include <fstream>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &output, const Stopword &w) {
    output << "Stopwords are:\n";
    for (string elements:w.getStopWords()) {
        output << elements << " ";
    }
    return output << endl;
}

Stopword::Stopword() {
    stopwordVector = vector<string>();//empty vector
}

Stopword::Stopword(const std::string &file) {
    ifstream inputFile(file);
    if (!inputFile) {
        cout << "Cannot open stopword file, program will terminate.";
        exit(EXIT_FAILURE);
    }
    string temp;
    while (inputFile >> temp) {
        stopwordVector.push_back(temp);
    }
    inputFile.close();
}

const vector<string> &Stopword::getStopWords() const {
    return stopwordVector;
}

bool Stopword::operator()(const string &word) {
    vector<string>::iterator it;
    it = find(stopwordVector.begin(), stopwordVector.end(), word);
    if (it != this->stopwordVector.end())
        return true;
    else
        return false;
}

