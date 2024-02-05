#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/17220
    17220번 마약수사대
*/
int n, m;
unordered_map<char, vector<char> > graph;
unordered_set<char> dontGo;
void inputs() {
    cin >> n >> m;
    char a, b;
    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);  // 방향 그래프
    }
    int num;
    cin >> num;  // 삭제 해야 되는 노드 숫자
    while (num--) {
        cin >> a;
        dontGo.insert(a);
    }
}
bool visited[27];
int dfs(char cur) {
    int ret = 0;
    visited[cur - 'A'] = true;
    for (char next : graph[cur]) {
        if (dontGo.find(next) != dontGo.end()) {
            dfs(next);
        } else {
            ret += dfs(next);
        }
    }
    return ret + 1;
}
void solve() {
    int count = 0;
    for (char root = 'A'; root < 'A' + n - 1; root++) {
        if (visited[root - 'A']) continue;
        if (dontGo.find(root) != dontGo.end()) {
            dfs(root);
        } else {
            count += dfs(root) - 1;
        }
    }
    cout << count;
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    inputs();
    solve();
    return 0;
}