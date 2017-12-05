#ifndef Document_h
#define Document_h

#include <string>
#include <iostream>
#include "AbstractTokenizer.h"
#include "IndexItem.h"

/*!
 * A document object d represents one document in your index.\
 * It provides
 *      a default constructor,which creates an empty document,
 *      a constructor that accepts a file name and reads the file contents into the document object.
 * Each document provides the functions
 *      name() (returns the file name of the document),
 *      size() (size in characters),
 *      content() (returns the text of the document).
 */
class Document : public IndexItem {
    friend std::ostream &operator<<(std::ostream &, const Document &);

public:
    /**
     * Default constructor
     */
    Document();

    /**
     * Constructor accepts a file name and reads the file contents into the document object
     * @param fileName
     */
    Document(const std::string &fileName);

    /**
     * Tokenizer a file by giving file name and its content
     * @param fileName
     * @param content
     */
    const void tokenizeByContent(const std::string& fileName, const std::string& content);
    /**
     * Get document size
     * @return the size of document
     */
    const std::size_t getSize() const override final;

    /**
     * Get the content of document
     * @return the content of document
     */

private:

};


#endif /* Document_h */
