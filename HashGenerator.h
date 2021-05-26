//
// Created by Tomek on 26.05.2021.
//

#ifndef HASZTEJBUL_HASHGENERATOR_H
#define HASZTEJBUL_HASHGENERATOR_H
#include <string>


class HashGenerator {
public:
    long long hash;
    explicit HashGenerator(const std::string& s);
};


#endif //HASZTEJBUL_HASHGENERATOR_H
