//
//  DollarAmount.h
//  DollarAmount
//
//  Created by Zhao Rui on 2017-07-15.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef DollarAmount_h
#define DollarAmount_h
#include <string>
#include <cmath>

class DollarAmount{
    
public:
    explicit DollarAmount(int64_t number)
    : balance{number}{}
    
    void add(DollarAmount another)
    {
        this.balance+=another.balance;
    }
    
    void subtract(DollarAmount another)
    {
        this.balance-=another.balance;
    }
    
    void addInterest(int rate, int divisor)
    {
        DollarAmount interest{
            (balance*rate+divisor/2)/divisor
        };
        
        add(interest);
    }
    
    std::string toString() const
    {
        std::string dollards{std::to_string(balance/100)};
        std::string cents{std::to_string(std::abs(balance%100))};
        return dollards+"."+(cents.size()==1?"0":"")+cents;
    }
    
private:
    int64_t balance{0};
};




#endif /* DollarAmount_h */
