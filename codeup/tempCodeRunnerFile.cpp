#include <iostream>
#include <array>
#include <queue>
#include <vector>

using namespace std;

struct Location
{
    int x;
    int y;
    int distance;
};
typedef vector<vector<int>> World;

int sign(int x)
{
    if (x == 0)
        return 0;
    else if ((x ^ 1) >= 0)
        return 1;
    else
        return -1;
}

void fill(Location from, Location to, World &world)
{
    int minX = min(from.x, to.x);
    int maxX = max(from.x, to.x);
    int minY = min(from.y, to.y);
    int maxY = max(from.y, to.y);
    if (from.x == to.x)
    {
        for (int y = minY; y <= maxY; y++)
        {
            if (from.x == 0 && y == 0) continue;
            world[y][from.x] = -1;
        }
    }
    else if (from.y == to.y)
    {
        for (int x = minX; x <= maxY; x++)
        {
            if (from.y == 0 && x == 0) continue;
            world[from.y][x] = -1;
        }
    }
    else
    {
        int x = from.x;
        int y = from.y;
        int signX = sign(to.x - from.x);
        int signY = sign(to.y - from.y);

        while (x != to.x + signX && y != to.y + signY)
        {
            if (x == 0 && y == 0) continue;
            world[y][x] = -1;
            x += signX;
            y += signY;
        }
    }
}

int main(void)
{
    int width, height;

    cin >> height >> width;

    World world(height, vector<int>(width, 0));

    int amountOfMagic;

    cin >> amountOfMagic;

    for (int i = 0; i < amountOfMagic; i++)
    {
        Location from, to;

        cin >> from.y >> from.x >> to.y >> to.x;

        from.x--;
        from.y--;
        to.x--;
        to.y--;

        fill(from, to, world);
    }

    int maxSize = 0;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (world[y][x] != -1)
                continue;

            vector<int *> island;
            queue<Location> opened;

            opened.push({x, y, 0});

            while (!opened.empty())
            {
                Location current = opened.front();
                opened.pop();

                if (current.x < 0 || current.y < 0 || current.x >= width || current.y >= height)
                    continue;
                if (world[current.y][current.x] != -1)
                    continue;

                world[current.y][current.x] = -2;
                island.push_back(&world[current.y][current.x]);

                opened.push({current.x + 1, current.y});
                opened.push({current.x - 1, current.y});
                opened.push({current.x, current.y + 1});
                opened.push({current.x, current.y - 1});
            }

            for (int *ground : island)
            {
                *ground = island.size();
            }

            maxSize = max(maxSize, (int)island.size());
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (world[y][x] == 0)
                continue;
            else if (world[y][x] != maxSize)
                world[y][x] = -1;
        }
    }

    printf("%d\n", maxSize);

    // for (int y = 0; y < height; y++)
    // {
    //     for (int x = 0; x < width; x++)
    //     {   
    //         if (world[y][x] == -1) printf("X ");
    //         else printf("%d ", world[y][x]);
    //     }
    //     printf("\n");
    // }

    queue<Location> opened;
    World visited(height, vector<int>(width, 0));

    opened.push({0, 0, 0});

    while (!opened.empty())
    {
        Location current = opened.front();
        opened.pop();

        if (current.x < 0 || current.y < 0 || current.x >= width || current.y >= height)
            continue;
        if (visited[current.y][current.x] == 1)
            continue;
        if (world[current.y][current.x] == -1)
            continue;
        if (world[current.y][current.x] == maxSize)
        {
            printf("%d", current.distance);
            break;
        }
        visited[current.y][current.x] = 1;

        int distance = current.distance + 1;

        opened.push({current.x + 1, current.y, distance});
        opened.push({current.x - 1, current.y, distance});
        opened.push({current.x, current.y + 1, distance});
        opened.push({current.x, current.y - 1, distance});
    }
}
/*
5 5
4
1 2 2 2
4 2 4 5
4 5 5 5
4 5 3 4
*/
