#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/9251
	9251�� LCS	
	a,b�� �󸶳� ��ġ�� �� �˾Ƴ���.
	
	Long common sebsequence
	a�� i��° ���ڶ�
	b�� j��° ���ڶ� ������ Ȯ��
	
	dp[i][j] = dp[i-1][j-1]+1;//a�� i���ڿ� b�� j ���ڰ� ������
	�ƴϸ� dp[i][j]=max(dp[i-1] �� ��.
*/
using namespace std;
int dp[1002][1002];
int main() {
	fast;
	string a, b; cin >> a >> b;
	for (int i = 1; i <= (int)a.size(); i++) {//a���ڿ� ��ŭ
		for (int j = 1; j <= (int)b.size(); j++) {//b ���ڿ� ��ŭ
			if (a[i-1] == b[j-1]) {
				dp[i][j] =max( dp[i - 1][j - 1]+1,dp[i][j-1]);//���� ���ϱ�
			}
			else {//�ٸ� �ٸ� ���� �� ���� �ִ� ������ ����
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[a.size()][b.size()];
	return 0;
}