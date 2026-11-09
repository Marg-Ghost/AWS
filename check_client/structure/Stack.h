//
// Created by Admin on 09.11.2026.
//

#ifndef AWS_HACKATHAN_STACK_H
#define AWS_HACKATHAN_STACK_H
#include "Item.h"


class Stack {
private:
    Item top;
    int max_size;
public:
    Stack();
    //getter && setter
    Item get_top();
    void set_top(Item item);
    //baisc
    void push(Item item);
    Item pop();
    //custome
    bool empty();
    bool full();
};



#endif //AWS_HACKATHAN_STACK_H
