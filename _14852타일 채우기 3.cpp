#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/14852
	타일 채우기 3
	2*n 크기의 벽을 2*1 , 1*2 , 1*1 
	크기의 타일로 채우는 경우의 수를 구해보자.
    일반적으로 생각하면
    2*dp[i-1] + 3*dp[i-2] 이게 점화식임
    근데 i-3 으로 가보면 
    새로운 타일 채울 수 있음

    i-4도 새로운 타일 채울 수 있음
    근데 그게 2개씩 경우의 수가 나옴
    그래서 
    점화식은 이것이다.
    2*dp[i-1] + 3*dp[i-2] + 2*sum(dp[:i-3])
    
    새로운 타일의 경우의 수 2개씩 계산 해줘야함.
*/
long long dp[1000001][2];
int main() {
	fast;
	int n;
	cin >> n;
	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[2][1] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i][1]=(dp[i-3][0]+dp[i-1][1]) % 1000000007;
		dp[i][0]=(3*dp[i-2][0] + 2 * dp[i - 1][0]+2*dp[i][1]) % 1000000007;
	}
	cout << dp[n][0];
	return 0;
}