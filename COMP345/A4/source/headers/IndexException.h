//
// Created by ling on 21/11/17.
//

#ifndef SOURCE_INDEXEXCEPTION_H
#define SOURCE_INDEXEXCEPTION_H

#include <exception>
#include <iostream>

class IndexException : public std::exception {
public:
    /** Constructor (C++ STL strings).
     *  @param message The error message.
     */
    IndexException(const std::string &message) :
            msg_(message) {}

    /** Destructor.
     * Virtual to allow for subclassing.
     */
    virtual ~IndexException() throw() {}

    /** Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. The underlying memory
     *          is in possession of the Exception object. Callers must
     *          not attempt to free the memory.
     */
    virtual const char *what() const throw() {
        return msg_.c_str();
    }

protected:
    /** Error message.
     */
    std::string msg_;
};

#endif //SOURCE_INDEXEXCEPTION_H
