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

#include <ctime>
#include <ratio>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

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
    docFreMap = std::map<const std::string, unsigned long>();
}

Indexer::~Indexer() {}

const long Indexer::getSize() const {
    return size;
}

const std::map<const std::string, unsigned long> Indexer::getDictionary() {
    return Indexer::dictionary;
};

/**
* 1. term frequency (in one document)
* 2. document frequency (in all document)
* 3. calculate weight, based on 1 and 2.
* 4. update score map
*/
void Indexer::normalize() {
    mergeDictionary();

    //std::vector<IndexItem> itemList;

    size_t size = itemList.size();
    size_t pthreadNumber = size / 10;
    for (int i = 0; i < 9; i++) {
        int indexBegin = i * pthreadNumber;
        int indexEnd = (i + 1) * pthreadNumber;
        thread t(&Indexer::subThread, this, indexBegin, indexEnd);
        threadVector.push_back(std::move(t));
    }

    int indexBegin = 9 * pthreadNumber;
    int indexEnd = size - 1;
    thread t(&Indexer::subThread, this, indexBegin, indexEnd);
    threadVector.push_back(std::move(t));

    for (auto &t : threadVector) {
        t.join();
    }
}

void Indexer::subThread(size_t from, size_t to) {
    for (unsigned int i = from; i < to; ++i) {
        IndexItem d = itemList[i];
        cout << "Indexing file: " << d.getFileName() << endl;
        std::map<const std::string, unsigned long> dicMap = d.getDictionary();
        for (const auto &kv : dicMap) {
            //kv.first: word
            //d: IndexItem
            //w: weight
            double w = getWeight(kv.first, kv.second, d);

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

const double Indexer::getWeight(const std::string &w, const IndexItem &d) const {
    double tf = searchDictionary(d.getDictionary(), w);
    if (tf == 0)  // if we do not find this word in this document
    {
        return 0;
    }
    double df = getDocumentFrequency(w);

    const double tf_idf = (1 + log(tf)) * log(size / df);
    return tf_idf;
}

const double Indexer::getWeight(const std::string &w, double tf, const IndexItem &d) const {
    double df = getDocumentFrequency(w);

    const double tf_idf = (1 + log(tf)) * log(size / df);
    return tf_idf;
}

const double Indexer::getQueryWeight(const std::string &w, const IndexItem &d) const {

    double tf = searchDictionary(d.getDictionary(), w);

    if (tf == 0)  // if we do not find this word in this document
    {
        return 0;
    }

    double df = getDocumentFrequency(w);

    const double tf_idf = (1 + log(tf)) * log(size / df);
    return tf_idf;
}

/**
* this word appeared in how many documents
*/
const double Indexer::getDocumentFrequency(const std::string &w) const {
    return searchDictionary(docFreMap, w);
    /*
    double df = 0;
    for (const IndexItem &ds: itemList)
    {
        if (searchDictionary(ds.getDictionary(), w))
        {
            ++df;
        }
    }
    return df;
    */
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

const vector<QueryResult> Indexer::queryByCount(const std::string s, const unsigned int top) {
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
        //cout << "in file: " << d.getFileName() << ", searching: " << d.getContent() << endl;
        double score = 0;
        double qd = 0;
        double q_i = 0.0;
        double w_i = 0.0;
        for (const std::string query : queries) {
            if (searchDictionary(dictionary, query)) {
                double w_iq = queryWeight(query, queries);
                double w_ij = getQueryWeight(query, d);
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

const IndexItem *Indexer::operator[](unsigned long index) const {
    const IndexItem *item = &(itemList[index]);
    return item;
}

/*
const unsigned long
Indexer::searchDictionary(std::map<const std::string, unsigned long> dicMap, const std::string word) const
{
    try
    {
        return dicMap.at(word);
    }
    catch (const std::exception &e)
    {
        return 0;
    }
    //return dicMap.at(word);
    //return docDic[word];
}
*/

const unsigned long
Indexer::searchDictionary(std::map<const std::string, unsigned long> dicMap, const std::string word) const {
    map<const std::string, unsigned long>::const_iterator got = dicMap.find(word);
    if (got != dicMap.end()) {
        return got->second;
    }
    return 0;

    //return dicMap.at(word);
    //return docDic[word];
}

/*
* Merge one document's dictionary into the global dictionary.
*/
void Indexer::mergeDictionary() {
    for (IndexItem d : itemList) {
        for (const auto &pair : d.getDictionary())//localMap has no duplicate keys, so we can updaet document frequency safely
        {
            (dictionary[pair.first]) += pair.second;
            // calculate document frequency here
            (docFreMap[pair.first]) += 1;
        }
    }
}
