#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
typedef long long ll;
/*
    https://www.acmicpc.net/problem/18290
    18290번 NM과 K (1)
*/
typedef struct Pair {
    int x, y;
} Pair;
int n, m, k;
int **board;
Pair pickx[4];
int res = INT_MIN;
bool visited[12][12];
void inputs() {
    scanf("%d %d %d", &n, &m, &k);
    board = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isSearch(int x, int y) {
    if (visited[x][y]) return false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visited[nx][ny]) return false;
    }
    return true;
}
void pick(int depth) {
    if (depth == k) {  // depth가 k와 같을 때 뽑은 좌표의 값을 다 더한다.
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            int x = pickx[i].x;
            int y = pickx[i].y;
            cnt += board[x][y];
        }
        res = max(res, cnt);
        return;
    }
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (!isSearch(row, col)) continue;
            pickx[depth].x = row;
            pickx[depth].y = col;
            visited[row][col] = 1;
            pick(depth + 1);
            visited[row][col] = 0;
            pickx[depth].x = 0;
            pickx[depth].y = 0;
        }
    }
}
void solve() {
    pick(0);  // 뽑은 뒤에
    printf("%d", res);
}
int main() {
    inputs();
    solve();
    return 0;
}