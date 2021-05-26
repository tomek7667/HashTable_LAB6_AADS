//
// Created by Tomek on 26.05.2021.
//

#include "SCHashTable.h"


SCHashTable::SCHashTable() {
    this->nodes = new HNode*[MAX_N];
    for (int i = 0; i < MAX_N; i++) this->nodes[i] = new HNode();
}

void SCHashTable::insert(string key, long long int hash) {
    if (!this->nodes[hash%MAX_N]->free) {
        HNode * temp = this->nodes[hash % MAX_N];
        while (temp->next != nullptr && temp->key != key) temp = temp->next;
        if (temp->key == key) {
            temp->occurences++;
        } else if (temp->next == nullptr) {
            temp->next = new HNode(temp, key);
        } else {
            cout << "why did this happen\n";
        }
    } else {
        this->nodes[hash%MAX_N] = new HNode(nullptr, key);
    }
}

void SCHashTable::remove(string key, long long int hash) {
    if (this->nodes[hash%MAX_N]->free) return;
    HNode * temp = this->nodes[hash % MAX_N];
    if (temp->key == key) {
        this->nodes[hash%MAX_N] = this->nodes[hash%MAX_N]->next;
        delete temp;
        if (this->nodes[hash%MAX_N] == nullptr)
            this->nodes[hash%MAX_N] = new HNode();
        return;
    }
    while (temp->next != nullptr) {
        if (temp->key == key) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
    }
}

int SCHashTable::get_data(string key, long long int hash) {
    HNode * temp = this->nodes[hash % MAX_N];
    if (temp == nullptr) return 0;
    while (temp->next != nullptr && temp->key != key) temp = temp->next;
    if (temp->key == key) return temp->occurences;
    return 0;
}

SCHashTable::~SCHashTable() {
    for (int i = 0; i < MAX_N; i++) {
        delete this->nodes[i];
    }
}
