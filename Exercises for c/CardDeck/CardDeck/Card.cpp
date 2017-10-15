//
//  Card.cpp
//  CardDeck
//
//  Created by Zhao Rui on 2017-08-26.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "Card.h"
#include <string>
#include <array>
#include <iostream>
using namespace std;

 array<string, 4> Card::nameOfSuits{"Spades","Hearts","Diamonds","Clubs"};
 array<string, 13> Card::nameOfFaces{"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};



Card::Card(Suits suitValue, Faces faceValue)
:suit(suitValue), face(faceValue){}

string Card::toString() const
{
    string encodeOfFace{""};
    switch (this->face) {
        case Faces::Ace:
            encodeOfFace+=nameOfFaces[0];
            break;
        case Faces::Deuce:
            encodeOfFace+=nameOfFaces[1];
            break;
        case Faces::Three:
            encodeOfFace+=nameOfFaces[2];
            break;
        case Faces::Four:
            encodeOfFace+=nameOfFaces[3];
            break;
        case Faces::Five:
            encodeOfFace+=nameOfFaces[4];
            break;
        case Faces::Six:
            encodeOfFace+=nameOfFaces[5];
            break;
        case Faces::Seven:
            encodeOfFace+=nameOfFaces[6];
            break;
        case Faces::Eight:
            encodeOfFace+=nameOfFaces[7];
            break;
        case Faces::Nine:
            encodeOfFace+=nameOfFaces[8];
            break;
        case Faces::Ten:
            encodeOfFace+=nameOfFaces[9];
            break;
        case Faces::Jack:
            encodeOfFace+=nameOfFaces[10];
            break;
        case Faces::Queen:
            encodeOfFace+=nameOfFaces[11];
            break;
        case Faces::King:
            encodeOfFace+=nameOfFaces[12];
            break;
    }
    string encodeOfSuit{""};
    switch (this->suit) {
        case Suits::Spades:
            encodeOfSuit+=nameOfSuits[0];
            break;
        case Suits::Hearts:
            encodeOfSuit+=nameOfSuits[1];
            break;
        case Suits::Diamonds:
            encodeOfSuit+=nameOfSuits[2];
            break;
        case Suits::Clubs:
            encodeOfSuit+=nameOfSuits[3];
            break;
    }
    return encodeOfFace+" of "+encodeOfSuit;

}
