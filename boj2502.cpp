#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2502
	2502번 떡 먹는 호랑이
	할머니가 호랑이에게 떡을 주어야 산을 넘어갈 수 있다.
	
	어제 받은 떡의 개수와 그저께 받은 떡의 개수를 더한만큼 떡을 받아야한다. < 피보나치?
	

	총 k개를 받았고 n일동안 산을 넘었다
	1,2,3,4,n-1일까지인데
	a 0,0 b,a+b,a+2b,2a+3b,3a+5b,5a+8b,8a+13b,13a+21b,21a+34b

	3a+5b =41인 것을 알아내는 것이네?
	
*/
using namespace std;
int d, k;
int dp[2][33];//a와 b의 계수를 각각 정리해보자.
int main() {
	fast; cin >> d >> k;
	dp[0][1] = 1;
	dp[1][2] = 1;
	for (int i = 3; i <= d; i++) {
		dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
		dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
	}
	//각 계수를 알아냈기에 그 계수에서 부정방정식 풀면됨.
	for (int A = 1;; A++) {// B가 A보다 커야됨.
		for (int B = A+1; dp[0][d] * A + dp[1][d] * B <= k; B++) {
			if (dp[0][d] * A + dp[1][d] * B == k) {
				cout << A << endl << B;
				exit(0);
			}
		}
	}
	return 0;
}