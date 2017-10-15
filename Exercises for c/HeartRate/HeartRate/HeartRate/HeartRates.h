//
//  HeartRates.h
//  HeartRate
//
//  Created by Zhao Rui on 2017-07-07.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef HeartRates_h
#define HeartRates_h
#include <string>
#include "Date.h"

class HeartRate{
public:
    HeartRate(std::string fn, std::string ln, Date dateOfBirth)
    : firstName{fn}, lastName{ln}, birthday{dateOfBirth}{}
    
    void setFirstName(std::string newName)
    {
        firstName=newName;
    }
    
    std::string getFirstName() const
    {
        return firstName;
    }
    
    void setLastName(std::string newName)
    {
        lastName=newName;
    }
    
    std::string getLastName() const
    {
        return lastName;
    }

    void setBirthday(int day, int month, int year)
    {
        birthday.setDay(day,month,year);
    }
    
    void getBirthday()
    {
        std::cout<<"The birthday is "<<birthday.getDate()<<" "<<birthday.getMonth()<<" ,"<<birthday.getYear()<<".\n";
    }
    
    int getAge() const
    {
        int age=2015-birthday.getYear();
        return age;
    }
    
    int maxRate()
    {
        int age=getAge();
        return 220-age;
    }
    
    void targetRate()
    {
        int lowLimit=maxRate()*0.5;
        int upperLimit=maxRate()*0.8;
        std::cout<<"Your target heart rate is between "<<lowLimit<<" and "<<upperLimit<<".\n";
    }
    
    
private:
    std::string firstName;
    std::string lastName;
    Date birthday;
    int currentYear=2015;
};


#endif /* HeartRates_h */
