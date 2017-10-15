//
//  Array.cpp
//  Array
//
//  Created by Zhao Rui on 2017-08-28.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "Array.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

Array::Array(int arraySize)
:size{(arraySize>0?static_cast<size_t>(arraySize):throw invalid_argument{"Array size must be greater than 0"})},
ptr{new int[size]{}}{/* empty body */}

//copy constructor
Array::Array(const Array& arrayToCopy)
:size{arrayToCopy.size},ptr{new int[size]}
{
    for(size_t i=0;i<size;i++)
        ptr[i]=arrayToCopy.ptr[i];
}

//destructor
Array::~Array()
{
    delete[] ptr;
}

size_t Array::getSize() const
{
    return this->size;
}

const Array& Array::operator=(const Array& arrayToAssign)
{
    if(&arrayToAssign!=this) //this is a pointer(address), should be compared with an address to ensure the right object is not the same one(compare their address)
    {
        if(size!=arrayToAssign.size)
        {
            delete[] ptr;
            size=arrayToAssign.size;
            ptr=new int[size];
        }
    
        for(size_t i=0;i<size;i++)
        {
            ptr[i]=arrayToAssign.ptr[i];
        }
    }
    return *this; //(*this) is the object pointed by this pointer, return this object by constant reference(const array&)
}

bool Array::operator ==(const Array& arrayToCompare) const
{
    if(size!=arrayToCompare.size)
    {
        return false;
    }
    for(size_t i=0;i<size;i++)
    {
        if(ptr[i]!=arrayToCompare.ptr[i])
            return false;
    }
    return true;
}
bool Array::operator !=(const Array& arrayToCompare) const
{
    return !(*this==arrayToCompare); //*this is the object pointed by this pointer, should be compared with an object, which is passed by reference in the parameter
}

int& Array::operator[](int index)//subscript operator for non-const object returns lvalue
{
    if(index<0||index>=size)
        throw out_of_range{"Subscript out of range!"};
    return ptr[index]; //value is returned by reference, which allows the value to be modified with assignment operator
}

int Array::operator[](int index) const
{
    if(index<0||index>=size)
        throw out_of_range{"Subscript out of range!"};
    return ptr[index];
}

istream& operator>>(istream& input, Array& array)
{
    for(size_t i=0; i<array.size;i++)
    {
        input>>array.ptr[i];
    }
    return input;
}

ostream& operator<<(ostream& output, const Array& array)
{
    for(size_t i=0;i<array.size;i++)
    {
        output<<array.ptr[i]<<"  ";
    }
    output<<endl;
    return output;
}



