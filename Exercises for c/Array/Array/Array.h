//
//  Array.h
//  Array
//
//  Created by Zhao Rui on 2017-08-28.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <iostream>

class Array{
    friend std::ostream& operator <<(std::ostream&, const Array&);
    friend std::istream& operator >>(std::istream&, Array&);
public:
    explicit Array(int=10); //default constructor
    Array(const Array&); //copy constructor
    ~Array(); //destructor
    
    size_t getSize() const;
    
    const Array& operator =(const Array&); //overload assignment operator

    bool operator !=(const Array&) const;
    bool operator ==(const Array&) const;
    
    int& operator[](int);//subscript operator for non-const object returns lvalue
    int operator[](int) const;//subscript operator for const object returns rvalue
    
    
    
private:
    size_t size;
    int* ptr;
    
};




#endif /* Array_h */
