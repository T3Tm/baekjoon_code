#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17484
	17484�� ������ �� ���� (Small)
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
			for (int z = 0; z < 3; z++)dp[i][j][z] = 1000;//�ִ� ����
		}
	}
	for (int i = 1; i <= n; i++) {//n�� ���� dp ����
		for (int j = 1; j <= m; j++) {//m���� dp ���̺� ���� 0�̸� �����ʿ��� �� ���̰�, 1�̸� �������� �� �� 2�̸� ���ʿ��� �� ����.
			//�� �������� ������� �� ��������� ��.
			if (j - 1 >= 1) dp[i][j][0] = min({ dp[i][j][0], dp[i - 1][j][1] + arr[i][j], dp[i - 1][j-1][2] + arr[i][j] });//0 ���� ��� ���� ���� �밢�� ���� �� �� �ִ� ��� �߿� �ּڰ� ��Ƴ���
			else dp[i][j][0] = min({ dp[i][j][0], dp[i - 1][j][1] + arr[i][j] });//0 ���� ��� ���� ���� �밢�� ���� �� �� �ִ� ��� �߿� �ּڰ� ��Ƴ���
			if (j - 1 >= 1 && j+1<=m) {
				dp[i][j][1] = min({ dp[i][j][1], dp[i - 1][j + 1][0] + arr[i][j], dp[i - 1][j - 1][2] + arr[i][j] });//1 ���� ��� ���� ��� ���� �� �� �ִ� ��� �߿� �ּڰ�
			}
			else if (j - 1 >= 1) {
				dp[i][j][1] = min({ dp[i][j][1],  dp[i - 1][j - 1][2] + arr[i][j]});
			}
			else if (j + 1 <= m) {
				dp[i][j][1] = min({ dp[i][j][1],dp[i - 1][j + 1][0] + arr[i][j] });
			}
			
			if (j + 1 <=m) dp[i][j][2] = min({ dp[i][j][2], dp[i - 1][j][1] + arr[i][j], dp[i - 1][j + 1][0] + arr[i][j] });//2 ���� ��� ���� ������ �밢�� ���� �� �� �ִ� ��� �߿� �ּڰ�
			else dp[i][j][2] = min({ dp[i][j][2], dp[i - 1][j][1] + arr[i][j]});//2 ���� ��� ���� ������ �밢�� ���� �� �� �ִ� ��� �߿� �ּڰ�
		}
	}
	for (int i = 1; i <= m; i++)answer = min({ answer, dp[n][i][0], dp[n][i][1], dp[n][i][2] });
	cout << answer;
	return 0;
}