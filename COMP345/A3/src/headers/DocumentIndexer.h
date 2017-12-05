#ifndef DOCUMENT_INDEXER_h
#define DOCUMENT_INDEXER_h

#include "Indexer.h"

class DocumentIndexer : public Indexer {

    friend std::ostream &operator<<(std::ostream &, const DocumentIndexer &);

public:
    /**
     * Default constructor
     */
    DocumentIndexer();

    /**
     * Default destructor
     */
    ~DocumentIndexer();
};

#endif