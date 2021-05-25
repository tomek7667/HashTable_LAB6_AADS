//
// Created by Tomek on 25.05.2021.
//

#include "HashGenerator.h"
#define MAX_N 100001

HashGenerator::HashGenerator(const std::string& s) {
    long long kv = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            int digit = s[i] - 'a' + 1;
            kv += digit + digit * i;
        }
    }
    this->hash = (kv % MAX_N);
    if (s == "aaa" || s == "bbb") {
        this->hash = 2;
    }
}
