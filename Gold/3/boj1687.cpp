#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/1687
    1687번 행렬 찾기
    2차원 누적합 + 구현으로 한 번 해봅시다~
*/
int n, m;
vector<vector<int>> board;
vector<vector<int>> prefix;
void inputs() {
    cin >> n >> m;
    board.resize(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        for (int j = 1; j <= m; j++) {
            board[i][j] = temp[j - 1] - '0';
        }
    }
    prefix.resize(n + 1, vector<int>(m + 1, 0));
}
void solve() {
    // 2차원 누적합
    //
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + board[i][j];
        }
    }
    int save = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!board[i][j]) {
                int r = i;
                while (r <= n && !board[r][j]) {
                    int c = j;
                    while (c <= m && (prefix[r][c] - prefix[r][j - 1] - prefix[i - 1][c] + prefix[i - 1][j - 1]) == 0) {
                        save = max(save, (r - i + 1) * (c - j + 1));
                        c++;
                    }
                    r++;
                }
            }
        }
    }
    cout << save;
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    inputs();
    solve();
    return 0;
}