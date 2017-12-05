//
//  SimpleProject.cpp
//  COMP345E7
//
//  Created by Zhao Rui on 2017-12-04.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include "SimpleProject.h"

SimpleProject::SimpleProject(Task* task):singleTask(task){}

SimpleProject::~SimpleProject()
{
    delete singleTask;
}

bool SimpleProject::tasksReady() const
{
    return singleTask->ready();
}

void SimpleProject::doIt()
{
    singleTask->doIt();
}


