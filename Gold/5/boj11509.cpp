#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/11509
	풍선 맞추기
	lcs << 문제네요.
	그리디 + Dp 문제
*/
using namespace std;
int n;
vector<int>ballons;
vector<int>dp(1000001,0);
int main() {
	fast;
	cin >> n;
	ballons.resize(n, 0);
	for (int i = 0; i < n; i++)cin >> ballons[i];
	int cnt = 1;
	dp[ballons[0]]++;
	for (int i = 1; i < n; i++) {
		if (!dp[ballons[i] + 1])cnt++;
		else dp[ballons[i] + 1]--;
		dp[ballons[i]]++;
	}
	cout << cnt;
	return 0;
}