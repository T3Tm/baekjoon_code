#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/9414
    9414번 프로그래밍 대회 전용 부지
*/
vector<int> arr;
void inputs() {
    int a;
    while (cin >> a) {
        if (a == 0) break;
        arr.push_back(a);
    }
}
void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long money = 5 * 1e6;
        arr.resize(0);
        inputs();
        if (arr.empty()) break;
        sort(arr.begin(), arr.end(), [](int &a, int &b) { return a > b; });  // 내림차순
        long long spend = 0;
        string res = "";
        for (int i = 0; i < arr.size(); i++) {
            spend += 2L * pow(arr[i], i + 1);
            if (spend > money) {
                break;
            }
        }
        if (spend > money) {
            res = "Too expensive";
        } else {
            res = to_string(spend);
        }
        cout << res << endl;
    }
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    solve();
    return 0;
}