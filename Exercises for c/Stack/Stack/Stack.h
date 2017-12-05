//
//  Stack.h
//  Stack
//
//  Created by Zhao Rui on 2017-12-04.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "Node.h"
#include <iostream>


template <typename T>
class Stack {
public:
    Stack():top(0){}
    void push(T value)
    {
        top=new Node<T>(value,top);
    }
    
    T pop()
    {
        if(top==nullptr)
        {
            std::cout<<"Nothing to pop, the stack is empty";
            return 0;
        }
        else
        {
            T result=top->value;
            top=top->next;
            return result;
        }
    }
    
    
private:
    Node<T>* top;
};




#endif /* Stack_h */
