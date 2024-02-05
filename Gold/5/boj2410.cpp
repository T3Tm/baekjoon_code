#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2410
	2410번 2의 멱수의 합

	2^k 수로 표현한다.

	1,2,4
	1,2,4,8
	1,2,4,8,16
	1,2,4,8,16,32 으로 표현하면 된다.

	n==1
	1
	n==2
	1+1
	2
	n==3
	1+1+1
	1+2
	n==4
	1+1+1+1
	1+2+1
	2+2
	n==5
	1+1+1+1+1
	1+2+1+1
	2+2+1
	1+4
*/
using namespace std;
int n, dp[1000002]{ 1 };
vector<int>token;
int main() {
	fast; cin >> n;
	int num = 1;
	for (int i = 2; num <= n; i++) {
		token.push_back(num);
		num *= 2;
	}
	for (auto value : token) {
		for (int i = value; i <= n; i++) {
			dp[i] = (dp[i] + dp[i - value]) % 1000000000;
		}
	}
	cout << dp[n];
	return 0;
}