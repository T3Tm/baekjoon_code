#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/9251
	9251번 LCS	
	a,b랑 얼마나 겹치는 지 알아내기.
	
	Long common sebsequence
	a의 i번째 문자랑
	b의 j번째 문자랑 같은지 확인
	
	dp[i][j] = dp[i-1][j-1]+1;//a의 i문자와 b의 j 문자가 같으면
	아니면 dp[i][j]=max(dp[i-1] 이 값.
*/
using namespace std;
int dp[1002][1002];
int main() {
	fast;
	string a, b; cin >> a >> b;
	for (int i = 1; i <= (int)a.size(); i++) {//a문자열 만큼
		for (int j = 1; j <= (int)b.size(); j++) {//b 문자열 만큼
			if (a[i-1] == b[j-1]) {
				dp[i][j] =max( dp[i - 1][j - 1]+1,dp[i][j-1]);//문자 더하기
			}
			else {//다른 다른 것은 그 전에 있던 값에서 보자
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[a.size()][b.size()];
	return 0;
}