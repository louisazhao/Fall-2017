//
//  CommissionEmployee.h
//  Chapter11
//
//  Created by Zhao Rui on 2017-08-29.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef CommissionEmployee_h
#define CommissionEmployee_h

#include <string>
#include "Employee.h"

class CommissionEmployee : public Employee{
public:
    CommissionEmployee(const std::string&, const std::string&, const std::string&, double=0.0, double=0.0);
    virtual ~CommissionEmployee()=default;
    virtual double earning()const override;
    virtual std::string toString() const override;
    
    
    double getGrossSales() const;
    void setGrossSales(double);
    double getCommissionRate() const;
    void setCommissionRate(double);
    
private:
    double grossSales;
    double commissionRate;
};


#endif /* CommissionEmployee_h */
