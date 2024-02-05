#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/11060
	11060번 점프 점프
	1*n 크기의 미로에 갇혀있다.
	i번째 칸에 쓰여 있는 수를 Ai라고 한다.
	Ai이하만큼 오른쪽 떨어진 칸으로 한 번에 점프 할 수 있다.


	수직선 상에서 가장 오른쪽 끝으로 가려고 한다.
	이때, 최소 몇 번 점프를 해야 갈 수 있는지 구하는 프로그램을 작성하시오.
*/
using namespace std;
int n, arr[1003], dp[1300];
int main() {
	fast; cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	memset(dp, -1, sizeof dp);
	dp[1] = 0;//처음만 0
	for (int i = 1; i <= n; i++) {
		if (dp[i] == -1)continue;
		for (int j = 1; j <= arr[i]; j++) {
			if (dp[i + j] == -1)dp[i + j] = dp[i] + 1;
			else dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	cout << dp[n];
	return 0;
}