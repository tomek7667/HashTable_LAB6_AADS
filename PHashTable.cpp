//
// Created by Tomek on 25.05.2021.
//

#include "PHashTable.h"

void PHashTable::insert(string key, long long hash) {
    int i = 0;
    while (this->nodes[hash+i].key != key && this->nodes[hash+i].key.length() != 0) i++;
    this->nodes[hash+i].key = key;
    this->nodes[hash+i].occurences++;
    this->nodes[hash+i].hash = hash;
}

void PHashTable::remove(string key, long long hash) {
    int i = 0;
    while (this->nodes[hash+i].key != key && this->nodes[hash+i].key.length() != 0) i++;
    this->nodes[hash+i].key = "";
    this->nodes[hash+i].occurences = 0;
    this->nodes[hash+i].hash = 0;
}

int PHashTable::get_data(string key, long long hash) {
    int i = 0;
    while (this->nodes[hash+i].key != key && this->nodes[hash+i].key.length() != 0) i++;
    return this->nodes[hash+i].occurences;
}
