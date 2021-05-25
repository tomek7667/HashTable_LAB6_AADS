#include <iostream>
#include "HashTable.h"
#include <string>
using namespace std;

int main() {
    string input;
    HashTable H = HashTable();
    while (cin >> input) {
        if (input.length() > 0) {
            //cout << "Przed wykonaniem = " << input << "\n";
            //H.print();
            switch (input[0]) {
                case '?':
                    input.erase(0, 1);
                    H.num_of_occurs(input);
                    break;
                case '-':
                    input.erase(0, 1);
                    H.remove_key(input);
                    break;
                case 'q':
                    return 1;
                default:
                    H.add_key(input);
                    break;
            }
            //cout << "\nPo wykonaniu\n";
            //H.print();
        }
    }
    return 0;
}
