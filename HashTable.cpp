//
// Created by Tomek on 25.05.2021.
//

#include "HashTable.h"
#define MAXIMUM_VALUE_OF_ELEMENTS 100000
HashTable::HashTable() {
    this->keys = new Key[MAXIMUM_VALUE_OF_ELEMENTS + 1];

}
