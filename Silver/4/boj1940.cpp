#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/1940
   1940¹ø ÁÖ¸ù
*/
using namespace std;
int n, m, cnt;
int arr[15002];
int main() {
    fast;
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == m)cnt++;
        }
    }
    cout << cnt;
    return 0;
}