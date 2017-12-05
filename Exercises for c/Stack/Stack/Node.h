//
//  Node.h
//  Stack
//
//  Created by Zhao Rui on 2017-12-04.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Node_h
#define Node_h

template<typename T> class Stack;//forward declarition

template <typename T>
class Node {
private:
    T value;
    Node* next;
    
public:
    Node(T value, Node*next)
    :value(value),next(next){}
friend class Stack<T>;
    
};

#endif /* Node_h */
