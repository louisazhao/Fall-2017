
/**
 * A document object d represents one document in your index.
 It provides
    a default constructor,which creates an empty document,
    a constructor that accepts a file name and reads the file contents into the document object.
 Each document provides the functions
    name() (returns the file name of the document),
    size() (size in characters),
    content() (returns the text of the document).


 *  Created by Zhao Rui on 2017-10-07
 *  Copyright © 2017 Zhao Rui. All rights reserved.
 *
 */


#ifndef Document_h
#define Document_h

#include <string>
#include <iostream>
#include "Tokenizer.h"
#include "Dictionary.h"

class Document {
    friend std::ostream &operator<<(std::ostream &, const Document &);

public:
    /**
     * Default constructor
     */
    Document();

    /**
     * Constructor accepts a string
     * @param s
     */
    Document(const std::string & s);

    /**
     * Get file name
     * @return file name
     */
    const std::string getFileName() const;

    /**
     * Get document size
     * @return the size of document
     */
    const unsigned long getSize() const;

    /**
     * Get the content of document
     * @return the content of document
     */
    const std::string getContent() const;

    /**
     * Get tokens of document
     * @return tokens of document
     */
    const std::vector<std::string> &getTokens() const;

    /**
     * Get dictionary
     * @return dictionary
     */
    const Dictionary &getDocDic() const;

private:
    std::string fileName;
    unsigned long size;
    std::string content;
    std::vector<std::string> tokens;
    Tokenizer tokensOfFile;
    Dictionary docDic;

    const Tokenizer &getTokenizer() const;

    void updateDocDic();
};


#endif /* Document_h */
