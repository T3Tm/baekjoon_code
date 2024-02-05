#include<bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
  https://www.acmicpc.net/problem/2164
  2164¹ø Ä«µå2
*/
using namespace std;
int n;
queue<int>values;
int main() {
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)values.push(i);
    while ((int)values.size() != 1) {
        values.pop();
        if ((int)values.size() == 1)break;
        auto backvalue = values.front(); values.pop();
        values.push(backvalue);
    }
    cout << values.front();
    return 0;
}