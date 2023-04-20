#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/13301
	13301번 타일 장식물

*/
using namespace std;
long long dp[82]{ 1,1 };
int n;
int main() {
	fast; cin >> n;
	for (int i = 2; i <= n; i++)dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n] * 2 + dp[n - 1] * 2;
	return 0;
}