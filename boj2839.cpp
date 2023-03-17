#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl "\n"
/*
	https://www.acmicpc.net/problem/2839
	2839¹ø ¼³ÅÁ ¹è´Þ
*/

using namespace std;
int dp[5002], n;
void Count(int value) {
	for (int i = value; i <= n; i++) {
		if (dp[i - value] != -1 && dp[i] == -1) {
			dp[i] = dp[i - value] + 1;
		}
		else if (dp[i - value] != -1) {
			dp[i] = min(dp[i - value] + 1, dp[i]);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)dp[i] = -1;
	Count(3);
	Count(5);
	cout << dp[n];
	return 0;
}