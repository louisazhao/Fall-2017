//
//  TaskException.h
//  COMP345E7
//
//  Created by Zhao Rui on 2017-12-04.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#ifndef TaskException_h
#define TaskException_h

#include <exception>
#include <iostream>

class TaskException : public std::exception{
public:
    TaskException(const std::string& message):msg_(message){}
    
    virtual ~TaskException() throw(){}
    
    virtual const char* what() const throw(){
        return msg_.c_str();
    }
    
    
protected:
    std::string msg_;
};


#endif /* TaskException_h */
