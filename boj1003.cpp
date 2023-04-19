#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1003
	1003번 피보나치 함수.
*/
using namespace std;
struct mydp {
	long long zero, one;
	const mydp operator +(const mydp& a) {
		mydp temp = { zero + a.zero,one + a.one };
		return temp;
	}
};
mydp dp[44] = { {1,0},{0,1} };//각 자신의 숫자에서 0의 갯수랑 1의 갯수를 돌려주면 된다
mydp fibonacci(int n) {
	if (n == 0)return dp[0];
	else if (n == 1)return dp[1];
	mydp& ret = dp[n];
	if (ret.zero || ret.one)return ret;
	ret = { 0,0 };//0,0개로 초기화 한 뒤에
	return ret = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	fast;
	fibonacci(40);
	int t; cin >> t;
	while (t--) {
		int num; cin >> num;
		cout << dp[num].zero << ' ' << dp[num].one << endl;
	}
	return 0;
}