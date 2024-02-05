#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    https://www.acmicpc.net/problem/10430
*/
int a, b, c;
void inputs() {
    scanf("%d %d %d", &a, &b, &c);
}
void solve() {
    int one = (a + b) % c;
    int two = (a * b) % c;
    printf("%d\n%d\n%d\n%d", one, one, two, two);
}
int main() {
    inputs();
    solve();
    return 0;
}