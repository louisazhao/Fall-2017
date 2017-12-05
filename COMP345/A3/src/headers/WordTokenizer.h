//
//  Word_tokenizer.h
//  COMP345A3
//
//  Created by Zhao Rui on 2017-10-26.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Word_tokenizer_h
#define Word_tokenizer_h

#include "AbstractTokenizer.h"
#include <string>
#include <iostream>
#include <vector>

class WordTokenizer : public AbstractTokenizer {
    friend std::ostream &operator<<(std::ostream &, const WordTokenizer &);

public:
    /**
     * Default constructor
     */
    WordTokenizer();

    /**
     * Constructor accepting a file name
     * @param inputString
     */
    WordTokenizer(const std::string &inputString);

    /**
     * Default destructor
     */
    virtual ~WordTokenizer() {};

private:
    /**
     * detect the end of a word
     * @param c
     * @return
     */
    inline bool isDelimiter(char c) const {
        const std::vector<char> delim = {',', '.', '!', '?', '\"', '\'', '(', ')', ':', ';'}; //delimiter list
        for (size_t i = 0; i < delim.size(); i++) {
            if (c == delim[i])
                return true;
        }
        return false;
    }
};


#endif /* Word_tokenizer_h */
