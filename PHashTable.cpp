//
// Created by Tomek on 25.05.2021.
//

#include "PHashTable.h"
#include <iostream>

void PHashTable::insert(string key, long long hash) {
    int i = 0;
    while (this->nodes[(hash+i)%MAX_N].key != key && this->nodes[(hash+i)%MAX_N].key.length() != 0) i++;
    this->nodes[(hash+i)%MAX_N].key = key;
    this->nodes[(hash+i)%MAX_N].occurences++;
    this->nodes[(hash+i)%MAX_N].hash = hash;
}

void PHashTable::remove(string key, long long hash) {
    int i = 0;
    while (this->nodes[(hash+i)%MAX_N].key != key && this->nodes[(hash+i)%MAX_N].key.length() != 0) i++;
    this->nodes[(hash+i)%MAX_N].key = "";
    this->nodes[(hash+i)%MAX_N].occurences = 0;
    this->nodes[(hash+i)%MAX_N].hash = 0;
}

int PHashTable::get_data(string key, long long hash) {
    int i = 0;
    while (this->nodes[(hash+i)%MAX_N].key != key && i > MAX_N) i++;
    return this->nodes[(hash+i)%MAX_N].occurences;
}