//
//  main.cpp
//  Exponential
//
//  Created by Zhao Rui on 2017-08-14.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
using namespace std;

unsigned int power(unsigned int,unsigned int);


int main() {
    unsigned int base, exp;
    cout<<"Enter the base number: \n";
    cin>>base;
    cout<<"Enter the expentional part: \n";
    cin>>exp;
    cout<<"The Power of "<<base<<" with "<<exp<<" degree is "<<power(base,exp)<<endl;
    
}


unsigned int power(unsigned int base ,unsigned int exp)
{
    if (exp==1)
        return base;
    else
        return base*power(base,exp-1);
}
