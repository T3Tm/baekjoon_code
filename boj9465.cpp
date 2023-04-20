#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/9465
	9465번 스티커
	뗀 스티커의 왼쪽, 오른쪽,위, 아래에 있는 스티커는 사용할 수 없게 된다.


*/
using namespace std;
int main() {
	fast;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int dp[2][100002]{ 0 };
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> dp[i][j];
			}
		}
		dp[0][1] += dp[1][0];
		dp[1][1] += dp[0][0];
		for (int i = 2; i < n; i++) {
			dp[0][i] += max({ dp[0][i - 2], dp[1][i - 1] ,dp[1][i - 2] });
			dp[1][i] += max({ dp[1][i - 2], dp[0][i - 1],dp[0][i - 2] });
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
	}
	return 0;
}