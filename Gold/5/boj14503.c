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
    https://www.acmicpc.net/problem/14503
    14503번 로봇 청소기
    1. 현재의 좌표를 먼저 보기
    2. 4칸을 보고 빈칸 확인 없으면?
        1. 바라보는 방향 유지한 채 후진할 수 있으면 한 칸 후진
        2. 후진 못 하면 작동 멈추기
    3. 빈 칸 있음
        1. 반시계로 회전
        2. 내 앞칸이 청소되지 않은 칸이야? 그럼 한 칸 전진
        2-1 아니야? 그럼 가만히
    //처음에 북쪽을 바라보고 있으면 dir
*/
int n, m;
int x, y, d;
int board[52][52];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dir[] = {-1, -1};  // 0번은 전진 1번은 후진
void setting() {
    if (!d) {
        dir[0] = 0;
        dir[1] = 2;
    } else if (d == 1) {
        dir[0] = 1;
        dir[1] = 3;
    } else if (d == 2) {
        dir[0] = 2;
        dir[1] = 0;
    } else {
        dir[0] = 3;
        dir[1] = 1;
    }
}
void inputs() {
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &x, &y, &d);
    FOR(i, n) {
        FOR(j, m) {
            scanf("%d", &board[i][j]);
        }
    }
    setting();
}
bool Cleanlocation() {
    int pre = board[x][y];
    if (board[x][y] == 0) board[x][y] = 2;
    return pre == 0;
}
bool isClean() {
    FOR(i, 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == 0) return true;
    }
    return false;
}
void Spinleft() {
    // 0 북 , 1동 , 2 남, 3 서
    //  0 -> 3
    //  1 -> 0
    //  2 -> 1
    //  3 -> 2
    d = d - 1 < 0 ? 3 : d - 1;
}
void isForwardClean() {
    int nx = x + dx[dir[0]];
    int ny = y + dy[dir[0]];
    if (board[nx][ny] != 0) return;
    x = nx, y = ny;
}
bool Back() {  // 뒤로 가는 것은
    int nx = x + dx[dir[1]];
    int ny = y + dy[dir[1]];  // 후진할 떄
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) return false;
    if (board[nx][ny] == 1) return false;
    x = nx, y = ny;
    return true;
}
void solve() {
    int cnt = 0;
    while (1) {  //
        // 현재 칸을 청소할 할 수 있는지
        if (Cleanlocation())
            cnt++;
        else if (isClean()) {
            Spinleft();  // 왼쪽으로 90도 회전
            setting();
            isForwardClean();  // 앞 쪽 청소 가능한지 판별
        } else if (!Back())
            break;
    }
    printf("%d", cnt);
}
int main() {
    inputs();
    solve();
    return 0;
}