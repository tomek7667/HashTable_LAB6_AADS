//
// Created by Tomek on 26.05.2021.
//

#ifndef HASZTEJBUL_SCHASHTABLE_H
#define HASZTEJBUL_SCHASHTABLE_H
#include <string>
#include <iostream>
#include "HashGenerator.h"
#define MAX_N 26
using namespace std;

struct HNode {
    string key;
    int occurences = 1;
    bool free = false;
    HNode * next = nullptr;
    HNode * prev = nullptr;
    HNode() {
        this->free = true;
    }
    HNode(HNode * p, string k) {
        this->prev = p;
        this->free = false;
        this->key = std::move(k);
    }
};

class SCHashTable {
public:
    SCHashTable();
    HNode ** nodes = nullptr;
    void insert(string key, long long hash);
    void remove(string key, long long hash);
    int get_data(string key, long long hash);
};


#endif //HASZTEJBUL_SCHASHTABLE_H
