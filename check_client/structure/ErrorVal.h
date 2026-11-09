//
// Created by Admin on 09.11.2026.
//

#ifndef AWS_HACKATHAN_ERRORVAL_H
#define AWS_HACKATHAN_ERRORVAL_H

#include <stdio.h>

class ErrorVal {
private:
    std::string error_message;
public:
    ErrorVal();
    //getter && setter
    std::string get_error_message();
    void set_error_messgae(std::string message);

};



#endif //AWS_HACKATHAN_ERRORVAL_H
