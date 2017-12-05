#ifndef query_result_H
#define query_result_H

#include <iostream>
#include <string>
#include "Document.h"

/**
* Storing the document and the score information for the query word
*/
class QueryResult {
	friend std::ostream & operator<<(std::ostream &, const QueryResult &);

public:
    /**
     * the current document in the query result.
     */
    const Document doc;

    /**
     * the socre realted to this document
     */
    const double score;

	/**
	 * Default constructor
	 * @param doc
	 * @param score
	 */
	QueryResult(Document doc, const double score);
private:

};
#endif
