#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/17472
    17472번 다리 만들기 2
*/
int n, m;
int parent[9];           // 각 집합
int mark[4][12][12];     // map에서 부로를 mark
int visited[4][12][12];  // 방문
int board[12][12];
int find(int cur) {  // 해당 땅
    if (parent[cur] < 0) return cur;
    return parent[cur] = find(parent[cur]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (x > y) {
        parent[y] += parent[x];
        parent[x] = y;
    } else {
        parent[x] += parent[y];
        parent[y] = x;
    }
}
void inputs() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    memset(visited, -1, sizeof visited);
    memset(parent, -1, sizeof parent);
}
int dx[]{0, 0, 1, -1};  // 0 <-> 1
int dy[]{1, -1, 0, 0};  // 2 <-> 3
//(dir + 1)%2 + (dir>1)*2
queue<tuple<int, int, int>> q;
int number = 1;
void dfs(int x, int y, int num) {
    visited[0][x][y] = num;
    mark[0][x][y] = num;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (!board[nx][ny]) {
            q.push({i, nx, ny});
            visited[i][nx][ny] = 1;
            mark[i][nx][ny] = num;
            continue;
        }
        if (visited[0][nx][ny] != -1) continue;
        dfs(nx, ny, num);
    }
}
int bfs() {
    vector<tuple<int, int, int>> connect;
    while (!q.empty()) {
        auto [dir, x, y] = q.front();
        q.pop();
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny]) continue;
        // 왼 <-> 오
        // 위 <-> 아
        int diffdir = (dir + 1) % 2 + (dir > 1) * 2;
        if (visited[diffdir][nx][ny] != -1) {                        // 반대쪽에서 오던 것 확인
            if (mark[diffdir][nx][ny] == mark[dir][x][y]) continue;  // 같은 육지였으면 안됨.
            int a = find(mark[diffdir][nx][ny]);
            int b = find(mark[dir][x][y]);
            connect.push_back({visited[dir][x][y] + visited[diffdir][nx][ny], a, b});
            continue;
        }
        visited[dir][nx][ny] = visited[dir][x][y] + 1;
        mark[dir][nx][ny] = mark[dir][x][y];
        q.push({dir, nx, ny});
    }
    sort(connect.begin(), connect.end(), [](tuple<int, int, int>& x, tuple<int, int, int>& y) {
        auto [a, b, c] = x;
        auto [q, w, e] = y;
        return a < q;
    });
    if (connect.empty()) return -1;
    int ret = 0;
    for (int i = 0; i < connect.size(); i++) {
        auto [d, x, y] = connect[i];
        int X = find(x);
        int Y = find(y);
        if (X == Y) continue;
        merge(X, Y);
        ret += d;
    }
    int count = 0;
    for (int i = 1; i < number; i++) {
        if (parent[i] < 0) count++;
    }
    return count > 1 ? -1 : ret;
}
void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[0][i][j] != -1) continue;
            if (!board[i][j]) continue;
            dfs(i, j, number++);
        }
    }
    cout << bfs();
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    inputs();
    solve();
    return 0;
}