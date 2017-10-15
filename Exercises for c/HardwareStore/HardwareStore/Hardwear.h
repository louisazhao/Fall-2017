//
//  Hardwear.h
//  HardwareStore
//
//  Created by Zhao Rui on 2017-09-03.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Hardwear_h
#define Hardwear_h

#include <string>
#include <iostream>

class Hardwear{
public:
    Hardwear(int=0, const std::string& ="", int=0,double=0.0);
    int getIdNumber() const;
    void setIdNumber(int);
    
    std::string getName() const;
    void setName(const std::string&);
    
    int getQuantity() const;
    void setQuantity(int);
    
    double getCost() const;
    void setCost(double);

private:
    int idNumber;
    std::string name;
    int quantity;
    double cost;
};


#endif /* Hardwear_h */
