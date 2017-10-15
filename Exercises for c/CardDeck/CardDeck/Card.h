//
//  Card.h
//  CardDeck
//  Exercise 9.23 Chapter 9
//  Created by Zhao Rui on 2017-08-26.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//
#include <string>
#include <array>


#ifndef Card_h
#define Card_h

enum class Suits{Spades=1, Hearts, Diamonds, Clubs};
enum class Faces{Ace=1, Deuce=2, Three=3, Four=4, Five=5, Six=6, Seven=7, Eight=8, Nine=9, Ten=10, Jack=11, Queen=12, King=13};
const std::array<Suits, 4> v_suit{Suits::Spades, Suits::Hearts, Suits::Diamonds, Suits::Clubs};
const std::array<Faces, 13> v_face{Faces::Ace, Faces::Deuce, Faces::Three, Faces::Four,Faces::Five,Faces::Six,Faces::Seven,Faces::Eight,Faces::Nine,Faces::Ten,Faces::Jack,Faces::Queen,Faces::King};

class Card{
public:
    Card(Suits=Suits::Spades, Faces=Faces::Ace);
    std::string toString() const;

private:
    Suits suit;
    Faces face;
    static std::array<std::string, 4> nameOfSuits;
    static std::array<std::string, 13> nameOfFaces;
};



#endif /* Card_h */
