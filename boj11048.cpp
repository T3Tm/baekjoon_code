#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/11048
	11048번 이동하기

	1,1에서n,m까지 가는데
	n,m까지 가져올 수 있는 사탕의 최댓값은 무엇이니?

*/
using namespace std;
int n, m;
int arr[1002][1002],dp[1002][1002];
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int main() {
	fast; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][1] = arr[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int z = 0; z < 2; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx < 0 || nx >= n + 1 || ny < 0 || ny >= m + 1)continue;
				dp[nx][ny] = max(dp[i][j] + arr[nx][ny],dp[nx][ny]);
			}
		}
	}
	cout << dp[n][m];
	return 0;
}