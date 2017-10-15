//
//  BasePlusCommissionEmployee.h
//  Chapter11
//
//  Created by Zhao Rui on 2017-08-29.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef BasePlusCommissionEmployee_h
#define BasePlusCommissionEmployee_h
#include "CommissionEmployee.h"
#include <string>

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string&,const std::string&,const std::string&,double=0.0,double=0.0,double=0.0);
    virtual ~BasePlusCommissionEmployee()=default;
    
    double getBaseSalary() const;
    void setBaseSalary(double);
    
    virtual double earning() const override;
    virtual std::string toString() const override;
private:
    double baseSalary;
};




#endif /* BasePlusCommissionEmployee_h */
