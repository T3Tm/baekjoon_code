#include<bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
  https://www.acmicpc.net/problem/9012
  9012¹ø °ýÈ£
*/
using namespace std;
int main() {
    fast;
    int t; cin >> t;
    while (t--) {
        stack<char>tmp;
        string temp, answer = "YES";
        cin >> temp;
        for (auto& value : temp) {
            if (value == '(')tmp.push('(');
            else {//»©¾ßµÊ.
                if (tmp.empty()) {
                    answer = "NO";
                    break;
                }
                else tmp.pop();
            }
        }
        if (!tmp.empty())answer = "NO";
        cout << answer << endl;
    }
    return 0;
}