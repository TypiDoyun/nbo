#include <iostream>
#include <string>

using namespace std;

string nextTerm(string& original) {
    string result;

    char previous;
    int length = 0;

    for (char item : original) {
        if (previous == NULL) previous = item;
        if (previous != item) {
            result += to_string(length) + previous;
            previous = item;
            length = 0;
        }
        length++;
    }

    result += to_string(length) + previous;

    return result;
}

int main(void) {
    string original;
    char input;

    while (true) {
        cin >> input;

        if (input == '0') break;

        original += input;
    }

    string result = nextTerm(original);

    cout << result;
}