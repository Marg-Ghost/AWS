//
// Created by Admin on 09.11.2026.
//

#include "ErrorDetector.h"
#include "../ErrorDetector.h"
#include "../FormalStructures/PrefixTree.h"

ErrorDetector::ErrorDetector() {
    std::vector<std::string> error_word_list;
    int error_word_size;
    std::ifstream file("../get_logs/error_fails.txt");
    if (!file.is_open()) {
        std::cout << "Error detector could not open file";
    }
    std::string line;
    while (std::getline(file, line)) {
        error_word_list[error_word_size] = line;
        error_word_size++;
    }
    file.close();
    this->error_tree = PrefixTree();
    for (int i = 0; i<error_word_size; i++) {
        tree.insert(error_word_list.at(i));
    }
}

int ErrorDetector::detect_string(std::stirng test) {
    //get all words to iterate over every one
    std::vector<std::string> word_list;
    int wl_size;
    std::string temp;
    int current_size;
    for (int i = 0; i<test.size(); i++) {
       if (test.at(i) == ' ') {
           word_list[wl_size] = temp;
           wl_size++;
           continue;
       }
        temp[current_size] = test.at(i);
        current_size ++;
    }

    //get all Key words for system errors -> outsourced in Konstruktur für bessere Laufzeit
    //nun unter this->error_tree
    



}