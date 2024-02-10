#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : -(a))
#define For(r) for (int i = 0; i < (r); i++)
#define FOR(a, b) for (int i = a; i < b; i++)
#define SWAP(i, j)   \
    {                \
        int OOO = i; \
        i = j;       \
        j = OOO;     \
    }
typedef long long ll;
/*
    https://www.acmicpc.net/problem/15685
    15685번 드래곤 커브
    도형 자체를 세우는 작업이 필요하다.
    g : 1
    d :  0
        전진
    g : 2
    d :  1   0    0
        전진 좌회전 전진
    g : 3
    d : 1    0    0   3    3    0   0
        전진 좌회전 전진 좌회전 전진 우회전 전진

    g : 4
    1    0    0   3    3    0   0        3
        전진 좌회전 전진 좌회전 전진 우회전 전진  좌회전
        3    2    2   3    3   0    0
        전진 좌회전 전진 우회전 전진 우회전 전진
    전진 0
    좌회전 1
    우회전 2
    // 0 -> 1
    // 1 -> 3
    // 2 -> 7
    // 3 -> 15
    // 4 -> 31
    // 5 -> 63
    // 6 -> 127
    // 7 -> 255
    // 8 -> 511
    // 9 -> 1023
    // 10 -> 2047
*/
int n;
int dragonCurve[11][2050] = {{0}};
void inputs() {
    scanf("%d", &n);
}
void makeDragonCurve(int gen, int len) {
    // 이전 것 복사
    For(len) {
        dragonCurve[gen][i] = dragonCurve[gen - 1][i];
    }
    // 좌회전 하나 추가
    dragonCurve[gen][len] = 1;  // 좌회전 한 번
    FOR(len + 1, len * 2 + 1) {
        if (dragonCurve[gen - 1][len - (i - len)] == 1) {  // 좌회전이면 우회전으로
            dragonCurve[gen][i] = 2;
        } else if (dragonCurve[gen - 1][len - (i - len)] == 2) {  // 우회전은 좌회전으로
            dragonCurve[gen][i] = 1;
        } else {  // 전진
            dragonCurve[gen][i] = 0;
        }
    }
}
void precomputation() {  //
    FOR(1, 11) {         // 세대
        // 현재 세대는 지난 세대에서 참조하여 만들면 됨.
        makeDragonCurve(i, (1 << i) - 1);  // 1세대부터 10세대까지 미리 다 만들기
    }
}
int x, y, d, g;
int board[102][102];

int dx[] = {0, -1, 0, 1};  // 동 북 좌 하
int dy[] = {1, 0, -1, 0};  // 우,좌,하,상
void setting(bool isLeft) {
    if (isLeft) {
        d = (d + 1) % 4;
    } else {
        d = d - 1 < 0 ? 3 : d - 1;
    }
}
void MOVE() {
    x = x + dx[d];
    y = y + dy[d];
    board[x][y] = 1;  // 좌표 찍고
}
void drawDragonCruve() {
    int size = (1 << (g + 1)) - 1;
    board[x][y] = 1;  // 현재 좌표 찍고
    For(size) {
        if (dragonCurve[g][i] == 0) {
            MOVE();
        } else if (dragonCurve[g][i] == 1) {  // 좌회전
            setting(true);
        } else {
            setting(false);
        }
    }
}

bool isSquare(int x, int y) {
    return board[x - 1][y] && board[x - 1][y - 1] && board[x][y - 1] && board[x][y];
}
int CountDragonCurve() {
    int ret = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            ret += isSquare(i, j);
        }
    }
    return ret;
}
void solve() {
    precomputation();  // 드래곤 커브 미리 구해놓기
    while (n--) {
        scanf("%d %d %d %d", &y, &x, &d, &g);
        drawDragonCruve();
    }
    printf("%d", CountDragonCurve());
}
int main() {
    inputs();
    solve();
    return 0;
}