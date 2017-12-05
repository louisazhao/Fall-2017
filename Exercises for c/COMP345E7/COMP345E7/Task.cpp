//
//  Task.cpp
//  COMP345E7
//
//  Created by Zhao Rui on 2017-12-04.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "Task.h"
#include "TaskException.h"
using namespace std;

Task::Task()
{
    ++counter;
    id=counter;
    performed=false;
}

Task::~Task()
{
    std::cout<<"Task "<<this->id<<" deleted."<<endl;
}

void Task::addPrereq(Task* ptr)
{
    prevs.push_back(ptr);
}

bool Task::ready() const
{
    if(prevs.size()==0)
    {
        return true;
    }
    else{
    for(vector<Task*>::const_iterator it;it!=prevs.end();++it)
    {
        if((*it)->performed!=true)
        {
            return false;
        }
    }
        return true;}
}


bool Task::done() const
{
    return this->performed;
}

void Task::doIt()
{
    if(!this->ready())
    {
        throw new TaskException("Task not ready!");
    }
    else if(this->done())
    {
        throw new TaskException("Task already done!");
    }
    else{
        std::cout<<"Task "<<this->id<<" is done."<<endl;
        this->performed=true;
    }
}






