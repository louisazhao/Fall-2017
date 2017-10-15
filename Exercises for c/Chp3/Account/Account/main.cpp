//
//  main.cpp
//  Account
//
//  Created by Zhao Rui on 2017-07-07.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include "Account.h"

using namespace std;

void displayAccount(Account a)
{
    cout<<"The name of the account is " << a.getName()<<" .Its balance is $" <<a.getBalance()<<".\n";
}

int main(int argc, const char * argv[]) {
    cout<<"Please enter the name for your accout.\n";
    string name1;
    getline(cin,name1);
    cout<<"Please enter the number that you want to deposit when opening the account.\n";
    int amout;
    cin>>amout;
    Account account1(name1,amout);
    displayAccount(account1);
    
    cout<<"Please enter the amount you want to deposit.\n";
    int depositNumber;
    cin>>depositNumber;
    cout<<"Adding $"<<depositNumber<<" dollars to your account.\n";
    account1.deposit(depositNumber);
    displayAccount(account1);
    
    cout<<"Please enter the amout you want to withdraw.\n";
    int withdrawNumber;
    cin>>withdrawNumber;
    cout<<"Withdrawing $"<<withdrawNumber<<" from your account.\n";
    account1.withdraw(withdrawNumber);
    displayAccount(account1);
    cout<<endl;
    
    
    
    
    
    
    
    
    
    
    return 0;
}

