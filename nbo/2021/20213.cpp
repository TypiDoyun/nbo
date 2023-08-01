#include <iostream>
#include <regex>

using namespace std;

int main(void) {
    int width, height, amountOfEnemy;

    cin >> width >> height >> amountOfEnemy;

    for (int index = 0; index < amountOfEnemy; index++) {
        regex re("(\\d+),(\\d+)");
        smatch result;
        string dataTemplate;

        cin >> dataTemplate;

        regex_match(dataTemplate, result, re);

        int x = stoi(result[1]);
        int y = stoi(result[2]);

        string controls;

        cin >> controls;

        for (char command : controls) {
            if (command == 'R') x = min(x + 1, width);
            else if (command == 'L') x = max(x - 1, 1);
            else if (command == 'D') y = min(y + 1, height);
            else if (command == 'U') y = max(y - 1, 1);
        }

        cout << x << "," << y << endl;
    }
}