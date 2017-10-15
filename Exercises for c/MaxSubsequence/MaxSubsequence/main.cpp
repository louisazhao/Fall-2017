//
//  main.cpp
//  MaxSubsequence
//
//  Created by Zhao Rui on 2017-09-21.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream inputFile("numbers.txt");
    if(!inputFile)
    {
        cerr<<"Cannot open file."<<endl;
        exit(EXIT_FAILURE);
    }
    
    int number;
    vector<int> numbers;
    while(inputFile>>number)
    {
        numbers.push_back(number);
    }
    inputFile.close();
    
    int maxSoFar=0;
    int maxEndingHere=0;
    int start=0;
    int end=0;
    for(size_t i=0;i!=numbers.size();i++)
    {
        maxEndingHere=max(maxEndingHere+numbers[i],0);
        if(maxEndingHere==0)
        {
            start=start=static_cast<int>(i)+1;
        }
        if(maxEndingHere>maxSoFar)
        {
            end=static_cast<int>(i);
        }
        maxSoFar=max(maxSoFar,maxEndingHere);
        
    }
    cout<<"The sum of the maximum subsequence is "<<maxSoFar<<endl;
    cout<<"The maximum subsequence is  ";
    for(size_t i=start;i<=end;i++)
    {cout<<numbers[i]<<" ";}
    cout<<endl;
}
