#include <iostream>
#include "HashTable.h"
#include <string>
using namespace std;

int main() {
    string input;
    while (cin >> input) {
        if (input.length() > 0) {
            switch (input[0]) {
                case '?':
                    break;
                case '-':
                    break;
                case 'q':
                    return 1;
            }
        }
    }
    return 0;
}
