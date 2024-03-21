#include <stdio.h>
#include <stdlib.h>
/*
    https://www.acmicpc.net/problem/16924
    16924번 십자가 찾기
*/
typedef struct loc {
    int x, y, size;
} loc;
int visited[102][102];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
int Possible(int size, int x, int y, char board[102][102]) {
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j] * i;
            int ny = y + dy[j] * i;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) return 0;
            if (board[nx][ny] == '.') return 0;
        }
    }
    visited[x][y] = 1;
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j] * i;
            int ny = y + dy[j] * i;
            visited[nx][ny] = 1;
        }
    }
    return 1;
}
loc query[1000002];
int main() {
    scanf("%d %d", &n, &m);
    int idx = 0;
    char board[102][102];
    for (int i = 0; i < n; i++) scanf("%s", board[i]);
    for (int size = 1; size <= 49; size++) {
        for (int row = size; row < n - size; row++) {
            for (int column = size; column < m - size; column++) {
                if (board[row][column] == '*') {  // 이게 되므로 덮어써주자.
                    if (Possible(size, row, column, board)) {
                        query[idx].x = row + 1;
                        query[idx].y = column + 1;
                        query[idx++].size = size;
                    }
                }
            }
        }
    }
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m; column++) {
            if (board[row][column] == '*' && visited[row][column] == 0) {
                idx = -1;
                goto EXIT;
            }
        }
    }
EXIT:
    printf("%d\n", idx);
    if (idx != -1) {
        for (int i = 0; i < idx; i++) {
            printf("%d %d %d\n", query[i].x, query[i].y, query[i].size);
        }
    }
    return 0;
}