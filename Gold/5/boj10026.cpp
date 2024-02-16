#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/10026
    10026번 적록색약
    빨강과 초록을 구분 못 함
*/
int n;
vector<string> board;
void inputs() {
    cin >> n;
    board.resize(n);
    for (auto& row : board) cin >> row;
}
bool visited[102][102];
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
void dfs(int x, int y, bool isTrue) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (visited[nx][ny]) continue;
        if (isTrue) {  // 빨강과 초록 구분 못함
            if (board[x][y] == 'B') {
                if (board[nx][ny] == 'B') {
                    dfs(nx, ny, isTrue);
                }
            } else {  // 아무거나 가셈
                if (board[nx][ny] != 'B') dfs(nx, ny, isTrue);
            }
        } else if (board[x][y] == board[nx][ny]) {  // 구분 잘함
            dfs(nx, ny, isTrue);                    // 갔다오자요
        }
    }
}
void solve() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            dfs(i, j, 0);
            cnt++;
        }
    }
    cout << cnt;
    cnt = 0;
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            dfs(i, j, 1);
            cnt++;
        }
    }
    cout << ' ' << cnt;
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    inputs();
    solve();
    return 0;
}