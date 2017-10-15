//
//  SalariedEmployee.h
//  Chapter11
//
//  Created by Zhao Rui on 2017-08-31.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef SalariedEmployee_h
#define SalariedEmployee_h

#include <string>
#include "Employee.h"

class SalariedEmployee : public Employee{
public:
    SalariedEmployee(const std::string&, const std::string&, const std::string&, double=0.0);
    virtual ~SalariedEmployee()=default;
    
    double getWeeklySalary() const;
    void setWeeklySalary(double);
    
    virtual double earning() const override;
    virtual std::string toString() const override;
    
private:
    double weeklySalary;
};


#endif /* SalariedEmployee_h */
