#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
typedef long long ll;
/*
    https://www.acmicpc.net/problem/14500
    테트로미노

    x 0 0 0
    90도 0 -> 1 -> 2 -> 3 -> 0 으로 변환 해주면 된다.

    1. 0 0 0
    2. 0 1 2
    3. 1 1 0
    4. 1 0 1
    5. 0 0 2 1
    x = (x + 1) % 4;

    (0 + 2 + (0%2)*2 )%4= 2
    (1 + 2) % 4 = 3
    (2 + 2 + (2%2) *2) % 4 = 0
    (3 + 2 + (3%2)*2) % 4 = 1

*/
int n, m;
int res;
int **board;
int block[5][4] = {
    {0, 0, 0},
    {0, 1, 2},
    {1, 1, 0},
    {1, 0, 1},
    {0, 0, 2, 1}};
int idx[] = {3, 3, 3, 3, 4};
void inputs() {
    scanf("%d %d", &n, &m);
    board = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (int *)malloc(sizeof(int *) * m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}
int yaxisSymmetry(int x) {
    return (x + 2 + (x % 2) * 2) % 4;
}
int degreeSymmetry(int x) {
    return (x + 1) % 4;
}
void degreeS(int i) {
    int size = idx[i];
    for (int z = 0; z < size; z++) {  // 모두 90도 꺽기
        block[i][z] = degreeSymmetry(block[i][z]);
    }
}
void yaxis(int i) {
    int size = idx[i];
    for (int z = 0; z < size; z++) {  // y축 대칭
        block[i][z] = yaxisSymmetry(block[i][z]);
    }
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int blockEstablish(int idxs, int x, int y) {
    int size = idx[idxs];
    int i = 0;
    int ret = board[x][y];
    // 1,2,3,4
    int lastx = -1, lasty = -1;
    for (; i < size; i++) {
        x += dx[block[idxs][i]];
        y += dy[block[idxs][i]];
        if (lastx == x && lasty == y) continue;
        if (!i) lastx = x, lasty = y;
        if (x < 0 || x >= n || y < 0 || y >= m) break;
        ret += board[x][y];
    }
    if (i != size) ret = 0;
    return ret;
}
void solve() {
    for (int i = 0; i < 5; i++) {                         // 5번
        for (int row = 0; row < n; row++) {               // 500
            for (int column = 0; column < m; column++) {  // 500
                int cnt = 0;
                for (int repeat = 0; repeat < 2; repeat++) {       // 2번
                    for (int degree = 0; degree < 4; degree++) {   // 4번
                        degreeS(i);                                // 4번
                        int ret = blockEstablish(i, row, column);  // 4
                        cnt = max(cnt, ret);
                    }
                    yaxis(i);  // 4번
                }              // 72 * 500 * 500 * 5
                res = max(res, cnt);
            }
        }
    }
    printf("%d", res);
}
int main() {
    inputs();
    solve();
    return 0;
}