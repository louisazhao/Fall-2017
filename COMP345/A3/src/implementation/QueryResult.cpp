#include <iostream>
#include <string>
#include "../headers/QueryResult.h"
#include "../headers/IndexItem.h"

using namespace std;

ostream &operator<<(ostream &os, const QueryResult &qR) {
    os << "Indexed item : " << qR.doc.getFileName() << " , Score : " << qR.score << endl;
    return os;
}

QueryResult::QueryResult() : score(0) {}

QueryResult::~QueryResult(){}

QueryResult::QueryResult(IndexItem doc, const double score) : doc(doc), score(score) {}
