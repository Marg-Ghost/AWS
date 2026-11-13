//
// Created by Admin on 12.11.2026.
//

#include "TrieNode.h"

TrieNode::TrieNode() {
    std::unordered_map <std::string, TrieNode*> children = {};
    bool end_of_word = false;
}
std::unordered_map <std::string, TrieNode*> TrieNode::get_children() {
    return this->children;
}
void TrieNode::set_end_of_word(bool) {
    this->end_of_word = true;
}
bool TrieNode::get_end_of_word() {
    return this->end_of_word;
}