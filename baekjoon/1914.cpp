#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

/**
 * 탑 높이 n개의 문제를 해결하기 위해선 높이 n - 1개의 문제를 먼저 해결 해야한다는 점을 이용한 풀이
 *   
 * 
 *  -
 * ---
 *  A    B    C
 * 
 * 
 * ---   -
 *  A    B    C -> n개의 탑이 목표 지점까지 가기 위해선 n - 1개의 탑이 시작 또는 목표 지점이 아닌 곳에 완성되어있어야 한다.
 * 
 * 
 *       -   --- -> n개의 탑이 from 지점에서 to지점으로 by지점을 이용하여 이용하는 것을 hanoi(n, from, to, by) 라고 하면,
 *  A    B    C  -> n개의 탑이 to에 완성되기 위해선 n - 1개의 탑이 by에 존재해야 한다. 
 *               -> 따라서 hanoi(n, from, to, by)가 호출 되면, hanoi(n - 1, from, by, to)가 실행 되어야 하며,
 *            -  -> 그 후 n번째 원반을 to로 옮긴 후 by에 있는 n - 1개의 탑을 to로 옮겨줘야한다.
 *           ---
 *  A    B    C
*/

void hanoi(int, int, int, int);

int main(void) {
    int n;

    scanf("%d", &n);

    string a = to_string(pow(2, n));
	
	int x = a.find('.');
	a = a.substr(0, x);
	a[a.length() - 1] -= 1;

    printf("%s\n", a.c_str());
    if (n <= 20) hanoi(n, 1, 3, 2);
}

void hanoi(int n, int from, int to, int by) {
    if (n == 0) return;

    hanoi(n - 1, from, by, to);
    printf("%d %d\n", from, to);
    hanoi(n - 1, by, to, from);

    return;
}