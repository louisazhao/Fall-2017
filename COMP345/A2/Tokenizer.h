//
//  Tokenizer.h
//  COMP345A2
//
//  Created by Zhao Rui on 2017-10-07.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Tokenizer_h
#define Tokenizer_h

#include <string>
#include <iostream>
#include <vector>

/**
* an util class for spliting input string.
*/
class Tokenizer{
    friend std::ostream& operator<<(std::ostream&, const Tokenizer&);

public:
    /**
     * Default constructor
     */
    Tokenizer();
    /**
     * Constructor accepts a string
     */
    Tokenizer(const std::string& inputString);
    /**
     * Get tokens
     * @return a vector of tokens
     */
    const std::vector<std::string>& getTokens() const;


private:
    std::vector<std::string> tokens;
    inline bool isDelimiter(char c)
    {
        const std::vector<char> delim={',','.','!','?','\"','\'','(',')',':',';'}; //delimiter list
        for(size_t i=0;i<delim.size();i++)
        {
            if(c==delim[i])
                return true;
        }
        return false;
    }
};


#endif /* Tokenizer_h */
