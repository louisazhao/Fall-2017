#ifndef query_result_H
#define query_result_H

#include <iostream>
#include <string>
#include "IndexItem.h"

/**
* Storing the document and the score information for the query word
*/
class QueryResult {
    friend std::ostream & operator<<(std::ostream &, const QueryResult &);

public:

    /**
     * the current document in the query result.
     */
    const IndexItem doc;

    /**
     * the score related to this document
     */
    const double score;

    /**
     * Default constructor
     */
    QueryResult();


    ~QueryResult();
    /**
     * Constructor accepting a IndexItem and its score
     * @param doc
     * @param score
     */
    QueryResult(const IndexItem doc, const double score);
private:

};
#endif
