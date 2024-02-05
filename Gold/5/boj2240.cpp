#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2240
	2240번 자두나무
	초마다 두 개의 나무 중 하나에서 열매가 떨어진다.
	
	열매가 떨어지는 순간 자두가 그 나무의 아래에 있으면 열매를 받아 먹을 수 있다.

	자두가 T초 동안 떨어지는데,자두는 최대 W번만 움직이고 싶다.

	매 초마다 어느 나무에서 자두가 떨어질지 정보가 주어진다. 자두가 받을 수 있는 
	자두의 갯수를 구해내라.

	처음은 자두가 1번에 위치해 있다.

	1<=T<=1000 1<=W<=30

	i가 1이면 2번나무
	i가 2이면 1번나무
	i가 3이면 2번나무
	i가 4이면 1번나무
	즉 i가 %2 했을 때 1이면 2번 나무에 있는 것이다.
*/
using namespace std;
int t, w;
int dp[32][1003],arr[1002];
int main() {
	fast; cin >> t >> w;
	for (int i = 1; i <= t; i++) {
		cin >> arr[i];
		dp[0][i] = dp[0][i - 1];//전의 것을 갖고 와서 
		if (arr[i] == 1)dp[0][i]++;//1이면 추가한다. 처음의 위치는 1이기에
	}
	for (int i = 1; i <= w; i++) {//1초이면
		for (int j = 1; j <= t; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i][j - 1]);
			if (i % 2 && arr[j]==2) {//지금 2번 나무임.
				dp[i][j]++;
			}
			else if(i%2==0 && arr[j]==1) {//1번 나무임
				dp[i][j]++;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i <= w; i++) {
		answer = max(answer, dp[i][t]);
	}
	cout << answer;
	return 0;
}