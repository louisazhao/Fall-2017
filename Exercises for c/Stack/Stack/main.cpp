//
//  main.cpp
//  Stack
//
//  Created by Zhao Rui on 2017-12-04.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include "Node.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Stack<int> newOne;
    cout<<newOne.pop()<<endl;
    newOne.push(2);
    newOne.push(3);
    cout<<newOne.pop()<<endl;
    
    return 0;
}
