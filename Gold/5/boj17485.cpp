#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17485
	17485번 진우의 달 여행 (Large)

	두번 연속으로 같은 방향으로 움직일 수 없다?
	왼쪽 왼쪽 안됨.
	3차원 DP?
	dp[i][j][3]
	dp[i][j][0] 바로 직전에 왼쪽으로 왔던 것중에서 최대
	dp[i][j][1] 바로 직전에 직진으로 왔던 것중 최대
	dp[i][j][2] 바로 직전에 오른쪽으로 왔던 것중 최대
*/
using namespace std;
int n, m, arr[1002][1002], dp[1002][1002][3];
int main() {
	fast; cin >> n >> m; memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		dp[1][i][0] = arr[1][i];
		dp[1][i][1] = arr[1][i];
		dp[1][i][2] = arr[1][i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + arr[i][j];
			dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + arr[i][j];
			dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + arr[i][j];
		}
	}
	int answer = INT_MAX;
	for (int i = 1; i <= m; i++) {
		answer = min(answer, *min_element(dp[n][i], dp[n][i] + 3));
	}
	cout << answer;
	return 0;
}