#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : -(a))
#define FOR(i, j) for (int i = 0; i < (j); i++)
#define For(r) for (int i = 0; i < (r); i++)
#define SWAP(i, j)   \
    {                \
        int OOO = i; \
        i = j;       \
        j = OOO;     \
    }
typedef long long ll;
/*
    https://www.acmicpc.net/problem/16926
    16926번 배열 돌리기 1

*/
int n, m, r;
int board[302][302];
void inputs() {
    scanf("%d %d %d", &n, &m, &r);
    FOR(i, n) {
        FOR(j, m) {
            scanf("%d", &board[i][j]);
        }
    }
}
void arrcpy(int src[][302], int dst[][302]) {
    FOR(i, n) {
        memcpy(dst[i], src[i], sizeof(int) * m);
    }
}
void rotateLeft(int x, int y, int temp[][302]) {
    int yreat = m - x * 2 - 1;
    int xreat = n - x * 2 - 1; //
    // 행 땡기고
    for (int i = y; i < y + yreat; i++) {
        temp[x][i] = board[x][i + 1];
    }
    // 열 땡기고
    x++;
    int i;
    for (i = x; i < x + xreat; i++) {
        temp[i][y] = board[i - 1][y];
    }
    x = i - 1;
    // 행 떙기고
    y++;
    for (i = y; i < y + yreat; i++) {
        temp[x][i] = board[x][i - 1];
    }
    // 열 땡기고
    y = i - 1;
    for (i = 1; i <= xreat; i++) {
        temp[x - i][y] = board[x - i + 1][y];
    }
}
void solve() {
    int repeat = min(n, m) / 2;
    int temp[302][302] = {};
    For(r) {
        FOR(i, repeat) {
            rotateLeft(i, i, temp);
        }
        // 배열 복사
        arrcpy(temp, board);
    }
    FOR(i, n) {
        FOR(j, m) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
int main() {
    inputs();
    solve();
    return 0;
}