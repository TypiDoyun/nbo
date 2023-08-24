/**
 * https://www.acmicpc.net/problem/2178
*/
#include <stdio.h>
#include <vector>
#include <array>
#include <queue>

using namespace std;

vector<vector<short>> board;
vector<vector<bool>> visited;
queue<array<int, 3>> bfs;
int width, height;
int cnt;

bool isValid(int, int);

int main(void) {
    scanf("%d %d", &height, &width);

    for (int y = 0; y < height; y++) {
        board.push_back(vector<short>(width));
        visited.push_back(vector<bool>(width, false));
        for (int x = 0; x < width; x++) {
            scanf("%1hd", &board[y][x]);
        }
    }

    bfs.push({ 0, 0, 1 });

    while (!bfs.empty()) {
        array<int, 3> location = bfs.front();
        bfs.pop();
        int x = location[0];
        int y = location[1];
        cnt = location[2];

        if (x == width - 1 && y == height - 1) break;
        visited[y][x] = true;

        if (isValid(x, y - 1)) bfs.push({ x, y - 1, cnt + 1 }); // 상
        if (isValid(x, y + 1)) bfs.push({ x, y + 1, cnt + 1 }); // 하
        if (isValid(x + 1, y)) bfs.push({ x + 1, y, cnt + 1 }); // 좌
        if (isValid(x - 1, y)) bfs.push({ x - 1, y, cnt + 1 }); // 우
    }

    printf("%d", cnt);
}

bool isValid(int x, int y) {
    return !(x < 0 || y < 0 || x >= width || y >= height) && board[y][x] == 1 && !visited[y][x];
}