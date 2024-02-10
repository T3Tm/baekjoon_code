#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : -(a))
#define FOR(i, j) for (int i = 0; i < (j); i++)
#define SWAP(i, j)   \
    {                \
        int OOO = i; \
        i = j;       \
        j = OOO;     \
    }
typedef long long ll;
/*
    https://www.acmicpc.net/problem/16927
    16927번 배열 돌리기 2
    자.... 모든 좌표에서 O(1)

    애초에 배열을 이차원으로 받을 때 굳이 이렇게 받아야 되나?
    1200 * 150 * 10^9 = 18 * 10^4
    n = 4, m = 5, r = 10
    (1, 1) => (1, 5)
    r/n = 2
    r%n = 2

*/
int n, m, R;
int board[302][302];
void inputs() {
    scanf("%d %d %d", &n, &m, &R);
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
typedef struct Pair {
    int x, y;
} Pair;
Pair transLocation(Pair src, Pair bounds, Pair base, int repeat, int leftBottomRightTop) {  // left,bottom,right,top
    Pair ret = src;
    // 현재 좌표에서 행 단위로 일단 움직이고, 그다음 열, 그다음 행, 열로 움직이면서 O(1)
    // 정도만에 바로 좌표 알아내기
    while (repeat) {
        if (!leftBottomRightTop) {               // 현재 내려가는 상황
            if (ret.x + repeat >= bounds.x) {    // 오른쪽으로 가야함.
                                                 // 딱 경계면 까지만
                repeat -= bounds.x - ret.x - 1;  //
                ret.x = bounds.x - 1;
                leftBottomRightTop = 1;
            } else {
                ret.x += repeat;
                repeat = 0;
            }
        } else if (leftBottomRightTop == 1) {
            if (ret.y + repeat >= bounds.y) {    // 오른쪽으로 가야함
                repeat -= bounds.y - ret.y - 1;  //
                ret.y = bounds.y - 1;            // 딱 경계면 까지만
                leftBottomRightTop = 2;
            } else {
                ret.y += repeat;
                repeat = 0;
            }
        } else if (leftBottomRightTop == 2) {
            if (ret.x - repeat < base.x) {  // 오른쪽으로 가야함.
                repeat -= ret.x - base.x;   //
                ret.x = base.x;             // 딱 경계면 까지만
                leftBottomRightTop = 3;
            } else {
                ret.x -= repeat;
                repeat = 0;
            }
        } else {
            if (ret.y - repeat < base.y) {  // 오른쪽으로 가야함.
                repeat -= ret.y - base.y;   //
                ret.y = base.y;             // 딱 경계면 까지만
                leftBottomRightTop = 0;
            } else {
                ret.y -= repeat;
                repeat = 0;
            }
        }
    }
    return ret;
}
void nextLocation(Pair *loc, Pair base, Pair bounds) {
    Pair ret = *loc;
    if (ret.y == base.y && ret.x + 1 < bounds.x) {
        ret.x++;
    } else if (ret.x == bounds.x - 1 && ret.y + 1 < bounds.y) {
        ret.y++;
    } else if (ret.y == bounds.y - 1 && ret.x - 1 >= base.x) {
        ret.x--;
    } else if (ret.x == base.x && ret.y - 1 >= base.y) {
        ret.y--;
    }
    loc->x = ret.x;
    loc->y = ret.y;
}
void rotateLeft(int x, int y, int temp[][302]) {
    int yreat = m - x * 2 - 1;
    int xreat = n - x * 2 - 1;
    Pair bounds = {n - x, m - y};
    Pair base = {x, y};
    int r = R % ((xreat + yreat) * 2);
    // 하나의 좌표가 결국에는 어디로 가는지 알아내기
    int i;
    x++;
    Pair src = {x, y};
    // 처음 내가 붙여야 되는 장소 알아내기
    Pair ret = transLocation(src, bounds, base, r, 0);  // 4번
    for (i = x; i < x + xreat; i++) {                   // 4800
        temp[ret.x][ret.y] = board[i][y];
        nextLocation(&ret, base, bounds);
    }
    x = i - 1;
    y++;
    for (i = y; i < y + yreat; i++) {
        temp[ret.x][ret.y] = board[x][i];
        nextLocation(&ret, base, bounds);
    }
    y = i - 1;
    x--;
    for (i = 0; i < xreat; i++) {
        temp[ret.x][ret.y] = board[x - i][y];
        nextLocation(&ret, base, bounds);
    }
    x -= i - 1;
    y--;
    for (i = 0; i < yreat; i++) {
        temp[ret.x][ret.y] = board[x][y - i];
        nextLocation(&ret, base, bounds);
    }
}
void solve() {
    int repeat = min(n, m) / 2;
    int temp[302][302] = {};
    FOR(i, repeat) {             // 150 번
        rotateLeft(i, i, temp);  // 4800번
    }
    FOR(i, n) {
        FOR(j, m) {
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
}
int main() {
    inputs();
    solve();
    return 0;
}