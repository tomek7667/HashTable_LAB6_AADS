//
// Created by Tomek on 25.05.2021.
//
#define MAX_N 100000
#ifndef HASZTEJBUL_PHASHTABLE_H
#define HASZTEJBUL_PHASHTABLE_H
#include <string>
#include <utility>
#include "HashGenerator.h"
using namespace std;

struct HashNode {
    string key;
    int occurences = 1;
    bool free = false;
    HashNode() {
        this->free = true;
    }
    HashNode(string k) {
        this->free = false;
        this->key = std::move(k);
    }
};

class PHashTable {
public:
    PHashTable();
    HashNode ** nodes = nullptr;
    void insert(string key, long long hash);
    void remove(string key, long long hash);
    int get_data(string key, long long hash);
};


#endif //HASZTEJBUL_PHASHTABLE_H
