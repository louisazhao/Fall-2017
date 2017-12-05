//
//  Sentence_tokenizer.h
//  COMP345A3
//
//  Created by Zhao Rui on 2017-10-26.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Sentence_tokenizer_h
#define Sentence_tokenizer_h

#include "AbstractTokenizer.h"
#include <string>
#include <iostream>
#include <vector>

class SentenceTokenizer : public AbstractTokenizer {
    friend std::ostream &operator<<(std::ostream &, const SentenceTokenizer &);

public:
    /**
     * Default constructor
     */
    SentenceTokenizer();

    /**
     * Tokenizer a file by accepting a file name
     */
    SentenceTokenizer(const std::string &inputString);

    /**
     * Default destructor
     */
    virtual ~SentenceTokenizer() {};

private:
    /**
     * Special case for some abbreviations
     * @return
     */
    bool isSpecialCase(const std::string &) const;

    /**
     * left trim a string
     * @param s
     */
    static void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
        }));
    }

    /**
     * right trim a string
     * @param s
     */
    static void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    /**
     * trim a string from both sides
     * @param s
     */
    static void trim(std::string &s) {
        ltrim(s);
        rtrim(s);
    }
};


#endif /* Sentence_tokenizer_h */
