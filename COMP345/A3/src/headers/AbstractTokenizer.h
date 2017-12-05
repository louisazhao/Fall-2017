//
//  Abstract_tokenizer.h
//  COMP345A3
//
//  Created by Zhao Rui on 2017-10-26.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Abstract_tokenizer_h
#define Abstract_tokenizer_h

#include <string>
#include <iostream>
#include <vector>

class AbstractTokenizer {
    /**
     * output AbstractTokenizer
     * @return
     */
    friend std::ostream &operator<<(std::ostream &, const AbstractTokenizer &);

public:
    /**
     * Default constructor
     */
    AbstractTokenizer();

    /**
     * Default destructor
     */
    virtual ~AbstractTokenizer();

    /**
     * Get tokens
     * @return
     */
    const std::vector<std::string> &getTokens() const; //not virtual because the behaviour is the same

    /**
     * Get the number of tokens
     * @return
     */
    const size_t getSize() const;

protected://has to be protected, because we need to modify the vector in subclasses

    /**
     * token vector
     */
    std::vector<std::string> tokens;

    /**
     * number of tokens
     */
    size_t size;
};


#endif /* Abstract_tokenizer_h */
