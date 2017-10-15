//
//  main.cpp
//  Chp2E19
//
//  Created by Zhao Rui on 2017-06-29.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int x=0;
    int y=0;
    int z=0;
    int sum=0;
    int average=0;
    int product=0;
    int largest=0;
    int smallest=0;
    
    cout <<"Please enter 3 integers: \n";
    cin >> x >> y >> z;
    
    sum= x + y + z;
    average=sum / 3;
    product = x * y * z;
    
    smallest=x;
    if(y<smallest)
        smallest=y;
    if(z<smallest)
        smallest=z;
    
    largest=x;
    if(y>largest)
        largest=y;
    if(z>largest)
        largest=z;
    
    
    cout <<"Sum is " << sum <<"\n";
    cout <<"Average is " << average <<"\n";
    cout <<"Product is " << product <<"\n";
    cout <<"Smallest is " << smallest <<"\n";
    cout <<"Largest is " << largest <<"\n";
    
    return 0;
}
