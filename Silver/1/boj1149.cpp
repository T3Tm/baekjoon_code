#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1149
	1149번 RGB거리
	결국 1,2,3
	1에서 1을 칠할 수 없다.
*/
using namespace std;
long long dp[1002][1002];
int n;
int main() {
	fast; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 2; i <= n; i++) {
		dp[i][1] += min(dp[i - 1][2], dp[i - 1][3]);
		dp[i][2] += min(dp[i - 1][1], dp[i - 1][3]);
		dp[i][3] += min(dp[i - 1][1], dp[i - 1][2]);
	}
	cout << min({ dp[n][1],dp[n][2],dp[n][3] });
	return 0;
}