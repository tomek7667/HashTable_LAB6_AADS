#include <iostream>
#include "PHashTable.h"
#include "HashGenerator.h"
#include <string>

using namespace std;


int main() {
    string input;
    PHashTable H = PHashTable();
    long long hash;
    while (cin >> input) {
        if (input.length() > 0) {
            switch (input[0]) {
                case '?':
                    input.erase(0, 1);
                    hash = HashGenerator(input).hash;
                    cout << H.get_data(input, hash) << endl;
                    break;
                case '-':
                    input.erase(0, 1);
                    hash = HashGenerator(input).hash;
                    H.remove(input, hash);
                    break;
                case 'q':
                    if (input.length() == 1) return 1;
                    break;
                default:
                    hash = HashGenerator(input).hash;
                    H.insert(input, hash);
                    break;
            }
        }
    }
    return 0;
}
