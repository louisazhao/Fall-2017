//
//  Task.h
//  COMP345E7
//
//  Created by Zhao Rui on 2017-12-04.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Task_h
#define Task_h
#include <vector>

class Task{
public:
    Task();
    void addPrereq(Task *ptr);
    bool ready() const;
    bool done() const;
    void doIt();
    ~Task();
    
private:
    int id;
    static int counter;
    std::vector<Task*> prevs;
    bool performed;
};


#endif /* Task_h */
