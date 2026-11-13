//
// Created by Admin on 09.11.2026.
//

#ifndef AWS_HACKATHAN_STACK_H
#define AWS_HACKATHAN_STACK_H
#include "../API/Item.h"


class Stack {
private:
    Item top;
    int size;
    int max_size;
public:
    Stack(int size);
    //getter && setter
    Item get_top();
    //baisc
    void push(Item item);
    Item pop();
    //custome
    bool full();
    void clean();
};



#endif //AWS_HACKATHAN_STACK_H
