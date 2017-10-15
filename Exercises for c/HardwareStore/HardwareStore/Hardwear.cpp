//
//  Hardwear.cpp
//  HardwareStore
//
//  Created by Zhao Rui on 2017-09-03.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "Hardwear.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

Hardwear::Hardwear(int id, const string& name, int quantity, double cost)
:idNumber(id),name(name),quantity(quantity),cost(cost){}

int Hardwear::getIdNumber() const
{
    return idNumber;
}

void Hardwear::setIdNumber(int newID)
{
    idNumber=newID;
}

string Hardwear::getName() const
{
    return name;
}

void Hardwear::setName(const string& newName)
{
    name=newName;
}

int Hardwear::getQuantity() const
{
    return quantity;
}
void Hardwear::setQuantity(int newQuantity)
{
    if(newQuantity<0)
        throw invalid_argument("Quantity cannot be negative");
    quantity=newQuantity;
}

double Hardwear::getCost() const
{
    return cost;
}
void Hardwear::setCost(double newCost)
{
    if(newCost<0.0)
        throw invalid_argument("Cost shoube be greater than 0.0");
    cost=newCost;
}

