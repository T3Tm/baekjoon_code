#include<bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
    https://www.acmicpc.net/problem/10773
    10773¹ø Á¦·Î
*/
using namespace std;
long long answer;
stack<int>values;
int main() {
    fast;
    int k; cin >> k;
    while (k--) {
        int number;
        cin >> number;
        if (!number) {
            answer -= values.top();
            values.pop();
            continue;
        }
        answer += number;
        values.push(number);
    }
    cout << answer;
    return 0;
}