//
// Created by Tomek on 25.05.2021.
//

#include "HashTable.h"
#include <iostream>

#include <utility>
#define MAXIMUM_VALUE_OF_ELEMENTS 100000
HashTable::HashTable() {
    this->keys = new Key[MAXIMUM_VALUE_OF_ELEMENTS + 1];
    this->n = 0;
}

void HashTable::add_key(string word) {
    for (int i = 0; i < this->n; i++) {
        if (this->keys[i].key == word) {
            this->keys[i].occurences++;
            return;
        }
    }
    this->keys[this->n].key = std::move(word);
    this->keys[this->n].occurences++;
    this->n++;
}

void HashTable::print() const {
    for (int i = 0; i < this->n; i++) {
        std::cout << this->keys[i].key << " - " << this->keys[i].occurences << endl;
    }
}

void HashTable::num_of_occurs(const string& key) const {
    int index = this->get_key(key);
    if (index > -1)
        cout << this->keys[this->get_key(key)].occurences << endl;
    else {
        cout << 0 << endl;
    }
}

void HashTable::remove_key(const string& key) {
    int index = get_key(key);
    for (int i = index; i < this->n; i++) {
        this->keys[i] = this->keys[i + 1];
    }
    this->n--;
}

int HashTable::get_key(const string& key) const {
    for (int i = 0; i < this->n; i++) {
        if (this->keys[i].key == key) return i;
    }
    return -1;
}

