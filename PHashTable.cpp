//
// Created by Tomek on 26.05.2021.
//

#include "PHashTable.h"
#include <iostream>
#define MAX_N 100001
void PHashTable::insert(string key, long long hash) {
    int i = 0;
    while (this->nodes[(hash+i)%MAX_N]->key != key && i <= MAX_N) i++;
    if (i > MAX_N) {
        i = 0;
        while (!this->nodes[(hash+i)%MAX_N]->free) i++;
        if (i > MAX_N) {
            cout << "[ERROR] HashTable is full!\n";
            exit(123);
        }
        this->nodes[(hash+i)%MAX_N] = new HashNode(key);
    } else {
        this->nodes[(hash+i)%MAX_N]->occurences++;
    }
}

void PHashTable::remove(string key, long long hash) {
    int i = 0;
    while (this->nodes[(hash+i)%MAX_N]->key != key && i < MAX_N) i++;
    if (i == MAX_N) return;
    this->nodes[(hash+i)%MAX_N]->free = true;
    this->nodes[(hash+i)%MAX_N]->key = "";
    this->nodes[(hash+i)%MAX_N]->occurences = 0;
}

int PHashTable::get_data(string key, long long hash) {
    int i = 0;
    while (this->nodes[(hash+i)%MAX_N]->key != key && i < MAX_N) i++;
    if (this->nodes[(hash+i)%MAX_N]->key == key) return this->nodes[(hash+i)%MAX_N]->occurences;
    return 0;
}

PHashTable::PHashTable() {
    this->nodes = new HashNode*[MAX_N];
    for (int i = 0; i < MAX_N; i++) this->nodes[i] = new HashNode();
}
