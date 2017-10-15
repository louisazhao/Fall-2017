//
//  Employee.cpp
//  Chapter11
//
//  Created by Zhao Rui on 2017-08-31.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "Employee.h"
#include <sstream>
using namespace std;

Employee::Employee(const string& firstName, const string& lastName, const string& ssn)
:firstName(firstName),lastName(lastName),socialSecurityNumber(ssn){}

string Employee::getFirstName() const
{
    return firstName;
}

void Employee::setFirstName(const string& newName)
{
    firstName=newName;
}

string Employee::getLastName() const
{
    return lastName;
}

void Employee::setLastName(const string& newName)
{
    lastName=newName;
}

string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void Employee::setSocialSecurityNumber(const string& ssn)
{
    socialSecurityNumber=ssn;
}

string Employee::toString() const
{
    ostringstream output;
    output<<getFirstName()<<" "<<getLastName()<<"\nsocial security number: "<<getSocialSecurityNumber();
    return output.str();
}

