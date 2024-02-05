#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17484
	17484번 진우의 달 여행 (Small)
*/
using namespace std;
int main() {
	fast;
	int n, m,answer=0x3f3f3f3f; cin >> n >> m;
	int arr[8][8]{ 0 };
	int dp[8][8][3]{ 0 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			for (int z = 0; z < 3; z++)dp[i][j][z] = 1000;//최댓값 설정
		}
	}
	for (int i = 1; i <= n; i++) {//n행 까지 dp 설정
		for (int j = 1; j <= m; j++) {//m개의 dp 테이블 설정 0이면 오른쪽에서 온 것이고, 1이면 직진에서 온 것 2이면 왼쪽에서 온 것임.
			//각 지점에서 뻗어나가는 거 지정해줘야 됨.
			if (j - 1 >= 1) dp[i][j][0] = min({ dp[i][j][0], dp[i - 1][j][1] + arr[i][j], dp[i - 1][j-1][2] + arr[i][j] });//0 같은 경우 전에 왼쪽 대각선 말고 올 수 있는 경로 중에 최솟값 담아놓기
			else dp[i][j][0] = min({ dp[i][j][0], dp[i - 1][j][1] + arr[i][j] });//0 같은 경우 전에 왼쪽 대각선 말고 올 수 있는 경로 중에 최솟값 담아놓기
			if (j - 1 >= 1 && j+1<=m) {
				dp[i][j][1] = min({ dp[i][j][1], dp[i - 1][j + 1][0] + arr[i][j], dp[i - 1][j - 1][2] + arr[i][j] });//1 같은 경우 전에 가운데 말고 올 수 있는 경로 중에 최솟값
			}
			else if (j - 1 >= 1) {
				dp[i][j][1] = min({ dp[i][j][1],  dp[i - 1][j - 1][2] + arr[i][j]});
			}
			else if (j + 1 <= m) {
				dp[i][j][1] = min({ dp[i][j][1],dp[i - 1][j + 1][0] + arr[i][j] });
			}
			
			if (j + 1 <=m) dp[i][j][2] = min({ dp[i][j][2], dp[i - 1][j][1] + arr[i][j], dp[i - 1][j + 1][0] + arr[i][j] });//2 같은 경우 전에 오른쪽 대각선 말고 올 수 있는 경로 중에 최솟값
			else dp[i][j][2] = min({ dp[i][j][2], dp[i - 1][j][1] + arr[i][j]});//2 같은 경우 전에 오른쪽 대각선 말고 올 수 있는 경로 중에 최솟값
		}
	}
	for (int i = 1; i <= m; i++)answer = min({ answer, dp[n][i][0], dp[n][i][1], dp[n][i][2] });
	cout << answer;
	return 0;
}