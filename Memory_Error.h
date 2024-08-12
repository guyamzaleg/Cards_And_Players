//
// Created by ise on 3/8/24.
//

#ifndef UNTITLED_MEMORY_ERROR_H
#define UNTITLED_MEMORY_ERROR_H
#include <exception>
using namespace std;
class Memory_Error:public exception
{
public:

    virtual const char* what() const throw() {
        return "Memory Problem\n";
    }
};
#endif //UNTITLED_MEMORY_ERROR_H
