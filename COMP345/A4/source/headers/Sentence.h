#ifndef SENTENCE_h
#define SENTENCE_h

#include "IndexItem.h"

class Sentence: public IndexItem{
    friend std::ostream &operator<<(std::ostream &, const Sentence &);

public:
    /**
     * Default constructor
     */
    Sentence();

    /**
     * Constructor accepts a string
     * @param str
     */
    Sentence(const std::string &name);

    /**
     * Get document size
     * @return the size of document
     */
    const std::size_t getSize() const override final;

    /**
     * Get the position of the sentence in the document
     * @return
     */
    const std::size_t getPos(const std::string&) const;

private:
    /**
     * The start position of the sentence within its document
     */
    std::size_t pos;
};
#endif
