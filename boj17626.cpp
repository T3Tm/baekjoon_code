#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
* https://www.acmicpc.net/problem/17626
* 17626번 Four Squares
*
* 223 << 49729
*/
using namespace std;
int main() {
	fast;
	int n; cin >> n;
	int dp[50002] = { 0 };
	for (int i = 1; i <= 223; i++) {//일단 제곱수들은 최소로 채운다.
		dp[i * i] = 1;
	}
	for (int i = 1; i <= 223; i++) {
		for (int j = i * i; j <= 50000; j++) {
			if (dp[j] == 0)dp[j] = dp[j - i * i] + 1;
			else dp[j] = min(dp[j], dp[j - i * i] + 1);
		}
	}
	cout << dp[n];
	return 0;
}