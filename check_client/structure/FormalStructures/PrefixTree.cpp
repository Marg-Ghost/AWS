//
// Created by Admin on 12.11.2026.
//

#include "PrefixTree.h"

#include "TrieNode.h"
#include <unordered_map>

PrefixTree::PrefixTree() {
    this->root = TrieNode();
}
//actions
void PrefixTree::insert(std::string word) {
    TrieNode *current = this->root;
    for (int i = 0; i < word.length(); i++) {
        if (!current->get_children().contains(word.at(i))) {
            current->set_new_entry(i) = TrieNode();
        }
        current = current->get_children().find(word.at(i));
    }
    current->set_end_of_word(true);
}
bool PrefixTree::search(std::string word) {
    TrieNode *current = this->root;
    for (int i = 0; i < word.length(); i++) {
        if (!current->get_children().contains(word.at(i))) {
            return false;
        }
        current = current->get_children().find(word.at(i));
    }
    return current->get_end_of_word();
}
bool PrefixTree::starts_with(std::stirng word) {
    TrieNode *current = this->root;
    for (int i = 0; i < word.length(); i++) {
        if (!current->get_children().contains(word.at(i))) {
            return false;
        }
        current = current->get_children().find(word.at(i));
    }
    return true;
}
