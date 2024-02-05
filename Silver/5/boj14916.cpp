#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/14916
	거스름돈

	거슬러 줄 수 없으면 -1
	손님이 2원짜리랑 5원짜리로 거스름돈을 달라고 함.

	DP + 그리디 문제인 것을 확인
*/
using namespace std;
int main() {
	fast;
	int n, answer = 0, dp[100002];
	cin >> n;
	dp[0] = 0;
	int last = 100000;
	for (int i = 1; i <= last; i++)dp[i] = -1;
	for (int i = 5; i <= last; i += 5)dp[i] = dp[i - 5] + 1;
	for (int i = 2; i <= last; i++) {
		if (dp[i-2] == -1)continue;
		if (dp[i] == -1)dp[i] = dp[i - 2] + 1;
		else dp[i] = min(dp[i - 2] + 1,dp[i]);
	}
	cout << dp[n];
	return 0;
}