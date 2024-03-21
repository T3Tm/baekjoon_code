#include <stdio.h>
/*
    https://www.acmicpc.net/problem/20061
    20061번 모노미노도미노2
*/
int dx[][2] = {{0}, {0}, {0, 0}, {0, 1}};
int dy[][2] = {{0}, {0}, {0, 1}, {0, 0}};
int board[11][11];
int score;
int isBound(int x, int y) { return x < 0 || x >= 10 || y < 0 || y >= 10; }
void block(int t, int x, int y) {
    int len = 1 + (t > 1);
    for (int i = 0; i < len; i++) {
        int nx = x + dx[t][i];
        int ny = y + dy[t][i];
        board[nx][ny] = 1;
    }
}
void right(int t, int x, int y) {
    while (!isBound(x, y)) {  // 경계면 안에 있을 때
        int len = 1 + (t > 1);
        for (int i = 0; i < len; i++) {  // t의 범위에 블럭이 있는지 계속 움직여보기
            int nx = x + dx[t][i], ny = y + dy[t][i];
            if (isBound(nx, ny) || board[nx][ny]) {  // 지금 경게면을 지나갈려고 함.
                // 이 때는 오른쪽 블럭이기에 왼쪽 한 칸
                block(t, x, y - 1);
                return;
            }
        }
        y++;
    }
    // 여기서는 다른 블럭
    block(t, x, y - 1);
}
void down(int t, int x, int y) {
    while (!isBound(x, y)) {  // 경계면 안에 있을 때
        int len = 1 + (t > 1);
        for (int i = 0; i < len; i++) {  // t의 범위에 블럭이 있는지 계속 움직여보기
            int nx = x + dx[t][i], ny = y + dy[t][i];
            if (isBound(nx, ny) || board[nx][ny]) {  // 지금 경게면을 지나갈려고 함.
                // 이 때는 오른쪽 블럭이기에 왼쪽 한 칸
                block(t, x - 1, y);
                return;
            }
        }
        x++;
    }
    // 여기서는 다른 블럭
    block(t, x - 1, y);
}
void row() {
    for (int i = 9; i >= 6; i--) {
        int temp = 0;
        for (int j = 0; j < 4; j++) {
            temp += board[i][j];
        }
        if (temp == 4) {                                  // 이 줄 삭제해야된다.
            score++;                                      // 점수 증가
            for (int j = 0; j < 4; j++) board[i][j] = 0;  //
        }
    }
}
void rowDown() {
    int idx = 9;  // board에 넣어야 될 행
    for (int i = 9; i >= 4; i--) {
        int flag = 0;
        for (int j = 0; j < 4; j++) {
            if (board[i][j]) {
                flag = 1;
                board[idx][j] = board[i][j];
                if (idx != i) board[i][j] = 0;  // 옮긴 것 삭제해주기
            }
        }
        if (flag) idx--;
    }
}
void column() {
    for (int i = 9; i >= 6; i--) {
        int temp = 0;
        for (int j = 0; j < 4; j++) {
            temp += board[j][i];
        }
        if (temp == 4) {                                  // 이 줄 삭제해야된다.
            score++;                                      // 점수 증가
            for (int j = 0; j < 4; j++) board[j][i] = 0;  //
        }
    }
}
void columnRight() {
    int idx = 9;  // board에 넣어야 될 열
    for (int i = 9; i >= 4; i--) {
        int flag = 0;
        for (int j = 0; j < 4; j++) {
            if (board[j][i]) {
                flag = 1;
                board[j][idx] = board[j][i];
                if (idx != i) board[j][i] = 0;  // 옮긴 것 삭제해주기
            }
        }
        if (flag) idx--;
    }
}
void whiteRow() {
    int idx = 9;
    for (int i = 5; i > 3; i--) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j]) {  // 보드에 값이 있으므로 해당 하는 젤 idx행 삭제
                for (int j = 0; j < 4; j++) {
                    board[idx][j] = 0;  //
                }
                idx--;
                break;
            }
        }
    }
}
void whiteColumn() {
    int idx = 9;
    for (int i = 5; i > 3; i--) {
        for (int j = 0; j < 4; j++) {
            if (board[j][i]) {  // 보드에 값이 있으므로 해당 하는 젤 idx행 삭제
                for (int j = 0; j < 4; j++) {
                    board[j][idx] = 0;  //
                }
                idx--;
                break;
            }
        }
    }
}
void blockset(int t, int b, int c) {
    right(t, b, c);
    down(t, b, c);
    row();
    rowDown();  // 행 내리기
    column();
    columnRight();  // 행 오른쪽으로 밀기
    // 연한 부분에 뭔가 있으면 처리
    whiteRow();
    rowDown();  // 다시 내려주기
    whiteColumn();
    columnRight();  // 다시 오른쪽으로 밀어주기
}
int totalTile() {
    int ret = 0;
    for (int i = 9; i > 5; i--) {
        for (int j = 0; j < 4; j++) {
            ret += board[i][j] + board[j][i];
        }
    }
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        blockset(a, b, c);
    }

    printf("%d\n", score);
    printf("%d", totalTile());

    return 0;
}