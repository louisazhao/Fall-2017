//
//  DeckOfCards.h
//  CardDeck
//
//  Created by Zhao Rui on 2017-08-26.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//
#include "Card.h"
#include <array>


#ifndef DeckOfCards_h
#define DeckOfCards_h

class DeckOfCards{
public:
    static const int NumberOfCards{52};
    explicit DeckOfCards();
    void shuffle();
    const Card& dealCard();
    bool moreCards() const;
    void displayDeck();
    
private:
    std::array<Card, NumberOfCards> deck;
    int currentCard{0};
    void fillDeck();
};


#endif /* DeckOfCards_h */
