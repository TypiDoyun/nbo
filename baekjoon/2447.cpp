#include <cstdio>

using namespace std;

void fractal(int, int, int);

int main(void) {
    int size;

    scanf("%d", &size);

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            fractal(x, y, size);
        }
        printf("\n");
    }
}

void fractal(int x, int y, int size) {
    if (x / size % 3 == 1 && y / size % 3 == 1)
        printf(" ");
    else if (size == 1)
        printf("*");
    else
        fractal(x, y, size / 3);
}