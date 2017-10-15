//
//  main.cpp
//  Array
//
//  Created by Zhao Rui on 2017-08-28.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include "Array.h"
#include <stdexcept>

using namespace std;

int main() {
    Array array1{7};
    Array array2{};
    
    cout<<array1.getSize()<<endl;
    cout<<array1;
    cout<<array2.getSize()<<endl;
    cout<<array2;
    
    cout<<"Enter 17 integers:"<<endl;
    cin>>array1>>array2;
    
    cout<<array1<<array2;
    
    cout<<(array1!=array2)<<endl;
    
    Array array3{array1};
    
    cout<<array3.getSize()<<endl;
    cout<<array3;
    
    cout<<(array1==array3)<<endl;
    
    array1=array2;
    cout<<array1;
    
    cout<<array1[3]<<endl;
    
    try{array1[15]=1000;
    }
    catch(out_of_range& ex)
    {
        cout<<ex.what()<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    
}
