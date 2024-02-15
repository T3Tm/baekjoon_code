#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/28276
    28276번 Yawned-Zoned
 */

const int SIZE = 1e6;
int r, c, w;
vector<string> board;
vector<int> vertical;
vector<vector<int>> boardParent;
int parent[SIZE];
int setSave[SIZE];
void inputs() {
    cin >> r >> c >> w;
    board.resize(r);
    vertical.resize(c, -1);
    for (auto& row : board) cin >> row;
    boardParent.resize(r, vector(c, -1));
}
int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
    int X = find(x);
    int Y = find(y);
    if (X > Y) {
        parent[Y] += parent[X];
        parent[X] = Y;
    } else if (X < Y) {
        parent[X] += parent[Y];
        parent[Y] = X;
    }
}
void CountVerticalAndSaveSet() {
    int number = 0;
    for (int col = 0; col < c; col++) {
        int row = 0;
        while (row < r) {
            if (board[row][col] == '1') {
                int cnt = 0;
                int inner = row;
                while (inner < r && board[inner][col] == '1') {
                    boardParent[inner][col] = number;  // 이 곳이 number라고 저장
                    inner++;
                    cnt++;
                }
                setSave[number++] = cnt;
                row = inner - 1;
            }
            row++;
        }
    }
}
void MeetFirstVerticalSet() {
    for (int col = 0; col < c; col++) {
        for (int row = 0; row < r; row++) {
            if (board[row][col] == '1') {
                vertical[col] = boardParent[row][col];
                break;
            }
        }
    }
}
void Restore(int temp[], int last, int col) {
    for (int start = vertical[col]; start <= last; start++) {
        temp[start] = setSave[start];
        parent[start] = -1;
    }
}
bool isPossible(int mid) {
    for (int row = 0; row < r; row++) {
        int nowSet = boardParent[row][0];
        if (nowSet == -1) continue;
        if (setSave[nowSet] > mid) return false;
    }
    int cnt = 0;
    int temp[SIZE]{};
    memcpy(temp, setSave, sizeof(int) * (r * c));
    memset(parent, -1, sizeof(int) * (r * c));
    for (int col = 1; col < c; col++) {
        if (vertical[col] == -1) continue;
        int row = 0;
        while (row < r) {
            int nowSet = boardParent[row][col];
            if (nowSet == -1) {
                row++;
                continue;
            }
            if (setSave[nowSet] > mid) return false;
            unordered_set<int> mergeSet;
            int nrow = row;
            int size = 0;
            int total = setSave[nowSet];
            while (nrow < r && boardParent[nrow][col] == boardParent[row][col]) {
                if (boardParent[nrow][col - 1] != -1) {
                    int X = find(boardParent[nrow][col - 1]);
                    mergeSet.insert(X);
                    if (mergeSet.size() != size) {
                        size = mergeSet.size();
                        total += temp[X];
                    }
                }
                nrow++;
            }
            if (total > mid) {
                Restore(temp, nowSet, col);
                cnt++;
                break;
            } else {
                for (auto x : mergeSet) {
                    merge(x, nowSet);
                }
                int x = find(nowSet);
                temp[x] = total;  // 부모에 한 번만 저장하면 됨.
                row = nrow;       // lgn
            }
        }
    }
    return cnt <= w;
}
void solve() {
    CountVerticalAndSaveSet();
    MeetFirstVerticalSet();
    int left = 0, right = r * c;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (isPossible(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << left;
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    inputs();
    solve();
    return 0;
}