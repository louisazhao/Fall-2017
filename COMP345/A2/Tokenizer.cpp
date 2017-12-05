//
//  Tokenizer.cpp
//  COMP345A2
//
//  Created by Zhao Rui on 2017-10-07.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "Tokenizer.h"
#include <sstream>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& output, const Tokenizer& t)
{
    output<<"Tokens are: ";
    for(string elements:t.getTokens())
    {
        output<<elements<<" ";
    }
    return output;
}
Tokenizer::Tokenizer()
{
    tokens=vector<string>();//empty
}

Tokenizer::Tokenizer(const std::string& inputString)
{
    istringstream text(inputString);
    string word;
    while(getline(text, word, ' '))
    {
        if(isDelimiter(word[0]))//if the first character is not an alpha, delete it
            word=word.substr(1,(word.length()-1));
        if(isDelimiter(word[0]))//if the second first is also not an alpha, delete it
            word=word.substr(1,(word.length()-1));
        if(isDelimiter(word[word.length()-1])&&(word[word.length()-1]!='\''))//if the last one is not an alpha and it's not a "'", delete it(for example students')
            word=word.substr(0,(word.length()-1));
        if(isDelimiter(word[word.length()-1])&&(word[word.length()-1]!='\''))//if the second last one is not an alpha and it's not a "'", delete it(for example students'.)
            word=word.substr(0,(word.length()-1));
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        tokens.push_back(word);
    }
}

const std::vector<std::string>& Tokenizer::getTokens() const
{
    return tokens;
}

