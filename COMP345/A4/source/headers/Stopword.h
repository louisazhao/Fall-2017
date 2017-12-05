/*
//  Stopword.h
//  COMP345A2

 An object of this class can be used for stopword filtering.
    The default constructor creates an object with an empty stopword list (i.e., no filtering).
    A constructor with a file name reads the stopword list from this file.

    To check if a given token exists in a stopword object, overload operator() to return true if the token is in the object’s list, otherwise false.

//
//  Created by Zhao Rui on 2017-10-07.
//  Copyright © 2017 Zhao Rui. All rights reserved.
*/

#ifndef Stopword_h
#define Stopword_h

#include <string>
#include <iostream>
#include <vector>

/**
* the words not to be showing in the output
*/
class Stopword {
    friend std::ostream &operator<<(std::ostream &, const Stopword &);

public:
    /**
     * Default constructor
     */
    Stopword();

    /**
     * Constructor accepts a string
     */
    Stopword(const std::string &file);

    /**
     * Overload ()
     * @return
     */
    bool operator()(const std::string &);

    /**
     * Get stop words
     * @return
     */
    const std::vector<std::string> &getStopWords() const;

private:
    std::vector<std::string> stopwordVector;
};

#endif /* Stopword_h */
