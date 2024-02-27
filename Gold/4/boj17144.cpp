#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/17144
    17144번 미세먼지 안녕!
    1. 미세먼지 확산 동시에 일어나야 됨.
        1. 인접한 네 방향으로 확산
        2. 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산 없음
        3. 확산되는 양은 /5이다.
        4. 남은 미세먼지 양은 확산된 방향 * n개
    2. 공기 청정기 작동
        1. 반시계 바람
        2. 공기청정기 쪽부터 하나씩 땡겨주면 된다.
*/
int n, m, t;
int board[52][52];
void inputs() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
}
struct query {
    int x, y, cnt;  //
};
vector<query> s;
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
void checkFourBound(int i, int j) {
    int cnt = 0;
    for (int z = 0; z < 4; z++) {
        int nx = i + dx[z];
        int ny = j + dy[z];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == -1) continue;
        cnt++;
    }
    for (int z = 0; z < 4; z++) {
        int nx = i + dx[z];
        int ny = j + dy[z];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == -1) continue;
        s.push_back({nx, ny, board[i][j] / 5});
    }
    board[i][j] -= (board[i][j] / 5) * cnt;
}
void spread() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == -1) continue;
            checkFourBound(i, j);
        }
    }
}
void task() {
    while (!s.empty()) {
        auto [x, y, cnt] = s.back();
        s.pop_back();
        board[x][y] += cnt;
    }
}
struct filt {
    int x, y;
    filt(int q, int w) : x(q), y(w) {}
};
filt up(0, 0), down(0, 0);
void filter() {
    int x = up.x - 1;
    int y = up.y;
    while (x - 1 >= 0) {
        board[x][y] = board[x - 1][y];
        x--;
    }
    while (y + 1 < m) {
        board[x][y] = board[x][y + 1];
        y++;
    }
    while (x + 1 <= up.x) {
        board[x][y] = board[x + 1][y];
        x++;
    }
    while (y - 1 > up.y) {
        board[x][y] = board[x][y - 1];
        y--;
    }
    board[x][y] = 0;
    x = down.x + 1;
    y = down.y;
    while (x + 1 < n) {
        board[x][y] = board[x + 1][y];
        x++;
    }
    while (y + 1 < m) {
        board[x][y] = board[x][y + 1];
        y++;
    }
    while (x - 1 >= down.x) {
        board[x][y] = board[x - 1][y];
        x--;
    }
    while (y - 1 > down.y) {
        board[x][y] = board[x][y - 1];
        y--;
    }
    board[x][y] = 0;
}
int dust() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ret += board[i][j] == -1 ? 0 : board[i][j];
        }
    }
    return ret;
}
void solve() {
    for (int row = 0; row < n; row++) {
        if (board[row][0] == -1) {
            if (up.x == 0)
                up = filt(row, 0);
            else
                down = filt(row, 0);
        }
    }
    while (t--) {
        spread();  // 먼지 뿌리기
        task();    // 먼지 뿌린 거 한꺼번에 처리
        filter();  // 청정기 작동
    }
    cout << dust();
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    inputs();
    solve();
    return 0;
}