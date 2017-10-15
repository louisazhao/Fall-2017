//
//  Student.h
//  Student
//
//  Created by Zhao Rui on 2017-07-12.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include<string>

class Student{
public:
    Student(std::string name, int average)
    : name(name){
        setAverage(average);
    }
    
    std::string getName() const
    {
        return name;
    }
    
    void setName(std::string newName)
    {
        name=newName;
    }
    
    int getAverage() const
    {
        return average;
    }
    
    void setAverage(int newAverage)
    {
        if (newAverage>0 && newAverage<=100)
            average=newAverage;
    }
    
    std::string getLetterGrade() const
    {
        std::string letterGrade;
        
        if (average>=90)
        {
            letterGrade="A";
        }
        else if (average>=80)
        {
            letterGrade="B";
        }
        else if (average>=70)
        {
            letterGrade="C";
        }
        else if (average>=60)
        {
            letterGrade="D";
        }
        else
        {
            letterGrade="F";
        }
        return letterGrade;
    }
    
private:
    std::string name;
    int average=0;
};










#endif /* Student_h */
