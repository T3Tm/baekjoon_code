#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr)
/*
 https://www.acmicpc.net/problem/28099
 28099번 이상한 배열

 max(arr[a:b]) > num:cout << "No" << endl;
 1 2 4 3 5 3

*/
using namespace std;
int idx[200003], arr[200003], n;
int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        unordered_map<int, int> s;
        set<int> T;
        string answer = "Yes";
        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            idx[num] = i, arr[i] = num, s[num] = (s[num] == 0 ? i : s[num]);
        }
        for (int i = 1; i <= n; i++) {
            if (s[arr[i]] == i) T.insert(arr[i]);
            if (idx[arr[i]] == i) T.erase(arr[i]);
            auto it = T.begin();
            if (!T.empty() && *it < arr[i]) {
                answer = "No";
                break;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
