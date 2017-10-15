//
//  Employee.h
//  Chapter11
//
//  Created by Zhao Rui on 2017-08-31.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Employee_h
#define Employee_h
#include <string>

class Employee{
public:
    Employee(const std::string&, const std::string&, const std::string&);
    virtual ~Employee()=default;
    
    std::string getFirstName() const;
    void setFirstName(const std::string&);
    
    std::string getLastName() const;
    void setLastName(const std::string&);

    std::string getSocialSecurityNumber() const;
    void setSocialSecurityNumber(const std::string&);
    
    virtual double earning() const=0; //pure virtual function
    virtual std::string toString() const;
    
private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;

};


#endif /* Employee_h */
