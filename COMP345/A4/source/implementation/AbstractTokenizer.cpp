//
// Created by ling on 07/11/17.
//

#include "../headers/AbstractTokenizer.h"

AbstractTokenizer::AbstractTokenizer() : tokens(std::vector<std::string>()) {

}

AbstractTokenizer::~AbstractTokenizer() {}

const std::vector<std::string> &AbstractTokenizer::getTokens() const {
    return tokens;
}

const size_t AbstractTokenizer::getSize() const { return size; }
