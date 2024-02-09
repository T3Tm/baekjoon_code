#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -a)
#define FOR(i, j) for (int i = 0; i < j; i++)
#define SWAP(i, j) \
    {              \
        int t = i; \
        i = j;     \
        j = t;     \
    }
typedef long long ll;
/*
    https://www.acmicpc.net/problem/16935
    16935번 배열 돌리기 3
    1번 상하 반전
    2번 좌우 반전
    3번 오른쪽 90도
    4번 왼쪽 90도
    5번은 칸을 분할해서 시계방향으로 돌린다.
    6번은 칸을 분할해서 반시계방향으로 돌린다.

    5번 3번 -> 6번 1번
    3번 3번 -> 4번 1번
    1번 2번 -> 2번
    모든 쿼리 (1000)을 처리한다?

    모두다 처리하는데 각 쿼리당 n*m 의 시간이 걸림

    n*m * 1000 ?
    10^3 * 10^2 * 10^2
    3+2+2 = 10^7 => 천만
    그냥 나이브하게 구현해도 된다
*/
int n, m, r;
int board[102][102];
void inputs() {
    scanf("%d %d %d", &n, &m, &r);
    FOR(i, n) {
        FOR(j, m) {
            scanf("%d ", &board[i][j]);
        }
    }
}
void arrcpy(int src[][102], int dst[][102]) {
    FOR(i, n) {
        memcpy(dst[i], src[i], sizeof(int) * m);
    }
}
void topBottomInversion(int temp[][102]) {
    FOR(i, n) {
        FOR(j, m) {
            temp[i][j] = board[n - i - 1][j];  // 값 갖고 오기
        }
    }
    arrcpy(temp, board);  // board로 넣어주기
}
void leftRightInversion(int temp[][102]) {
    FOR(i, n) {
        FOR(j, m) {
            temp[i][j] = board[i][m - j - 1];  // 값 갖고 오기
        }
    }
    arrcpy(temp, board);
}
void rightSpin(int temp[][102]) {  // 오른쪽으로 90도 돌리는 거면 n,m이 바뀌어야 된다.
    FOR(i, m) {
        FOR(j, n) {
            temp[i][j] = board[n - j - 1][i];  // 값 갖고 오기
        }
    }
    SWAP(n, m);
    arrcpy(temp, board);
}
void leftSpin(int temp[][102]) {
    FOR(i, m) {
        FOR(j, n) {                            //
            temp[i][j] = board[j][m - i - 1];  // 값 갖고 오기
        }
    }
    SWAP(n, m);
    arrcpy(temp, board);
}
void splitLeft(int temp[][102]) {
    int divn = n / 2;
    int divm = m / 2;
    FOR(i, divn) {
        FOR(j, divm) {
            temp[i][j] = board[i][j + divm];
        }
    }
    FOR(i, divn) {
        for (int j = divm; j < m; j++) {
            temp[i][j] = board[i + divn][j];
        }
    }
    for (int i = divn; i < n; i++) {
        for (int j = divm; j < m; j++) {
            temp[i][j] = board[i][j - divm];
        }
    }
    for (int i = divn; i < n; i++) {
        FOR(j, divm) {
            temp[i][j] = board[i - divn][j];
        }
    }
    arrcpy(temp, board);
}
void splitRight(int temp[][102]) {
    int divn = n / 2;
    int divm = m / 2;
    FOR(i, divn) {  // 0번에 4번 있는 거 갖고 오기
        FOR(j, divm) {
            temp[i][j] = board[i + divn][j];
        }
    }
    FOR(i, divn) {
        for (int j = divm; j < m; j++) {
            temp[i][j] = board[i][j - divm];
        }
    }
    for (int i = divn; i < n; i++) {
        for (int j = divm; j < m; j++) {
            temp[i][j] = board[i - divn][j];
        }
    }
    for (int i = divn; i < n; i++) {
        FOR(j, divm) {
            temp[i][j] = board[i][j + divm];
        }
    }
    arrcpy(temp, board);
}
void excute(int query, int temp[][102]) {
    switch (query) {
        case 1:
            topBottomInversion(temp);
            break;
        case 2:
            leftRightInversion(temp);
            break;
        case 3:
            rightSpin(temp);
            break;
        case 4:
            leftSpin(temp);
            break;
        case 5:
            splitRight(temp);
            break;
        case 6:
            splitLeft(temp);
            break;
    }
}
void condition(int lastQuery, int cnt, int temp[][102]) {
    if (lastQuery == 1) {
        if (cnt == 1)
            excute(lastQuery, temp);
        else {
            FOR(i, cnt % 2) {
                excute(lastQuery, temp);
            }
        }
    } else if (lastQuery == 2) {
        if (cnt == 1)
            excute(lastQuery, temp);
        else {
            FOR(i, cnt % 2) {
                excute(lastQuery, temp);
            }
        }
    } else if (lastQuery == 3) {  // 오른쪽 90도가
        int cntt = cnt % 4;       //
        if (cntt == 3) {
            excute(4, temp);  // 4번 한 번
        } else {
            FOR(i, cntt) {
                excute(lastQuery, temp);
            }
        }
    } else if (lastQuery == 4) {
        int cntt = cnt % 4;  //
        if (cntt == 3) {
            excute(3, temp);  // 4번 한 번
        } else {
            FOR(i, cntt) {
                excute(lastQuery, temp);
            }
        }
    } else if (lastQuery == 5) {
        int cntt = cnt % 4;  //
        if (cntt == 3) {
            excute(6, temp);  // 4번 한 번
        } else {
            FOR(i, cntt) {
                excute(lastQuery, temp);
            }
        }
    } else {
        int cntt = cnt % 4;  //
        if (cntt == 3) {
            excute(5, temp);  // 4번 한 번
        } else {
            FOR(i, cntt) {
                excute(lastQuery, temp);
            }
        }
    }
}
void solve() {
    int query;
    int temp[102][102] = {};  // temp
    int lastQuery, cnt = 1;
    scanf("%d", &lastQuery);
    FOR(i, r - 1) {
        scanf("%d", &query);
        if (lastQuery != query) {  // 마지막 것과 다르다면 이전 거 실행해주기 같다면
            condition(lastQuery, cnt, temp);
            lastQuery = query;  // 쿼리 덮어쓰기
            cnt = 1;            // 갯수 1개
        } else {
            cnt++;
        }
    }
    condition(lastQuery, cnt, temp);
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