#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/9507
	9507번 Generations of Tribbles
	n == 0 || n == 1  : 1
	n == 2 : 2
	n == 3 : 4

*/
using namespace std;
long long dp[69]{ 1,1,2,4 };
int main() {
	fast;
	int t; cin >> t;
	for (int i = 4; i <= 67; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	while (t--) {
		int n; cin >> n;
		cout << dp[n]<<endl;
	}
	return 0;
}