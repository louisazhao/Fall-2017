//
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "../headers/SentenceIndexer.h"
#include "../headers/Document.h"

using namespace std;

ostream &operator<<(std::ostream &out, const SentenceIndexer &i) {
    out << "Indexed " << i.size << " documents." << endl;
    return out;
}

SentenceIndexer::SentenceIndexer() {
}

const IndexItem* SentenceIndexer::operator[](unsigned long index) const {
    const IndexItem* item = &(itemList[index]);
    return item;
}

const vector<QueryResult> SentenceIndexer::query(const std::string s, const unsigned int top) {
    //istringstream iss(s);
    //vector<string> vStrings{istream_iterator<string>{iss}, istream_iterator<string>{}};

    Document d;
    d.tokenizeByContent("", s);
    string topic = s;
    topic.erase(std::remove(topic.begin(), topic.end(), '\n'), topic.end());
    cout << "Topic:" << "\n\t" << topic << "\n\n";
    vector<string> vStrings = d.getTokens();

    multimap<const double, const IndexItem, std::greater<double>> rank = score(vStrings);
    vector<QueryResult> qrV;
    size_t i = 0;
    for (const auto &kv : rank) {
        if (i <= top) {
            qrV.push_back({(kv.second), kv.first});
        } else {
            break;
        }
        i += kv.second.getSize();
    }
    return qrV;
}

const std::vector<QueryResult> SentenceIndexer::queryByCount(const std::string s, const unsigned int top){
    Document d;
    d.tokenizeByContent("", s);
    string topic = s;
    topic.erase(std::remove(topic.begin(), topic.end(), '\n'), topic.end());
    cout << "Topic:" << "\n\t" << topic << "\n\n";
    vector<string> vStrings = d.getTokens();

    multimap<const double, const IndexItem, std::greater<double>> rank = score(vStrings);
    vector<QueryResult> qrV;
    unsigned i = 0;
    for (const auto &kv : rank) {
        if (i < top) {
            qrV.push_back({(kv.second), kv.first});
        } else {
            break;
        }
        ++i;
    }
    return qrV;
}