#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/3066
    3066번 브리징 시그널
    2 3 4 5 6 7 8 9 10 1

*/
int n;
vector<int> arr;
void inputs() {
    cin >> n;
    arr = vector<int>(n);
    for (auto &i : arr) cin >> i;
}
void solve() {
    int t;
    cin >> t;
    while (t--) {
        inputs();
        vector<int> a{0};
        for (int i = 1; i <= n; i++) {
            if (a.back() < arr[i - 1]) {
                a.push_back(arr[i - 1]);
            } else {  //
                auto it = lower_bound(a.begin(), a.end(), arr[i - 1]) - a.begin();
                a[it] = arr[i - 1];
            }
        }
        cout << a.size() - 1 << endl;
    }
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    solve();
    return 0;
}