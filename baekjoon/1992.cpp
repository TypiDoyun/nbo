#include <cstdio>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

struct Location {
    unsigned long long x;
    unsigned long long y;
};

vector<vector<unsigned long long>> board;

int divideFloor(int index) {
    return index / 2;
}

int divideCeil(int index) {
    return ceil(index / 2.0);
}

string quadTree(Location from, Location to) {
    if (from.x == to.x && from.y == to.y) return to_string(board[to.y][to.x]);
    Location distance{ to.x - from.x, to.y - from.y };
    string result = 
        quadTree(
            from,
            Location{ from.x + divideFloor(distance.x), from.y + divideFloor(distance.y) }
        ) +
        quadTree(
            Location{ from.x + divideCeil(distance.x), from.y },
            Location{ to.x, from.y + divideFloor(distance.y) }
        ) +
        quadTree(
            Location{ from.x, from.y + divideCeil(distance.y) },
            Location{ from.x + divideFloor(distance.x), to.y }
        ) +
        quadTree(
            Location{ from.x + divideCeil(distance.x), from.y + divideCeil(distance.y) },
            to
        );
    bool isValid = true;
    for (unsigned long long i = 0; i < result.size(); i++) {
        if (i == 0) continue;
        if (result[i] != result[i - 1]) {
            isValid = false;
            break;
        }
    }
    if (isValid) return string(1, result[0]);
    else return "(" + result + ")";
}

int main(void) {
    unsigned long long size;

    scanf("%d", &size);

    for (unsigned long long y = 0; y < size; y++) {
        board.push_back(vector<unsigned long long>(size));
        for (unsigned long long x = 0; x < size; x++) {
            scanf("%1d", &board[y][x]);
        }
    }

    string result = quadTree(Location{ 0, 0 }, Location{ size - 1, size - 1 });

    printf("%s", result.c_str());
}