#ifndef INDEX_ITEM_h
#define INDEX_ITEM_h

#include <string>
#include <map>
#include "AbstractTokenizer.h"


class IndexItem {

    friend std::ostream &operator<<(std::ostream &, const IndexItem &);

public:
    /**
     * Default constructor
     */
    IndexItem();

    /**
     * Destructor
     */
    virtual ~IndexItem();

    /**
     * Get file name
     * @return the value of file name
     */
    const std::string getFileName() const;

    /**
     * Get the dictionary map
     * @return
     */
    const std::map<const std::string, unsigned long> getDictionary() const;

    /**
     * Get the size of this file
     * @return the size in characters of this file
     */
    virtual const std::size_t getSize() const;

    /**
     * Get the content of this file
     * @return the content of this file
     */
    const std::string getContent() const;

    /**
     * Get tokens
     * @return
     */
    const std::vector<std::string> getTokens() const;

protected:
    std::string fileName;
    std::size_t size;
    std::string content;

    /**
     * words in the indexItem
     */
    std::vector<std::string> tokens;

    /**
     * word and word count in the indexItem
     */
    std::map<const std::string, unsigned long> dictionary;
};

#endif // INDEX_ITEM
