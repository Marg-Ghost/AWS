//
// Created by Admin on 09.11.2026.
//

#ifndef AWS_HACKATHAN_ITEM_H
#define AWS_HACKATHAN_ITEM_H


class Item {
private:
    Item next;
    std::string data;
public:
    Item(std::string error);
    //getter && setter
    void set_next(Item below);
    Item get_next();
    void set_data(Item data);
    std::string get_data();
};



#endif //AWS_HACKATHAN_ITEM_H
