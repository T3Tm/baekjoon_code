#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17103
	골드바흐 파티션
	0.5 초	512 MB
	
	2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다.

	짝수 N을 두 소수의 합으로 나타내는 것을 골드바흐 파티션이라고 한다.
	짝수 N이 주어졌을 때 파티션의 개수를 구해보자.

	두 소수의 순서만 다른 것은 같은 파티션이다. 
	예를 들어) 2,17  // 17,2 는 같은 파티션이다.
	nloglogn 이면
*/
using namespace std;
int dp[10000001];
int main() {
	fast;
	dp[0] = dp[1] = 1;
	for (int i = 2; i * i <= 1000000; i++) {
		if (!dp[i]) {
			for (int j = i * i; j <= 1000000; j += i)dp[j] = 1;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		//갯수 세기
		int count = 0;
		int n;// 숫자 받기
		cin >> n;
		for (int i = n / 2; i >= 2; i--) {
			if (!dp[i] && !dp[n - i])count++;
		}
		cout << count << endl;
	}
	return 0;
}