#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    int n;
    cin >> n;
    unordered_map<int, vector<int>> x;
    unordered_map<int, vector<int>> y;

    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        x[a].push_back(b);
        y[b].push_back(a);
    }
    long long res = 0;
    for (auto &[key, value] : x) {
        int size = x[key].size();
        for (auto nowY : value) {
            res += 1L * (y[nowY].size() - 1) * (size - 1);
        }
    }
    cout << res;
    return 0;
}