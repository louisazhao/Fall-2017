//
//

#include <string>
#include <vector>
#include <map>
#include "../headers/IndexItem.h"
#include "../headers/DocumentIndexer.h"

using namespace std;

ostream &operator<<(std::ostream &out, const DocumentIndexer &i) {
    out << "Indexed " << i.size << " documents." << endl;
    return out;
}

DocumentIndexer::DocumentIndexer(){}


DocumentIndexer::~DocumentIndexer(){}
