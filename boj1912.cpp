#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/1912
   1912번 연속합

   연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
*/
using namespace std;
int dp[100002];
int n;
int main() {
    fast;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> dp[i];
    int result = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i], dp[i] + dp[i - 1]);
        result = max(dp[i], result);
    }
    cout << result;
    return 0;
}