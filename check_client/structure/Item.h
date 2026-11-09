//
// Created by Admin on 09.11.2026.
//

#ifndef AWS_HACKATHAN_ITEM_H
#define AWS_HACKATHAN_ITEM_H

#include "ErrorVal.h"

class Item {
private:
    Item below;
    ErrorVal data;
public:
    Item();
    //getter && setter
    void set_below(Item below);
    Item get_below();
    void set_data(Item data);
    ErrorVal get_data();
};



#endif //AWS_HACKATHAN_ITEM_H
