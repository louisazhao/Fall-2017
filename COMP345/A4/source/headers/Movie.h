#ifndef MOVIE_h
#define MOVIE_h

#include "IndexItem.h"

class Movie: public IndexItem
{
    friend std::ostream &operator<<(std::ostream &, const Movie &);

public:
    /**
     * Default constructor
     */
    Movie();

    /**
     * Full parameters constructor
     * @param str
     */
    Movie(const unsigned id, std::string name, std::string releaseDate);

    /**
    * Default destructor
    */
    ~Movie();
    /**
     * Get document size
     * @return the size of document
     */
    const std::size_t getSize() const override final;

    const unsigned long getId() const;

    const std::string getName() const;

    const std::string getContent() const;

    void setContent(std::string content);

    const std::string getReleaseDate() const;


private:
    const unsigned long id;
    const std::string name;
    const std::string releaseDate; // may change to date type
    /**
    * holds a movie's plot description
    */
    std::string content;

};
#endif

