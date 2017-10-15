//
//  main.cpp
//  Chap4-2
//
//  Created by Zhao Rui on 2017-07-12.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    unsigned int count=1;
    unsigned int passed=0;
    unsigned int failed=0;
    
    while(count<=10)
    {
        cout<<"Please enter the grade for this student, 1 for passed and 2 for faild\n";
        int grade;
        cin>>grade;
        count++;
        if(grade==1)
        {
            passed++;
        }
        else
        {
            failed++;
        }
    }
    
    cout<<"The number of student who passed the exam is "<<passed<<"\n";
    cout<<"The number of student who failed the exam is "<<failed<<"\n";
    
    if(passed>8)
    {
        cout<<"Bonus to instructor!\n"<<endl;
    }
    return 0;
}
