#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/17140
    17140번 이차원 배열과 연산
*/
int r, c, k;
int a[102][102];
void inputs() {
    cin >> r >> c >> k;
    r--, c--;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> a[i][j];
    }
}
struct Arr {
    int number, cnt;
};
bool compare(const Arr &me, const Arr &other) {
    if (me.cnt == other.cnt) {
        return me.number < other.number;
    }
    return me.cnt < other.cnt;
}
void CommandR(int &r, int &c) {
    int nowc = 0;
    for (int i = 0; i < r; i++) {  // r
        vector<Arr> temp;
        unordered_map<int, int> save;
        for (int j = 0; j < c; j++) {  // c
            if (a[i][j] == 0) continue;
            if (save.find(a[i][j]) == save.end()) {
                save[a[i][j]] = 1;
            } else {
                save[a[i][j]]++;
            }
        }
        for (auto [key, value] : save) {
            temp.push_back({key, value});
        }
        sort(temp.begin(), temp.end(), compare);
        int col = min(50, (int)temp.size());
        for (int i = 0; i < 50 - col; i++) {
            temp.push_back({0, 0});
        }
        for (int repeat = 0; repeat < temp.size(); repeat++) {
            a[i][repeat * 2] = temp[repeat].number;
            a[i][repeat * 2 + 1] = temp[repeat].cnt;
        }
        nowc = max(col * 2, nowc);
    }
    c = nowc;
}
void CommandC(int &r, int &c) {
    int nowr = 0;
    for (int i = 0; i < c; i++) {  // r
        vector<Arr> temp;
        unordered_map<int, int> save;
        for (int j = 0; j < r; j++) {  // c
            if (a[j][i] == 0) continue;
            if (save.find(a[j][i]) == save.end()) {
                save[a[j][i]] = 1;
            } else {
                save[a[j][i]]++;
            }
        }
        for (auto [key, value] : save) {
            temp.push_back({key, value});
        }
        sort(temp.begin(), temp.end(), compare);
        int row = min(50, (int)temp.size());
        for (int i = 0; i < 50 - row; i++) {
            temp.push_back({0, 0});
        }
        for (int repeat = 0; repeat < temp.size(); repeat++) {
            a[repeat * 2][i] = temp[repeat].number;
            a[repeat * 2 + 1][i] = temp[repeat].cnt;
        }
        nowr = max(row * 2, nowr);
    }
    r = nowr;
}
void solve() {
    int t{};
    int nowr = 3;
    int nowc = 3;
    while (a[r][c] != k && t <= 100) {  // 80000의 시복을 갖는다.
        if (nowr >= nowc) {
            CommandR(nowr, nowc);
        } else {
            CommandC(nowr, nowc);
        }
        t++;
    }
    cout << (a[r][c] == k ? t : -1);
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    inputs();
    solve();
    return 0;
}