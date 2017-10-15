//
//  main.cpp
//  parkingfee
//
//  Created by Zhao Rui on 2017-08-14.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double calculateCharges(double);


int main() {
    double hour1{1.5},hour2{4.0},hour3{24.0},totalHours{0},total{0};
    
    cout<<fixed<<setprecision(2);
    
    cout<<"Car"<<setw(13)<<"Hours"<<setw(15)<<"Charge"<<endl;
    cout<<"1"<<setw(15)<<hour1<<setw(15)<<calculateCharges(hour1)<<endl;
    cout<<"2"<<setw(15)<<hour2<<setw(15)<<calculateCharges(hour2)<<endl;
    cout<<"3"<<setw(15)<<hour3<<setw(15)<<calculateCharges(hour3)<<endl;
    
    totalHours=hour1+hour2+hour3;
    total=calculateCharges(hour1)+calculateCharges(hour2)+calculateCharges(hour3);
    cout<<"Total"<<setw(11)<<totalHours<<setw(15)<<total<<endl;
    return 0;
}

double calculateCharges(double hour)
{
    if(hour<=3)
        return 20.0;
    else if(hour>3&&hour<24)
        return 20.0+5.0*ceil(hour-3);
    else
        return 50.0;
}
