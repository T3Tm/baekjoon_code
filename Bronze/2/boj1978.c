#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
/*
    https://www.acmicpc.net/problem/1978
    소수 찾기
*/
int n;
void inputs() {
    scanf("%d", &n);
}
bool isPrime(int num) {
    if (num < 2) return 0;
    for (int div = 2; div * div <= num; div++) {
        if (num % div == 0) return 0;
    }
    return 1;
}
void solve() {
    int cnt = 0;
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        cnt += isPrime(a);
    }
    printf("%d", cnt);
}
int main() {
    inputs();
    solve();
    return 0;
}