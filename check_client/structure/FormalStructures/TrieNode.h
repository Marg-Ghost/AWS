//
// Created by Admin on 12.11.2026.
//

#ifndef AWS_HACKATHAN_TRIENODE_H
#define AWS_HACKATHAN_TRIENODE_H

#include <unordered_map>
#include <string>
class TrieNode {
private:
    std::unordered_map <std::string, TrieNode*> children;
    bool end_of_word = false;
public:
    TrieNode();
    //getter & setter
    std::unordered_map <std::string, TrieNode*> get_children();
    void set_new_entry(std::string, TrieNode*);
    void set_end_of_word(bool);
    bool get_end_of_word();
};



#endif //AWS_HACKATHAN_TRIENODE_H
