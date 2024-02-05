#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/1755
   1755번 숫자놀이
*/
using namespace std;
map<char, string>convert = { {'0',"zero"},{'1',"one"},{'2',"two"},{'3' ,"three"},{'4',"four"},
    {'5',"five"},{'6',"six"},{'7',"seven"},{'8',"eight"},{'9',"nine"} };
vector<pair<string, int>>words;
int main() {
    fast;
    int m, n;
    cin >> m >> n;
    for (; m <= n; m++) {
        string temp;
        for (auto& value : to_string(m)) {
            temp += convert[value];
        }
        words.push_back({ temp,m });
    }
    sort(words.begin(), words.end());
    int idx = 0;
    for (auto& value : words) {
        cout << value.second << " ";
        idx++;
        if (idx == 10) {
            idx = 0;
            cout << endl;
        }
    }
    return 0;
}