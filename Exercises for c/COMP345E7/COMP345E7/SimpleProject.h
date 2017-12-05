//
//  SimpleProject.h
//  COMP345E7
//
//  Created by Zhao Rui on 2017-12-04.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef SimpleProject_h
#define SimpleProject_h
#include "Project.h"
#include "Task.h"

class SimpleProject: public Project{
public:
    SimpleProject(Task*);
    bool tasksReady() const override;
    void doIt() override;
    ~SimpleProject();
    
private:
    Task* singleTask;
};

#endif /* SimpleProject_h */
