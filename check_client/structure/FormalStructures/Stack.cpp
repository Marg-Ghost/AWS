//
// Created by Admin on 09.11.2026.
//

#include "../logic/Stack.h"

#include "Item.h"
#include "../../../../../../../Program Files/JetBrains/CLion 2026.1/bin/mingw/x86_64-w64-mingw32/include/stddef.h"

Stack::Stack(int size) {
    this->max_size = size;
    this->top = NULL;
}


void Stack::push(Item item) {
    Item temp;
    if (top == NULL) {
        temp = this->top;
        item.set_next(temp);
    }
    this->top = item;
    this->size++;
    if (full()){
        pop();
    }
}

Item Stack::pop() {
    if (top == NULL) {
        return;
    }
    Item temp = top;
    top = top->get_next();
    this->size--;
    std::cout << "Cleared now :" + this->size + "| in Stack";
    return temp;
}

//helper

bool Stack::full() {
    if ( size > max_size +1 ) {
        std::cout << "Stack Overflow";
        Stack::clean();
        return false;
    }
    if (size > max_size) {
        return true;
    }else{
        return false;
    }
}
bool Stack::clean() {
    while (size > max_size) {
        pop();
    }
    std::cout << "Stack cleard now Items :" + this->size + "| in Stack";
}
