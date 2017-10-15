//
//  main.cpp
//  Chapter11
//
//  Created by Zhao Rui on 2017-08-29.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std;

void virtualViaPointer(const Employee* const);
void virtualViaReference(const Employee&);//references alias to objects

int main() {
    cout<<fixed<<setprecision(2);
    
    SalariedEmployee e1{"John","Smith","111-11-1111",800};
    CommissionEmployee e2{"Sue","Jones","333-33-3333",10000,0.06};
    BasePlusCommissionEmployee e3{"Bob","Lewis","444-44-4444",5000,0.04,300};
    
    cout<<"static method:\n"
    <<e1.toString()<<"\nearined $"<<e1.earning()<<"\n\n"
    <<e2.toString()<<"\nearined $"<<e2.earning()<<"\n\n"
    <<e3.toString()<<"\nearined $"<<e3.earning()<<"\n\n";
    
    vector<Employee *> employees{&e1,&e2, &e3};
    
    cout<<"dynamic binding:\n";
    
    cout<<"pointers:\n";
    
    for(const Employee* employeeptr:employees)
        virtualViaPointer(employeeptr);
    
    cout<<"references:\n";
    
    for(const Employee* employeeptr:employees)
        virtualViaReference(*employeeptr); //objects
}

void virtualViaPointer(const Employee* const baseClassPtr)
{
    cout<<baseClassPtr->toString()<<"\nearined $"<<baseClassPtr->earning()<<"\n\n";
}
void virtualViaReference(const Employee& baseClaaRef)
{
    cout<<baseClaaRef.toString()<<"\nearined $"<<baseClaaRef.earning()<<"\n\n";
}
