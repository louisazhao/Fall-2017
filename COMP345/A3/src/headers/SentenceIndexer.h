#ifndef SENTENCE_INDEXER_h
#define SENTENCE_INDEXER_h

#include "Indexer.h"
class SentenceIndexer : public Indexer{

    friend std::ostream &operator<<(std::ostream &, const SentenceIndexer &);

public:

    /**
     * Default constructor
     */
    SentenceIndexer();

    /**
     * Default destructor
     */
    ~SentenceIndexer(){};

    /**
     * Query by giving string
     * @return
     */
    virtual const std::vector <QueryResult> query(const std::string, const unsigned int=500) override ;

    /**
     * Get the indexItem at given position
     * @return
     */
    virtual const IndexItem* operator[](unsigned long) const override ;

};
#endif
