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
            if (input[0] == '?') {
                input.erase(0, 1);
                hash = HashGenerator(input).hash;
                cout << H.get_data(input, hash) << endl;
            } else if (input[0] == '-') {
                input.erase(0, 1);
                hash = HashGenerator(input).hash;
                H.remove(input, hash);
            } else if (input[0] == 'q' && input.length() == 1) {
                return 1;
            } else {
                hash = HashGenerator(input).hash;
                H.insert(input, hash);
            }
        }
    }
    return 0;
}
