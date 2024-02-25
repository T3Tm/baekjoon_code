#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/4991
    4991번 로봇 청소기
    청소한 갯수마다 방문배열 만들기
*/
int n, m;
int visited[1026][22][22];
vector<vector<char>> board;
bool inputs() {
    cin >> m >> n;
    if (n == m && m == 0) return false;
    board = vector<vector<char>>(n, vector<char>(m));
    for (auto& row : board) {
        for (auto& col : row) cin >> col;
    }
    memset(visited, -1, sizeof visited);
    return true;
}
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
int bfs() {
    int dirty = 0;
    queue<tuple<int, int, int>> q;
    int number = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'o') {
                q.push({1, i, j});
                visited[1][i][j] = 0;
            } else if (board[i][j] == '*') {
                dirty++;
                board[i][j] = number + '0';
                number++;
            }
        }
    }
    dirty = (1 << (dirty + 1)) - 1;
    int ret = 402;
    while (!q.empty()) {
        auto [dir, x, y] = q.front();
        q.pop();
        if (dir == dirty) {
            ret = min(ret, visited[dir][x][y]);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int plus = 0;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 'x') continue;
            if (board[nx][ny] >= '1' && board[nx][ny] <= '9') {
                plus = board[nx][ny] - '0';
            }
            if (visited[dir | (1 << plus)][nx][ny] != -1) {
                continue;
            }
            int nextkey = dir | (1 << plus);
            visited[nextkey][nx][ny] = visited[dir][x][y] + 1;
            q.push({nextkey, nx, ny});
        }
    }

    return ret == 402 ? -1 : ret;
}
void solve() {
    while (inputs()) {
        cout << bfs() << endl;
    }
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    solve();
    return 0;
}