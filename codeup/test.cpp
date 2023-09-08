#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    queue<int> myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    printf("%d\n", myQueue.front());
    myQueue.pop();
    printf("%d\n", myQueue.front());
    myQueue.pop();
    printf("%d\n", myQueue.front());
    myQueue.pop();
}