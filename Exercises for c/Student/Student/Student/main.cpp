//
//  main.cpp
//  Student
//
//  Created by Zhao Rui on 2017-07-12.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"
using namespace std;


int main() {
    int total=0;
    unsigned int count=0;
    
    cout<<"Please enter the next grade, if no record, enter -1: \n";
    int nextgrade;
    cin>>nextgrade;
    
    while(nextgrade!=-1)
    {
        total=total+nextgrade;
        count++;
        cout<<"Please enter the next grade, if no record, enter -1: \n";
        cin>>nextgrade;
    }

    
    if(count!=0)
    {
        double average=static_cast<double>(total)/count;
        cout<<setprecision(2)<<fixed;
        cout<<"Average is "<<average<<"\n"<<endl;
    }
    else{
        cout<<"no grade were entered\n"<<endl;
    }
}
