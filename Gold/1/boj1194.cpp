#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
  https://www.acmicpc.net/problem/1194
  1194번 달이 차오른다, 가자.
*/
int visited[129][52][52];
vector<string> board;
int n, m;
void inputs() {
    cin >> n >> m;
    board.resize(n);
    for (auto& row : board) cin >> row;
    memset(visited, -1, sizeof visited);
}
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
int bfs() {
    queue<tuple<int, int, int>> loc;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '0') {
                loc.push({1, i, j});
                visited[1][i][j] = 0;
                break;
            }
        }
    }
    while (!loc.empty()) {
        auto [key, x, y] = loc.front();
        loc.pop();
        if (board[x][y] == '1') {
            return visited[key][x][y];
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int plus = 0;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '#') continue;
            if (board[nx][ny] >= 'a' && board[nx][ny] <= 'f') {
                plus = board[nx][ny] - 'a' + 1;
            } else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'F') {  // 열쇠 있는지 확인
                int door = board[nx][ny] - 'A' + 1;
                if (!(key & (1 << door))) continue;
            }
            if (visited[key | (1 << plus)][nx][ny] != -1) continue;
            int nextkey = key | (1 << plus);
            visited[nextkey][nx][ny] = visited[key][x][y] + 1;
            loc.push({nextkey, nx, ny});
        }
    }
    return -1;
}
void solve() {
    cout << bfs();
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    inputs();
    solve();
    return 0;
}