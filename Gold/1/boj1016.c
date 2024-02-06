#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
typedef long long ll;
/*
    https://www.acmicpc.net/problem/1016
    1016번 제곱 ㄴㄴ 수
    2부터 시작해서 min보다 크거나 같은 제곱수를 찾는다. 그리고 없애준다.
*/
ll x, y;
bool squareNumber[1000002];  // 제곱 ㄴㄴ수 확인용
void inputs() {
    scanf("%lld %lld", &x, &y);
}
void solve() {
    int cnt = 0;

    for (ll i = 2; i <= 1000001; i++) {            // 10^6을 제곱하면  10^6번
        ll square = i * i;                         // x보다 크거나 같은 제곱수를 O(1)에 구해보자.
        ll div = x / square + ((x % square) > 0);  // 몫을 구하고
        ll start = div * square;                   //
        for (; start <= y; start += square) {      // square씩 커지면서 squareNumber를 확인한다.
            squareNumber[start - x] = true;        // 1로 채워주기
        }
    }

    for (int i = 0; i < y - x + 1; i++) {  // y-x+1번은 확인 해야됨.
        cnt += !squareNumber[i];
    }
    printf("%d", cnt);
}
int main() {
    inputs();
    solve();
    return 0;
}