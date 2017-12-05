//
//  Document.cpp
//  COMP345A2
//
//  Created by Zhao Rui on 2017-10-07.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <fstream>
#include <vector>
#include "Document.h"

using namespace std;

ostream &operator<<(ostream &output, const Document &d) {
    output << "File name of this document is " << d.getFileName()
           << "\nThe stopwordVector of this file(after tokenization is:\n";
    output << d.getContent();
    return output << endl;
}


Document::Document()
        : fileName(""), size(0), content("") {
    Tokenizer tokensOfFile;//empty
    docDic = Dictionary();
    tokens = std::vector<std::string>();
};

Document::Document(const std::string &name)
        : fileName(name), content("") {
    docDic = Dictionary();
    ifstream input(name);
    if (!input) {
        cout << "Cannot open the file, program will terminate.";
        exit(EXIT_FAILURE);
    }
    string temp = "";
    while (getline(input, temp)) {
        content += temp;//read all stopwordVector
    }
    tokensOfFile = Tokenizer(content);//tokenize the stopwordVector
    tokens = tokensOfFile.getTokens();
    updateDocDic();
    size = tokens.size();
    input.close();
}

const string Document::getFileName() const {
    return fileName;
}

const unsigned long Document::getSize() const {
    return size;
}

const string Document::getContent() const {
    return content;
}


const std::vector<std::string>& Document::getTokens() const {
    return tokens;
}
const Tokenizer& Document::getTokenizer() const {
    return tokensOfFile;
}

const Dictionary & Document::getDocDic() const{
    return docDic;
}

void Document::updateDocDic(){
    for(const string token : tokens){
        docDic.insert(token);
    }
}
