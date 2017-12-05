/**
 *
 */

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <iterator>
#include "Indexer.h"
#include "Document.h"
#include "QueryResult.h"

using namespace std;

ostream &operator<<(std::ostream &out, const Indexer &i) {
    out << "Indexed " << i.size << " documents." << endl;
    return out;
}

void operator>>(const Document &d, Indexer &i) {
    i.documentList.push_back(d);
    ++i.size;
}

Indexer::Indexer() : size(0) {
    documentList = vector<Document>();
    dic = Dictionary();
}

const long Indexer::getSize() const {
    return size;
}

void Indexer::normalize() {
    for (Document d : documentList) {
        dic.merge(d.getDocDic());
    }

    for (Document d : documentList) {
        std::map<const std::string, unsigned long> dicMap = d.getDocDic().getMap();
        for (const auto &kv : dicMap) {
            double w = weight(kv.first, d);
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

const double Indexer::docFre(const std::string &w) const{
    double df = 0;
    for (const Document &ds: documentList) {
        if(ds.getDocDic().search(w) > 0){
            ++df;
        }
    }
    return df;
}

const double Indexer::weight(const std::string &w, const Document &d) const {
    double tf = d.getDocDic().search(w);
    if(tf == 0){
        return 0;
    }
    double df = docFre(w);
    const double tf_idf = (1 + log(tf)) * log(size / df);
    return tf_idf;
}

const vector<QueryResult> Indexer::query(const std::string s, const int top) {
    istringstream iss(s);
    vector<string> vStrings{istream_iterator<string>{iss}, istream_iterator<string>{}};
    multimap<const double, const Document, std::greater<double>> rank = score(vStrings);
    vector<QueryResult> qrV;
    int i = 1;
    for (const auto &kv : rank) {
        if (i <= top) {
            qrV.push_back({kv.second, kv.first});
        }
        ++i;
    }
    return qrV;
}

const double Indexer::query_weight(const std::string &w, std::vector<std::string> queries) const {
    double tf = 0;
    for (size_t i = 0; i < queries.size(); i++) {
        if (w == queries[i]) {
            ++tf;
        }
    }

    double df = docFre(w);

    const double tf_idf = (1 + log(tf)) * log(size / df);
    return tf_idf;
}


const std::multimap<const double, const Document, std::greater<double>> Indexer::score(const std::vector<std::string> queries) const {
    std::multimap<const double, const Document, std::greater<double>> rank;
    for (const Document d : documentList) {
        double score = 0;
        double qd = 0;
        double q_i=0.0;
        double w_i=0.0;
        for (const std::string query : queries) {
            if(dic.search(query)){
                double w_iq = query_weight(query, queries);
                double w_ij = weight(query, d);
                //std::map<const std::string, std::multimap<const double, const Document>>

                qd += w_iq*w_ij;
                q_i += pow(w_iq,2);
                w_i += pow(w_ij,2);
            }else{
                continue;
            }

        }
        if((sqrt(q_i)*sqrt(w_i)) == 0){
            score = 0;
        }else{
            score=qd/(sqrt(q_i)*sqrt(w_i));
        }
        rank.insert({score, d});
    }
    return rank;

}

const Document &Indexer::operator[](unsigned long index) const {
    return documentList[index];
}
