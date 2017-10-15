//
//  CommissionEmployee.cpp
//  Chapter11
//
//  Created by Zhao Rui on 2017-08-29.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "CommissionEmployee.h"
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "Employee.h"
using namespace std;

CommissionEmployee::CommissionEmployee(const std::string& firstName, const std::string& lastName, const std::string& socialSecurityNumber, double sales, double rate)
:Employee::Employee(firstName,lastName,socialSecurityNumber){
    setGrossSales(sales);
    setCommissionRate(rate);
}


double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}

void CommissionEmployee::setGrossSales(double newSale)
{
    if(newSale<0.0)
        throw invalid_argument("Gross sales must be >=0.0");
    else
        grossSales=newSale;
}

double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}

void CommissionEmployee::setCommissionRate(double newRate)
{
    if(newRate<=0.0||newRate>=1.0)
        throw invalid_argument("Commission rate must be >0.0 and <1.0");
    else
        commissionRate=newRate;
}

double CommissionEmployee::earning() const
{
    return getGrossSales()*getCommissionRate();
}

string CommissionEmployee::toString() const
{
    ostringstream output;
    output<<fixed<<setprecision(2);
    output<<"commission employee: "<<Employee::toString()<<"\ngross sales: "<<getGrossSales()<<"\ncommission rate: "<<getCommissionRate();
    return output.str();
}

