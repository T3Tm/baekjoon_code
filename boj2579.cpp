#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2579
	2579번 계단 오르기

	한 번에 1,2계단씩 올라갈 수 있다.

	도착 계단은 무조건 밟아야 한다.

	이러면 탑다운이 좋을 것 같다.


	포도주 시식과는 다르게 여기서는 i번째 계단은 무조건 밟아야 한다는 조건이 있음.
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = arr[1] + arr[2] or arr[2] + arr[3];
	dp[4] = dp[2] + arr[4] or dp[1] + arr[3] + arr[4];
*/
using namespace std;
int n, dp[302], arr[302];
int main() {
	fast; cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	dp[1] = arr[1];
	if (n >= 2) {
		dp[2] = arr[1] + arr[2];
	}
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
	}
	cout << dp[n];
	return 0;
}