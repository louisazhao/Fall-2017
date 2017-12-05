//
// Created by ling on 07/11/17.
//

#include <iostream>
#include <fstream>
#include "../headers/IndexItem.h"

using namespace std;

ostream &operator<<(ostream &output, const IndexItem &d) {
    output << "File name of this document is " << d.getFileName()
           << "\nThe stopwordVector of this file(after tokenization is:\n";
    output << d.getContent();
    return output << endl;
}

IndexItem::IndexItem() : fileName(""), size(0), content("") {
    tokens = std::vector<std::string>();
    dictionary = std::map<const std::string, unsigned long>();
}

IndexItem::~IndexItem() {}

const std::string IndexItem::getFileName() const { return fileName; }

const std::map<const std::string, unsigned long> IndexItem::getDictionary() const { return dictionary; };

const std::size_t IndexItem::getSize() const { return size; };

const std::string IndexItem::getContent() const { return content; }

const std::vector<std::string> IndexItem::getTokens() const { return tokens; }