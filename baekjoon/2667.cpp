/**
 * https://www.acmicpc.net/problem/2667
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int count(int, int);

int SIZE;
vector<vector<int>> board;
vector<int> complexes;

int main(void) {

    int amountOfComplex = 0;

    cin >> SIZE;

    for (int y = 0; y < SIZE; y++) {
        board.push_back(vector<int>(SIZE));
        for (int x = 0; x < SIZE; x++) {
            scanf("%1d", &board[y][x]);
        }
    }

    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (board[y][x] == 0) continue;
            int numberOfHouse = count(x, y);
            complexes.push_back(numberOfHouse);
            amountOfComplex++;
        }
    }

    sort(complexes.begin(), complexes.end());

    printf("%d\n", amountOfComplex);
    for (int complex : complexes) {
        printf("%d\n", complex);
    }
}

int count(int x, int y) {
    if (x < 0 || y < 0 || x >= SIZE || y >= SIZE) return 0;
    if (board[y][x] == 0) return 0;
    board[y][x] = 0;
    return count(x + 1, y) + count(x - 1, y) + count(x, y + 1) + count(x, y - 1) + 1;
}