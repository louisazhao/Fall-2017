//
//  main.cpp
//  CardDeck
//
//  Created by Zhao Rui on 2017-08-26.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include "Card.h"
#include "DeckOfCards.h"
using namespace std;

int main() {
//    Card card1{Suits::Spades, Faces::Ace};
//    cout<<card1.toString()<<endl;
    
    DeckOfCards newDeck;
    newDeck.displayDeck();
    newDeck.shuffle();
    cout<<"\n\n";
    newDeck.displayDeck();
    for(int i=0;i<53;i++)
    {
        newDeck.dealCard();
    }
}
