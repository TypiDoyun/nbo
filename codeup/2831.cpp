#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

typedef pair<int, int> Location;
typedef array<int, 5> LocationInfo;

bool canGo(Location location, vector<vector<int>> &maze)
{
    if (location.first < 0 || location.second < 0 || location.first >= maze[0].size() || location.second >= maze.size())
        return false;
    return maze[location.second][location.second] == 0;
}

int main(void)
{
    int width, height;

    cin >> height >> width;

    vector<vector<int>> maze(height, vector<int>(width));
    Location start, end;

    for (int y = 0; y < height; y++)
    { // 값 입력받는 곳.
        for (int x = 0; x < width; x++)
        {
            char symbol = cin.get();
            if (symbol == '\n')
                symbol = cin.get();

            if (symbol == '#')
                maze[y][x] = 1;
            else if (symbol == '.')
                maze[y][x] = 0;
            else if (symbol == 'S')
            {
                start.first = x;
                start.second = y;
            }
            else
            {
                end.first = x;
                end.second = y;
            }
        }
    }

    int distance = 0x3f3f3f3f;
    bool success = false;

    // dijstra 시작

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (maze[y][x] != 1)
                continue;
            int walls = 0;
            if (!canGo({x + 1, y}, maze))
                walls++;
            if (!canGo({x - 1, y}, maze))
                walls++;
            if (!canGo({x, y + 1}, maze))
                walls++;
            if (!canGo({x, y - 1}, maze))
                walls++;

            if (walls >= 3)
                continue;

            priority_queue<LocationInfo, vector<LocationInfo>, greater<LocationInfo>> opened;
            vector<vector<bool>> closed(height, vector<bool>(width, false));
            opened.push({0, start.first, start.second, 0, 1});
            //            ^       ^            ^        ^                  ^
            //        도착지점까지   x            y       몇번째        벽을 길로 바꿀 수 있다면 1
            //        맨해튼 거리                      반복인지 저장           아니면 0
            while (!opened.empty())
            {
                LocationInfo current = opened.top();

                opened.pop();

                if (current[1] == end.first && current[2] == end.second)
                {
                    // 반복하다 좌표 같아지면 현재 몇 번 수행했는지 출력하고 종료.
                    distance = min(distance, current[3]);
                    break;
                }
                if (current[1] < 0 || current[2] < 0 || current[1] >= width || current[2] >= height)
                    continue;
                if (closed[current[2]][current[1]])
                    continue;
                if (maze[current[2]][current[1]] == 1)
                {
                    if (current[1] != x || current[2] != y)
                        continue;
                }
                closed[current[2]][current[1]] = true;

                opened.push({abs((current[1] - 1) - end.first) + abs(current[2] - end.second) + current[3] + 1,
                             current[1] - 1,
                             current[2],
                             current[3] + 1,
                             current[4]});
                opened.push({abs(current[1] - end.first) + abs((current[2] - 1) - end.second) + current[3] + 1,
                             current[1],
                             current[2] - 1,
                             current[3] + 1,
                             current[4]});
                opened.push({abs((current[1] + 1) - end.first) + abs(current[2] - end.second) + current[3] + 1,
                             current[1] + 1,
                             current[2],
                             current[3] + 1,
                             current[4]});
                opened.push({abs(current[1] - end.first) + abs((current[2] + 1) - end.second) + current[3] + 1,
                             current[1],
                             current[2] + 1,
                             current[3] + 1,
                             current[4]});
            }
        }
    }
    // success가 false면 출력 안했단 뜻이므로 가는 길 X -> -1 출력
    if (distance == 0x3f3f3f3f)
        printf("-1");
    else
        printf("%d", distance);
}