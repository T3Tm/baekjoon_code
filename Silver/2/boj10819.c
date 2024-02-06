#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -a)
typedef long long ll;
/*
    https://www.acmicpc.net/problem/10819
    10819번 차이를 최대로
*/
int n;
int arr[10];
int res = INT_MIN;
void inputs() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
}
void back(int depth, bool avail[], int result[]) {
    if (depth == n) {
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            cnt += abs((result[i] - result[i - 1]));
        }
        res = max(res, cnt);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (avail[i]) continue;
        avail[i] = true;
        result[depth] = arr[i];
        back(depth + 1, avail, result);
        avail[i] = false;
        result[depth] = 0;
    }
}
void solve() {
    bool avail[10] = {};
    int result[10] = {};
    back(0, avail, result);
    printf("%d", res);
}
int main() {
    inputs();
    solve();
    return 0;
}