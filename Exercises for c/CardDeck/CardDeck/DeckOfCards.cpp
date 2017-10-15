//
//  DeckOfCards.cpp
//  CardDeck
//
//  Created by Zhao Rui on 2017-08-26.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "DeckOfCards.h"
#include "Card.h"
#include <array>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


DeckOfCards::DeckOfCards(){
    fillDeck();
}

void DeckOfCards::displayDeck()
{
    for(int i=0;i<deck.size();i++)
    {
        cout<<setw(20)<<deck[i].toString();
        if((i+1)%4==0)
            cout<<endl;
    }
}

void DeckOfCards::shuffle()
{
    for(int i=0;i<NumberOfCards;i++)
    {
        int index=rand()%52;
        Card temp=deck[0];
        deck[0]=deck[index];
        deck[index]=temp;
    }
}

const Card& DeckOfCards::dealCard()
{
    int index=currentCard;
    if(moreCards()==false)
    {cout<<"\nNo more cards in the deck.";}
    
    currentCard++;
    cout<<"\nCard been dealed is "<<deck[index].toString()<<endl;
    return deck[index];

}

bool DeckOfCards::moreCards() const
{
    return (currentCard>=0&&currentCard<NumberOfCards);
}



void DeckOfCards::fillDeck()
{
    int number{0};
    for(int i=0;i<v_face.size();i++)
    {
        for(int j=0;j<v_suit.size();j++)
        {
            deck[number]=Card{v_suit[j],v_face[i]};
            number++;
        }
    }
}
