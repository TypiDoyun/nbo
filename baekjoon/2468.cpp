#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> overflowed;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
    overflowed[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX < 0 || nextY < 0 || nextX >= board.size() || nextY >= board.size()) continue;
        if (overflowed[nextY][nextX] == 0) dfs(nextX, nextY);
    }
}

int main(void) {
    int size;

    scanf("%d", &size);

    for (int y = 0; y < size; y++) {
        board.push_back(vector<int>(size));
        overflowed.push_back(vector<int>(size, 0));
        for (int x = 0; x < size; x++) {
            scanf("%d", &board[y][x]);
        }
    }

    int result = 0;

    for (int depth = 0; depth <= 100; depth++) {
        int numberOfsafeZones = 0;
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                if (board[y][x] > depth) overflowed[y][x] = 0;
                else overflowed[y][x] = 1;
            }
        }
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                if (overflowed[y][x] == 1) continue;
                dfs(x, y);
                numberOfsafeZones++;
            }
        }

        result = max(result, numberOfsafeZones);
    }

    printf("%d", result);
}