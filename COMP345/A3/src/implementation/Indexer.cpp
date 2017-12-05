/**
 *
 */

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <iterator>
#include "../headers/Indexer.h"

using namespace std;

ostream &operator<<(std::ostream &out, const Indexer &i) {
    out << "Indexed " << i.size << " documents." << endl;
    return out;
}

void operator>>(const IndexItem &d, Indexer &i) {
    i.itemList.push_back(d);
    ++i.size;
}

Indexer::Indexer() : size(0) {
    itemList = vector<IndexItem>();
    dictionary = std::map<const std::string, unsigned long>();
}

Indexer::~Indexer() {}

const long Indexer::getSize() const {
    return size;
}

const std::map<const std::string, unsigned long> Indexer::getDictionary() {
    return Indexer::dictionary;
};

void Indexer::normalize() {
    for (IndexItem d : itemList) {
        cout << "Indexing file: " << d.getFileName() << endl;
        mergeDictionary(d.getDictionary());// for task 1 display


        //std::map<const std::string, std::multimap<const double, const IndexItem>> tf_idf_map;

        std::map<const std::string, unsigned long> dicMap = d.getDictionary();
        for (const auto &kv : dicMap) {
            double w = getWeight(kv.first, d);
            auto searchWord = tf_idf_map.find(kv.first);
            if (searchWord != tf_idf_map.end())  // we found the word!
            {
                (searchWord->second).insert({w, d});
            } else {
                tf_idf_map.insert({kv.first, {{w, d}}});
            }
        }
    }
}

const double Indexer::getDocumentFrequency(const std::string &w) const {
    double df = 0;
    for (const IndexItem &ds: itemList) {
        if (searchDictionary(ds.getDictionary(), w)) {
            ++df;
        }
    }
    return df;
}

const double Indexer::getWeight(const std::string &w, const IndexItem &d) const {
    double tf = searchDictionary(d.getDictionary(), w);
    if (tf == 0) {// if we do not find this word in this document
        return 0;
    }
    double df = getDocumentFrequency(w);
    const double tf_idf = (1 + log(tf)) * log(size / df);
    return tf_idf;
}

const vector<QueryResult> Indexer::query(const std::string s, const unsigned int top) {
    istringstream iss(s);
    vector<string> vStrings{istream_iterator<string>{iss}, istream_iterator<string>{}};
    multimap<const double, const IndexItem, std::greater<double>> rank = score(vStrings);
    vector<QueryResult> qrV;
    size_t i = 1;
    for (const auto &kv : rank) {
        if (i <= top) {
            qrV.push_back({(kv.second), kv.first});
        } else {
            break;
        }
        ++i;
    }
    return qrV;
}

/**
 * the weight of query string
 * @param w
 * @param queries
 * @return
 */
const double Indexer::queryWeight(const std::string &w, std::vector<std::string> queries) const {
    double tf = 0;
    for (size_t i = 0; i < queries.size(); i++) {
        if (w == queries[i]) {
            ++tf;
        }
    }

    double df = getDocumentFrequency(w);

    const double tf_idf = (1 + log(tf)) * log(size / df);
    return tf_idf;
}


const std::multimap<const double, const IndexItem, std::greater<double>>
Indexer::score(const std::vector<std::string> queries) const {
    std::multimap<const double, const IndexItem, std::greater<double>> rank;
    for (const IndexItem d : itemList) {
        cout << "in file: " << d.getFileName() << ", searching: " << d.getContent() << endl;
        double score = 0;
        double qd = 0;
        double q_i = 0.0;
        double w_i = 0.0;
        for (const std::string query : queries) {
            if (searchDictionary(dictionary, query)) {
                double w_iq = queryWeight(query, queries);
                double w_ij = getWeight(query, d);
                //std::map<const std::string, std::multimap<const double, const Document>>

                qd += w_iq * w_ij;
                q_i += pow(w_iq, 2);
                w_i += pow(w_ij, 2);
            } else {
                continue;
            }

        }
        if ((sqrt(q_i) * sqrt(w_i)) == 0) {
            score = 0;
        } else {
            score = qd / (sqrt(q_i) * sqrt(w_i));
        }
        rank.insert({score, d});
    }
    return rank;

}

const IndexItem* Indexer::operator[](unsigned long index) const {
    const IndexItem* item = &(itemList[index]);
    return item;
}

const unsigned long
Indexer::searchDictionary(std::map<const std::string, unsigned long> dicMap, const std::string word) const {
    try { return dicMap.at(word); } catch (const std::exception &e) { return 0; }
    //return dicMap.at(word);
    //return docDic[word];
}

void Indexer::mergeDictionary(const std::map<const std::string, unsigned long> &localMap) {
    for (const auto &pair : localMap) {
        (dictionary[pair.first]) += pair.second;
    }
}