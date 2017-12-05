//
// Created by ling on 16/10/17.
//

#ifndef COMP345_DICTIONARY_H
#define COMP345_DICTIONARY_H

#include <string>
#include <map>

/**
 * Storing all the word encountered in the index documents, and the times it is encountered.
 */
class Dictionary {
    friend std::ostream& operator<<(std::ostream&, const Dictionary&);

public:
    /**
     * Default constructor
     */
    Dictionary();

    /**
     * Insert a new word to the dictionary.
     * @param word the value of new word
     */
    void insert(const std::string word);

    /**
     * Merge map to dictionary
     * @param localMap the map to be merged
     */
    void merge(const std::map<const std::string, unsigned long> & localMap) ;



    /**
     * Merge two dictionaries
     * @param d the dictionary to be merged
     */
    void merge(const Dictionary & d) ;



    /**
     * Search a word in the dictionary
     * @param word the word to be searched
     * @return the value of how many times this word has been encountered; 0, if no such word.
     */
    const unsigned long search(const std::string word)  const;
    /**
     *
     * Get the size of dictionary
     * @return the size of dictionary
     */
    const unsigned long getSize()  const;
    /**
     *
     * Get the map structure of dictionary
     * @return the map structure of dictionary
     */
    const std::map<const std::string, unsigned long> & getMap() const;

private:
    /**
     * the map data type to store dictionary
     */
    std::map<const std::string, unsigned long> dicMap;
};


#endif //COMP345_DICTIONARY_H
