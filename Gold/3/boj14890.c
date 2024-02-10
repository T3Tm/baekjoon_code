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
    https://www.acmicpc.net/problem/14890
    14890번 경사로
    1. 세로 먼저 지나가면서 갯수 세기
    2. 그 다음 가로로 지나가면서 갯수 세기
    출력해주기
*/
int n, l;
int board[102][102];
void inputs() {
    scanf("%d %d", &n, &l);
    FOR(i, n) {
        FOR(j, n) {
            scanf("%d", &board[i][j]);
        }
    }
}

bool isVertical(int x, int y) {  //
    int last = board[x][y];
    int cnt = 1;
    bool isDown = false;
    for (int i = x + 1; i < n; i++) {
        if (last != board[i][y]) {  // 이전 숫자와 다르다면 높이 차이가 몇 인지 확인한다.
            if (isDown) {
                if (cnt < l)
                    return false;
            }
            if (abs(board[i][y] - last) != 1) return false;  // 높이 차이가 1이 아니라면 애초에 불가능
            // 높이 차이가 1이면?
            if (last > board[i][y]) {  // 높은 곳에서 내려간다면? 임시 보류해놓고
                isDown = true;
                last = board[i][y];
                cnt = 1;
                continue;
            }
            // 다시 올라가기
            if (isDown) {                       // 만약 갯수가 l*2가 되지 않으면
                if (cnt < l * 2) return false;  // 다시 올라가는 거 설치 못 함
            }
            if (cnt < l) return false;  // 갯수가 l개 미만이면 경사로 설치 못하지
            isDown = false;
            // 괜찮으면 설치하고 내려가장
            last = board[i][y];
            cnt = 1;
        } else {  // 같은 거면 갯수 세기
            cnt++;
        }
    }
    if (isDown) {
        if (cnt < l) return false;
    }
    return true;
}
bool isHorizontal(int x, int y) {  // 여기서 출발
    int last = board[x][y];
    int cnt = 1;
    bool isDown = false;
    for (int i = y + 1; i < n; i++) {
        if (last != board[x][i]) {  // 이전 숫자와 다르다면 높이 차이가 몇 인지 확인한다.
            if (isDown) {
                if (cnt < l)
                    return false;
            }
            if (abs(board[x][i] - last) != 1) return false;  // 높이 차이가 1이 아니라면 애초에 불가능
            // 높이 차이가 1이면?
            if (last > board[x][i]) {  // 높은 곳에서 내려간다..? 그러면 경사로가 낮은 곳 기준이므로 낮은 곳에 갯수가 cnt개가 돼야한다.
                isDown = true;
                last = board[x][i];
                cnt = 1;
                continue;
            }
            // 다시 올라가기
            if (isDown) {                       // 만약 갯수가 l*2가 되지 않으면
                if (cnt < l * 2) return false;  // 다시 올라가는 거 설치 못 함
            }
            if (cnt < l) return false;  // 갯수가 l개 미만이면 경사로 설치 못하지
            // 괜찮으면 설치하고 내려가장
            isDown = false;
            last = board[x][i];
            cnt = 1;
        } else {  // 같은 거면 갯수 세기
            cnt++;
        }
    }
    if (isDown) {
        if (cnt < l) return false;
    }
    return true;
}
void solve() {
    int cnt = 0;
    For(n) {
        cnt += isVertical(0, i);
        cnt += isHorizontal(i, 0);
    }
    printf("%d", cnt);
}
int main() {
    inputs();
    solve();
    return 0;
}