#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/7569
    7569번 토마토
*/
struct loc {
    int h, x, y;
};
int m, n, h;
int visited[102][102][102];
int board[102][102][102];
queue<loc> q;
int zero;
void inputs() {
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            memset(visited[i][j], -1, sizeof(int) * m);
        }
    }
    for (int t = 0; t < h; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[t][i][j];
                if (board[t][i][j] == 1) {
                    q.push({t, i, j});
                    visited[t][i][j] = 0;
                } else if (!board[t][i][j])
                    zero++;
            }
        }
    }
}
int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};
int bfs() {
    int ret = -1;
    if (!zero) ret = 0;
    while (!q.empty()) {
        auto [H, x, y] = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nh = H + dh[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nh < 0 || nh >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nh][nx][ny] != -1 || board[nh][nx][ny] == -1) continue;
            visited[nh][nx][ny] = visited[H][x][y] + 1;
            q.push({nh, nx, ny});
            zero--;
            if (zero == 0) {
                ret = visited[nh][nx][ny];
            }
        }
    }
    return ret;
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