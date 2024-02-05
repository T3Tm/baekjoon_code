#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/6198
   6198¹ø ¿Á»ó Á¤¿ø ²Ù¹Ì±â
*/
using namespace std;
int n;
stack<pair<int, int>>roof;//value, idx ½Ö
int arr[80002];
long long result;
int main() {
    fast;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> arr[i];
    for (int i = 0; i < n; i++) {
        while (!roof.empty() && roof.top().first <= arr[i]) {
            result += (i - roof.top().second - 1);
            roof.pop();
        }
        roof.push({ arr[i],i });
    }
    while (!roof.empty()) {
        result += (n - roof.top().second - 1);
        roof.pop();
    }
    cout << result;
    return 0;
}