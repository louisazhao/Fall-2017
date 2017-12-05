#ifndef INDEXER_h
#define INDEXER_h

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include "IndexItem.h"
#include "QueryResult.h"

class Indexer {

    friend std::ostream &operator<<(std::ostream &, const Indexer &);

    /**
     * A new document can be read into the index through an overloaded extractor (operator>>)
     * @return
     */
    friend void operator>>(const IndexItem &, Indexer &);

public:

    /**
     * default constructor, which creates an empty index
     */
    Indexer();

    /**
     * Default destructor
     */
    virtual ~Indexer();

    /**
     * @return the number of documents in the index
     */
    const long getSize() const;

    /**
     * The map storing word and its count
     * @return
     */
    const std::map<const std::string, unsigned long> getDictionary();

    /**
     * computes the tf-idf weights based on the number N of indexed documents
     */
    void normalize();

    /**
     * Calculate document frequency
     * The document frequency df t for a term t is defined as the number of documents that t appears in
     * @param t term
     * @return df
     */
    const double getDocumentFrequency(const std::string &t) const;

    /**
     * Calculate term weight
     * the tf-idf weight of a term t in a document d is defined as the given formula
     * @param t term
     * @param d document
     * @return term weight
     */
    const double getWeight(const std::string &t, const IndexItem &d) const;

    /**
     * query the index with the provided string.
     * By default, it returns the top-10 results, but this can be overridden on a per-query basis (optional second argument).
     * If the index has not been normalized, attempting to query it will throw an exception (adding a new document after normalization also results in a non-normalized index).
     * The query() function returns a vector<query result>, where each result object has a document and its score.
     * @return
     */
    virtual const std::vector<QueryResult> query(const std::string, const unsigned int= 10);

    /**
     * provides access to its indexed documents with an overloaded operator[]: e.g., idx[3] would return the fourth document in the index, as an object of class document.
     * @return
     */
    virtual const IndexItem* operator[](unsigned long) const;

    const unsigned long
    searchDictionary(std::map<const std::string, unsigned long> dicMap, const std::string word) const;

protected:

    unsigned long size;

    std::vector<IndexItem> itemList;

    std::map<const std::string, unsigned long> dictionary;

    std::map<const std::string, std::multimap<const double, const IndexItem>> tf_idf_map;

    const double queryWeight(const std::string &w, std::vector<std::string> queries) const;

    const std::multimap<const double, const IndexItem, std::greater<double>>
    score(const std::vector<std::string> queries) const;

    void mergeDictionary(const std::map<const std::string, unsigned long> &localMap) ;
};

#endif
