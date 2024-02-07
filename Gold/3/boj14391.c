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
    https://www.acmicpc.net/problem/14391
    14391번 종이 조각
    지금 있는 곳에서 왼쪽과 오른쪽을 고를 수 있음
    2가지
    골랐다면
    몇 칸?
    최대 4칸
    4번
    for문으로 전체 다 돌았을 때 16번

*/
int n, m;
int res;
char board[7][7];
void inputs() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", board[i]);
}
int right(int x, int y, int cnt, int visited[10]) {
    // 현재 좌표로 부터 얼만큼 오른쪽으로 자를 것인지 확인
    int ret = 0;
    for (int i = 0; i < cnt; i++) {  // cnt갯수 만큼 자를 것이다.
        if (y + i >= m) {
            ret = -1;
            break;
        }
        if (visited[x] & (1 << y + i)) {  // 이미 다른 곳에서 잘라서 사용하고 있음
            ret = -1;
            break;
        }
    }
    if (!ret) {
        for (int i = 0; i < cnt; i++) {  // cnt갯수 만큼 자를 것이다.
            ret = ret * 10 + board[x][y + i] - '0';
        }
        visited[x] |= (((unsigned)-1) >> (32 - cnt)) << y;
    }
    return ret;
}
int down(int x, int y, int cnt, int visited[10]) {
    int ret = 0;
    for (int i = 0; i < cnt; i++) {  // cnt갯수 만큼 자를 것이다.
        if (x + i >= n) {
            ret = -1;
            break;
        }
        if (visited[x + i] & (1 << y)) {  // 이미 다른 곳에서 잘라서 사용하고 있음
            ret = -1;
            break;
        }
    }
    if (!ret) {
        for (int i = 0; i < cnt; i++) {  // cnt갯수 만큼 자를 것이다.
            visited[x + i] |= (1 << y);
            ret = ret * 10 + board[x + i][y] - '0';
        }
    }
    return ret;
}
void restore(int visited[10], int row, int col, int repeat, bool isRight) {
    if (isRight) {
        visited[row] &= ~((((unsigned)-1) >> 32 - repeat) << col);  // (col ~  col + repeat - 1)
    } else {
        for (int i = 0; i < repeat; i++) {
            visited[row + i] &= ~(1 << col);
        }
    }
}
void back(int number, int prex, int prey, int visited[10], int isEnd) {
    if (isEnd == n * m) {  // 16번
        res = max(res, number);
        return;
    }
    for (int row = prex; row < n; row++) {  // 16
        for (int col = prey; col < m; col++) {
            if (visited[row] & (1 << col)) continue;  // 당연히 현재 좌표의 값이 이미 가져간 값이라면 또 넣으면 안된다.
            if (board[row][col] == '0') {             // 그냥 넌 혼자서 잘라.
                visited[row] |= (1 << col);
                back(number, row, col + 1, visited, isEnd + 1);
                visited[row] &= ~(1 << col);
            } else {
                for (int repeat = 1; repeat <= m; repeat++) {
                    int Plus = right(row, col, repeat, visited);                          // 오른쪽으로 가기
                    if (Plus != -1) {                                                     //
                        back(number + Plus, row, col + repeat, visited, isEnd + repeat);  // 갔다온 다음은 복원
                        restore(visited, row, col, repeat, true);
                    } else {
                        break;
                    }
                }
                for (int repeat = 2; repeat <= n; repeat++) {
                    int Plus = down(row, col, repeat, visited);  // 아래로 내려가기
                    if (Plus != -1) {
                        back(number + Plus, row, col + 1, visited, isEnd + repeat);  // 갔다온 다음은 복원
                        restore(visited, row, col, repeat, false);
                    } else {
                        break;
                    }
                }
            }
        }
        prey = 0;
    }
}
void solve() {
    int visited[10] = {};
    back(0, 0, 0, visited, 0);
    printf("%d", res);
}
int main() {
    inputs();
    solve();
    return 0;
}