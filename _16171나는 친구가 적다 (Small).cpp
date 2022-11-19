#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
    https://www.acmicpc.net/problem/16171
    나는 친구가 적다 (Small)
    k 키워드가 s에 모두 존재해야됨
*/
int main() {
    fast;
    string s, k;
    string word;
    cin >> s >> k;
    for (auto value : s) {
        if (!(value <= '9' && value >= '0')) word += value;
    }
    if (word.find(k)!=string::npos)cout << 1;
    else cout << 0;
    return 0;
}