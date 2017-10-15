//
//  Account.h
//  Account
//
//  Created by Zhao Rui on 2017-07-07.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Account_h
#define Account_h

#include <string>

class Account{
public:
    Account(std::string accountName, int initialBalance)
    : name{accountName}{
        if(initialBalance>0)
            balance=initialBalance;}
    
    void deposit(int depositAmount)
    {
        if (depositAmount>0)
            balance=balance+depositAmount;
        else
            std::cout<<"Not a legal amount, please enter a number.\n";
    }
    
    void withdraw(int withdrawAmount)
    {
        if(balance>=withdrawAmount)
            balance=balance-withdrawAmount;
        else
            std::cout<<"Withdeawal amount exceeded account balance.\n";
    }
    
    int getBalance() const
    {
        return balance;
    }
    
    std::string getName() const
    {
        return name;
    }
    
    void setName(std::string newName)
    {
        name=newName;
    }
    
private:
    std::string name;
    int balance=0;
};


#endif /* Account_h */

