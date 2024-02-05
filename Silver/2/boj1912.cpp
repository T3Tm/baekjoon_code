#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/1912
   1912�� ������

   ���ӵ� �� ���� ���� �����ؼ� ���� �� �ִ� �� �� ���� ū ���� ���Ϸ��� �Ѵ�.
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