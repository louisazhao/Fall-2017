//
//  Date.h
//  HeartRate
//
//  Created by Zhao Rui on 2017-07-07.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Date_h
#define Date_h

class Date{
public:
    Date(int date, int m, int year)
    :year{year},date{date}
    {
        if (m>=1 && m<=12)
            month=m;
        else
            month=1;
    }
    
    void setDate(int newDay)
    {
        date=newDay;
    }
    
    int getDate() const
    {
        return date;
    }
    
    void setMonth(int newMonth)
    {
        if(newMonth<1||newMonth>12)
            std::cout<<"Invalid number, only from 1 to 12.\n";
        else
            month=newMonth;
    }
    
    int getMonth() const
    {
        return month;
    }
    
    void setYear(int newYear)
    {
        year=newYear;
    }
    
    int getYear() const
    {
        return year;
    }
    
    
    void setDay(int day,int month,int year)
    {
        day=day;
        month=month;
        year=year;
    }
    
    
private:
    int date;
    int month;
    int year;
};

#endif /* Date_h */
