//
//  Movie.cpp
//  COMP345A4
//


#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "../headers/Movie.h"


using namespace std;

ostream &operator<<(ostream &output, const Movie &d)
{
    output << "File name of this movie is " << d.getFileName();
    return output << endl;
}

Movie::Movie():id(0), name(""), releaseDate("") {}

Movie::Movie(const unsigned id, std::string name, std::string releaseDate):id(id), name(name), releaseDate(releaseDate)
{
    fileName = std::to_string(id);
}

Movie::~Movie() {}

const size_t Movie::getSize() const
{
    return size;
}

const unsigned long Movie::getId() const {
    return id;
}

const std::string Movie::getName() const {
    return name;
}

const std::string Movie::getContent() const {
    return content;
}

void Movie::setContent(std::string content){
    Movie::content = content;
}

const std::string Movie::getReleaseDate() const{
    return releaseDate;
}
