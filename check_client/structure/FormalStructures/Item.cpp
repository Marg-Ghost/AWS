//
// Created by Admin on 09.11.2026.
//

#include "Item.h"
#include "../Item.h"

Item::Item (std::string data) {
    this->data = data;
}
//getter && setter
void set_next(Item below) {
    this->next = below;
}
Item get_next() {
    return this->next;
}
void set_data(Item data) {
    this->data = data;
}
std::string get_data() {
    return this->data;
}