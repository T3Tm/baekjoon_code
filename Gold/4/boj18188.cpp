#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/18188
    18188번 다오의 데이트
*/
struct Pair {
    int x, y;
};
int h, w, n;
vector<string> board;
vector<vector<int>> cmd;
Pair start;
Pair endPoint;
void inputs() {
    cin >> h >> w;
    board.resize(h);
    for (auto& row : board) cin >> row;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        vector<int> temp{a, b};
        cmd.push_back(temp);
    }
}
unordered_map<char, int> MOVE = {{'W', 0}, {'D', 1}, {'S', 2}, {'A', 3}};
int dx[]{-1, 0, 1, 0};
int dy[]{0, 1, 0, -1};
void back(int depth, vector<int>& result) {
    if (depth == n) {
        // result대로 움직였을 때 가능한지 판별
        Pair loc = start;
        for (int i = 0; i < n; i++) {
            int idx = result[i];
            int nx = loc.x + dx[MOVE[cmd[i][idx]]];
            int ny = loc.y + dy[MOVE[cmd[i][idx]]];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) return;  // 못 감
            if (board[nx][ny] == '@') return;                    // 블럭 위치는 못 감
            loc = {nx, ny};
            if (loc.x == endPoint.x && loc.y == endPoint.y) {  // 도달 했다..?
                cout << "YES" << endl;
                for (int j = 0; j <= i; j++) {
                    cout << (char)cmd[j][result[j]];
                }
                exit(0);
            }
        }
        return;
    }
    for (int i = 0; i < 2; i++) {
        result[depth] = i;
        back(depth + 1, result);
    }
}
void solve() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == 'D') {
                start = {i, j};
            } else if (board[i][j] == 'Z') {
                endPoint = {i, j};
            }
        }
    }
    vector<int> result(n);
    back(0, result);  // 시작
    cout << "NO";
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    inputs();
    solve();
    return 0;
}