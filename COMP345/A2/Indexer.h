/**
 * The indexer is responsible for storing and maintaining your document index.
 *
 * An object idx of class indexer holds the data structures created from the input documents.
 * It has a default constructor, which creates an empty index.
 * A function size() returns the number of documents in the index.
 * A new document can be read into the index through an overloaded extractor (operator>>).
 * A function normalize() computes the tf-idf weights based on the number N of indexed documents.
 * A function query(string, int) is used to query the index with the provided string.
 *      By default, it returns the top-10 results, but this can be overridden on a per-query basis (optional second argument).
 *      If the index has not been normalized, attempting to query it will throw an exception (adding a new document after normalization also results in a non-normalized index).
 *      The query() function returns a vector<query result>, where each result object has a document and its score.
 * Class indexer also provides access to its indexed documents with an overloaded operator[]: e.g., idx[3] would return the fourth document in the index, as an object of class document.
 */

#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include "Document.h"
#include "Tokenizer.h"
#include "Stopword.h"
#include "QueryResult.h"

class Indexer {

    friend std::ostream &operator<<(std::ostream &, const Indexer &);

    /**
     * A new document can be read into the index through an overloaded extractor (operator>>)
     * @return
     */
    friend void operator>>(const Document &, Indexer &);

public:
    /**
     * word dictionary
     */
    Dictionary dic;
    /**
     * default constructor, which creates an empty index
     */
    Indexer();

    /**
     * @return the number of documents in the index
     */
    const long getSize() const;

    /**
     * computes the tf-idf weights based on the number N of indexed documents
     */
    void normalize();

    /**
     * Calculate word frequency
     * @param w word
     * @return wf
     */
    const double docFre(const std::string &w) const;

    /**
     * Calculate word weight
     * @param w word
     * @param d document
     * @return word weight
     */
    const double weight(const std::string &w, const Document &d) const;

    /**
     * query the index with the provided string.
     * By default, it returns the top-10 results, but this can be overridden on a per-query basis (optional second argument).
     * If the index has not been normalized, attempting to query it will throw an exception (adding a new document after normalization also results in a non-normalized index).
     * The query() function returns a vector<query result>, where each result object has a document and its score.
     * @return
     */
    const std::vector<QueryResult> query(const std::string, const int= 10);

    /**
     * provides access to its indexed documents with an overloaded operator[]: e.g., idx[3] would return the fourth document in the index, as an object of class document.
     * @return
     */
    const Document &operator[](unsigned long) const;

private:
    unsigned long size;
    std::vector<Document> documentList;

    std::map<const std::string, std::multimap<const double, const Document>> tf_idf_map;

    const double query_weight(const std::string &w, std::vector<std::string> queries) const ;

    const std::multimap<const double, const Document, std::greater<double>> score(const std::vector<std::string> queries) const ;

};

#endif //INDEXER_H
