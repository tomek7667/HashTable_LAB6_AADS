//
// Created by Tomek on 25.05.2021.
//

#ifndef HASZTEJBUL_HASHTABLE_H
#define HASZTEJBUL_HASHTABLE_H
#include "Key.h"

class HashTable {
public:
    Key * keys = nullptr;
    int n;
    HashTable();
    void print() const;

    int get_key(const string& key) const;

    void add_key(string word);
    void num_of_occurs(const string& key) const;
    void remove_key(const string& key);
};


#endif //HASZTEJBUL_HASHTABLE_H
