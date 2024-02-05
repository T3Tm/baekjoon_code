#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
/*
        https://www.acmicpc.net/problem/2659
        십자카드 문제

        시계수란 : 시계방향으로 만들어질 수 있는 수들 중에서 가장 작은 수
*/
using namespace std;
int result;
int cnt;
int check[10000];
int makeNumber(int a, int b, int c, int d) {
    return a * 1000 + b * 100 + c * 10 + d;
}
void crosscard(int depth, int number) {
    if (depth == 4) {
        if (check[number]) return;
        cnt++;
        int d = number % 10;
        int c = number / 10 % 10;
        int b = number / 100 % 10;
        int a = number / 1000;
        check[makeNumber(a, b, c, d)] = 1;
        check[makeNumber(b, c, d, a)] = 1;
        check[makeNumber(c, d, a, b)] = 1;
        check[makeNumber(d, a, b, c)] = 1;
        if (number == result) {
            cout << cnt;
            exit(0);
        }
        return;
    }
    for (int i = 1; i <= 9; i++) {
        crosscard(depth + 1, number * 10 + i);
    }
}
int main() {
    fast;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    result = min(min(makeNumber(a, b, c, d), makeNumber(b, c, d, a)), min(makeNumber(c, d, a, b), makeNumber(d, a, b, c)));
    crosscard(0, 0);
    return 0;
}