//
//  BasePlusCommissionEmployee.cpp
//  Chapter11
//
//  Created by Zhao Rui on 2017-08-29.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "BasePlusCommissionEmployee.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& firstName, const string& lastName, const string& ssn, double sales, double rate, double salary)
:CommissionEmployee(firstName,lastName,ssn,sales,rate){
    setBaseSalary(salary);
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

void BasePlusCommissionEmployee::setBaseSalary(double newSalary)
{
    if(newSalary<0.0)
        throw invalid_argument("Base salary must be >0.0");
    baseSalary=newSalary;
}

double BasePlusCommissionEmployee::earning()const
{
    return baseSalary+CommissionEmployee::earning();
}

string BasePlusCommissionEmployee::toString() const
{
    ostringstream output;
    output<<fixed<<setprecision(2);
    output<<"Base-salaried "<<CommissionEmployee::toString()<<"\nbase salary: "<<baseSalary;
    return output.str();
}
