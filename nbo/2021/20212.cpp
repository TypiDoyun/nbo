#include <iostream>

using namespace std;

int main(void) {
    string serial;
    string space;
    string brand;

    for (int index = 0; index < 4; index++) {
        cin >> space;


        if (space.length() != 4) {
            cout << -1;
            return 0;
        }

        if (index == 0) {
            int code = stoi(space.substr(0, 2));
            if (code == 35) brand = "JCB";
            else if (code == 37) brand = "American Express";
            else if (code >= 40 && code <= 49) brand = "VISA";
            else if (code >= 51 && code <= 55) brand = "MasterCard";
            else if (code == 65) brand = "BC Global";
            else if (code >= 90 && code <= 99) brand = "Local";
            else {
                cout << -2;
                return 0;
            }
        }

        serial += space;
    }

    int valid = 0;

    reverse(serial.begin(), serial.end());

    for (int index = 0; index < serial.length(); index++) {
        // cout << serial[index];
        if ((index + 1) % 2 == 0) {
            for (auto item : to_string((serial[index] - '0') * 2)) {
                valid += item - '0';
            }
        } else {
            valid += serial[index] - '0';
        }
    }

    cout << brand << " " << valid << " " << (valid % 10 == 0 ? "O" : "X");
}