//
// Created by ling on 16/10/17.
//

#include <iostream>
#include "Dictionary.h"

using namespace std;

ostream &operator<<(ostream &output, const Dictionary &d) {
    output << "The size of dictionary is: " << d.dicMap.size();
    return output << endl;
}

Dictionary::Dictionary() {
    dicMap = map<const std::string, unsigned long>();
}

void Dictionary::insert(const std::string word) {
    ++(dicMap[word]);
}

void Dictionary::merge(const std::map<const std::string, unsigned long> & localMap) {
    for (const auto &pair : localMap) {
        (dicMap[pair.first]) += pair.second;
    }
}

void Dictionary::merge(const Dictionary & d) {
    Dictionary::merge(d.getMap());
}

const unsigned long Dictionary::search(const std::string word) const{
    try { return dicMap.at(word); } catch (const std::exception& e) { return 0; }
    //return dicMap.at(word);
    //return docDic[word];
}

const unsigned long Dictionary::getSize() const{
    return dicMap.size();
}

const std::map<const std::string, unsigned long> & Dictionary::getMap() const{
    return dicMap;
}

