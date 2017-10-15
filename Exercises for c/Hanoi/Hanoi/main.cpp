//
//  main.cpp
//  Hanoi
//
//  Created by Zhao Rui on 2017-08-14.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
using namespace std;

void moves(int, int, int, int);

int main() {
    moves(4, 1, 3, 2);
   
}

void moves(int numberToMove,int moveFrom, int moveTo, int temporary)
{
    
    if(numberToMove==1)
        cout<<moveFrom<<" to "<<moveTo<<endl;
        
    else
    {
        moves(numberToMove-1, moveFrom, temporary, moveTo);
        cout<<moveFrom<<" to "<<moveTo<<endl;
        moves(numberToMove-1, temporary, moveTo, moveFrom);
    }
        
    
}
