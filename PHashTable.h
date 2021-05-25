//
// Created by Tomek on 25.05.2021.
//
#define MAX_N 100001
#ifndef HASZTEJBUL_PHASHTABLE_H
#define HASZTEJBUL_PHASHTABLE_H
#include <string>
#include "HashGenerator.h"

using namespace std;
struct HashNode {
    string key;
    long long hash;
    int occurences = 0;
};

class PHashTable {
public:
    HashNode * nodes = new HashNode[MAX_N];
    void insert(string key, long long hash);
    void remove(string key, long long hash);
    int get_data(string key, long long hash);
};


#endif //HASZTEJBUL_PHASHTABLE_H
