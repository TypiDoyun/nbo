#include <iostream>
#include <array>

using namespace std;

const int cubeSize = 3;

array<array<array<int, cubeSize>, cubeSize>, cubeSize> cube;

array<array<int, cubeSize>, cubeSize> winnerPattern;

int checkWinner() {
    int winner = 0;

    for (int z = 0; z < cubeSize; z++) {
        for (int y = 0; y < cubeSize; y++) {
            for (int x = 0; x < cubeSize; x++) {
                int stone = cube[z][y][x];

                if (stone == 0) continue;

                for (int checkZ = z; checkZ <= z + 1; checkZ++) {
                    for (int checkY = y; checkY <= y + 1; checkY++) {
                        for (int checkX = x; checkX <= x + 1; checkX++) {
                            if (checkX == x && checkY == y && checkZ == z) continue;
                            if (checkX >= cubeSize || checkY >= cubeSize || checkZ >= cubeSize) continue;
                            if (cube[checkZ][checkY][checkX] != stone) continue;

                            int nextX = 2 * checkX - x;
                            int nextY = 2 * checkY - y;
                            int nextZ = 2 * checkZ - z;

                            if (nextX >= cubeSize || nextY >= cubeSize || nextZ >= cubeSize) continue;
                            if (cube[nextZ][nextY][nextX] != stone) continue;

                            winnerPattern[0] = { x, y, z };
                            winnerPattern[1] = { checkX, checkY, checkZ };
                            winnerPattern[2] = { nextX, nextY, nextZ };

                            winner = stone;
                        }
                    }
                }
            }
        }
    }

    return winner;
}

int main(void) {
    for (int z = 0; z < cubeSize; z++) {
        for (int y = 0; y < cubeSize; y++) {
            for (int x = 0; x < cubeSize; x++) {
                cin >> cube[z][y][x];
            }
        }
    }

    int result = checkWinner();

    cout << result << endl;

    if (result == 0) return 0;

    sort(winnerPattern.begin(), winnerPattern.end(), [](array<int, cubeSize> a, array<int, cubeSize> b) {
        if (a[0] < b[0]) return true;
        else if (a[0] == b[0]) {
            if (a[1] < b[1]) return true;
            else if (a[1] == b[1]) return a[2] < b[2];
            else false;
        } else return false;
    });

    for (auto row : winnerPattern)
        cout << "(" << row[0] << ", " << row[1] << ", " << row[2] << ")" << endl;
}