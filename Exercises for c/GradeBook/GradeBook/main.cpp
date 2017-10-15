//
//  main.cpp
//  GradeBook
//
//  Created by Zhao Rui on 2017-08-20.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include <array>
#include "GradeBook.h"
using namespace std;

int main() {
    
    array<array<int, GradeBook::tests>, GradeBook::students> grades{};
    
    grades[0]={87,96,70};
    grades[1]={68,87,90};
    grades[2]={94,100,90};
    grades[3]={100,81,82};
    grades[4]={83,65,85};
    grades[5]={78,87,65};
    grades[6]={85,75,83};
    grades[7]={91,94,100};
    grades[8]={76,72,84};
    grades[9]={87,93,73};
    
    
    GradeBook myGradeBook("CS101 Introduction to C++ Programming", grades);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
    
    
}
