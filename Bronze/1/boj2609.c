#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    https://www.acmicpc.net/problem/2609
    boj2609
*/
typedef long long ll;
ll a, b;
ll gcd(ll x, ll y) {
    if (x % y == 0) return y;
    return gcd(y, x % y);
}
ll lcm(ll x, ll y) {
    return x * y / gcd(x, y);
}
void inputs() {
    scanf("%lld %lld", &a, &b);
}

void solve() {
    printf("%lld\n%lld", gcd(a, b), lcm(a, b));
}
int main() {
    inputs();
    solve();
    return 0;
}