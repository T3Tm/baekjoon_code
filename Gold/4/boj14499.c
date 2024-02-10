#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : -(a))
#define For(r) for (int i = 0; i < (r); i++)
#define FOR(i, j) for (int i = 0; i < (j); i++)
#define SWAP(i, j)   \
    {                \
        int OOO = i; \
        i = j;       \
        j = OOO;     \
    }
typedef long long ll;
/*
    https://www.acmicpc.net/problem/14499
    14499번 주사위 굴리기
*/
int n, m, x, y, k;
int board[22][22];
int dice[7] = {};                        // 0이 상단 , 1이 뒤 2가 오른쪽 3 왼쪽 5 앞 6이 아래
int mapping[7] = {0, 1, 2, 3, 4, 5, 6};  // 상단에 있는 숫자가 무엇인지 맵핑해주기

void inputs() {
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    FOR(i, n) {
        FOR(j, m) {
            scanf("%d", &board[i][j]);
        }
    }
}
bool isBound(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}
bool MoveEast() {
    if (isBound(x, y + 1)) return false;
    y++;
    // 1 -> 3 -> 6 -> 4 -> 1
    int save = mapping[1];
    mapping[1] = mapping[4];
    mapping[4] = mapping[6];
    mapping[6] = mapping[3];
    mapping[3] = save;
    return true;
}
bool MoveNorth() {
    if (isBound(x - 1, y)) return false;
    x--;
    // 6 -> 5 -> 1 -> 2 -> 6
    int save = mapping[6];
    mapping[6] = mapping[2];
    mapping[2] = mapping[1];
    mapping[1] = mapping[5];
    mapping[5] = save;
    return true;
}
bool MoveSouth() {
    if (isBound(x + 1, y)) return false;
    // 1 -> 5 -> 6 -> 2 -> 1
    x++;
    int save = mapping[1];
    mapping[1] = mapping[2];
    mapping[2] = mapping[6];
    mapping[6] = mapping[5];
    mapping[5] = save;
    return true;
}
bool MoveWest() {
    if (isBound(x, y - 1)) return false;
    y--;
    // 4 -> 6 -> 3 -> 1 -> 4
    int save = mapping[4];
    mapping[4] = mapping[1];
    mapping[1] = mapping[3];
    mapping[3] = mapping[6];
    mapping[6] = save;
    return true;
}
void solve() {
    int cmd;
    bool flag;  // 1 동 , 2 서, 3 북, 4 남
    For(k) {
        scanf("%d", &cmd);
        switch (cmd) {
            case 1:
                flag = MoveEast();
                break;
            case 2:
                flag = MoveWest();
                break;
            case 3:
                flag = MoveNorth();
                break;
            case 4:
                flag = MoveSouth();
                break;
        }
        if (flag) {
            dice[mapping[6]] = !board[x][y] ? dice[mapping[6]] : board[x][y];
            board[x][y] = !board[x][y] ? dice[mapping[6]] : 0;
            printf("%d\n", dice[mapping[1]]);
        }
    }
}
int main() {
    inputs();
    solve();
    return 0;
}