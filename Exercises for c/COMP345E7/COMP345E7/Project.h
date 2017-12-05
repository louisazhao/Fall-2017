//
//  Project.h
//  COMP345E7
//
//  Created by Zhao Rui on 2017-12-04.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef Project_h
#define Project_h

class Project{
public:
    Project(){};
    virtual bool tasksReady() const=0;
    virtual void doIt()=0;
    virtual ~Project(){};
};


#endif /* Project_h */
