#include <iostream>
#include "QueryResult.h"
#include "Document.h"

using namespace std;

ostream & operator<<(ostream &output, const QueryResult &q) {
    output << "Document : " << q.doc.getFileName() << ", Score: " << q.score;
    return output << endl;
}

QueryResult::QueryResult(Document doc, const double score):doc(doc), score(score) {

}
