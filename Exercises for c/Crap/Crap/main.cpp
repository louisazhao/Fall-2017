//
//  main.cpp
//  Crap
//
//  Created by Zhao Rui on 2017-07-21.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
unsigned int rollDice();

int main() {
    enum class Status{CONTINUE,WON,LOST};
    
    unsigned int sum{0};
    unsigned int point{0};
    Status gameStatus;
    
    srand(static_cast<unsigned int>(time(0)));
    sum=rollDice();
    
    switch (sum) {
        case 7:
        case 11:
            gameStatus=Status::WON;
            break;
            
        case 2:
        case 3:
        case 12:
            gameStatus=Status::LOST;
            break;
            
        default:
            gameStatus=Status::CONTINUE;
            point=sum;
            cout<<"Point is "<<point<<endl;
            break;
    }
    
    while(gameStatus==Status::CONTINUE)
    {
        sum=rollDice();
        if(sum==7)
        {
            gameStatus=Status::LOST;
        }
        else if (sum==point)
        {
            gameStatus=Status::WON;}
    }
    
    if(gameStatus==Status::WON)
    {
        cout<<"Player wins!\n"<<endl;
    }
    else{
        cout<<"Player lost!\n"<<endl;
    }
}

unsigned int rollDice()
{
     int dice1{1+rand()%6};
     int dice2{1+rand()%6};
    int sum=dice1+dice2;
    cout<<"Player rolled"<<dice1<<" + "<<dice2<<" = "<<sum<<endl;
    return sum;
}
