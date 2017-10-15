//
//  SalariedEmployee.cpp
//  Chapter11
//
//  Created by Zhao Rui on 2017-08-31.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "SalariedEmployee.h"
#include <sstream>
#include <stdexcept>
using namespace std;

SalariedEmployee::SalariedEmployee(const string& fn, const string& ln, const string& ssn, double salary)
:Employee(fn,ln,ssn){
    setWeeklySalary(salary);
}

double SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary;
}

void SalariedEmployee::setWeeklySalary(double newSalary)
{
    if(newSalary<0.0)
        throw invalid_argument("Weekly salary must be >0.0");
    weeklySalary=newSalary;
}

double SalariedEmployee::earning() const
{
    return getWeeklySalary();
}

string SalariedEmployee::toString() const
{
    ostringstream output;
    output<<"salaried employee: "<<Employee::toString()<<"\nweekly salary: "<<getWeeklySalary();
    return output.str();
}
