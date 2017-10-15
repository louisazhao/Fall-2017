//
//  main.cpp
//  HeartRate
//
//  Created by Zhao Rui on 2017-07-07.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include "HeartRates.h"
#include "Date.h"


using namespace std;


int main() {
    cout<<"Welcome to the heart rate calculator.\n";
    cout<<"Please enter you first name.\n";
    string firstName;
    cin>>firstName;
    cout<<"Please enter you last name.\n";
    string lastName;
    cin>>lastName;
    cout<<"Please enter the date when you are born.\n";
    int day;
    cin>>day;
    cout<<"Please enter the month when you are born.\n";
    int month;
    cin>>month;
    cout<<"Please enter the year when you are born.\n";
    int year;
    cin>>year;
    
    Date newDate(day,month,year);
    HeartRate client1(firstName,lastName,newDate);
    
    
    cout<<"According to your data,\n";
    cout<<"Your maximum heart rate is "<<client1.maxRate()<<".\n";
    client1.targetRate();
    
    
    
    
    return 0;
}
