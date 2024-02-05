#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1446
	1446�� ������

	Dų�ι��� ������ ��ӵ��θ� ������.
	������ ����.
	�Ϲ������̴�.

	�ش��ϴ� ��ġ���� �ּ� �Ÿ��� ����Ѵ�.
	���� ���)
	0 50 10
	0 50 20 �̸�
	50������ 10�̸� �� �� �ִ�.
	50 100  < 100������ 20�̸� �� �� �ִ�.
	0~50 3
	0~49 1
	49~50 1 => �� 2 50�� �����ϴµ� 2�� �� �� ����.
	�����ϴ� ���� ��� �Ǵ����� �߿��ѵ�

*/
using namespace std;
int n, d;//������ ���� ,������ ����
int arr[10002];
int dp[10002];
map<int, map<int, int>>highpass;
int main() {//�ش��ϴ� �ּҿ� 
	fast;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int a, b, c;//���� ,��,����
		cin >> a >> b >> c;
		if (highpass.find(b) != highpass.end() && highpass[b].find(a) != highpass[b].end()) {
			highpass[b][a] = min(highpass[b][a], c);
		}
		else {
			highpass[b][a] = c;
		}
	}
	for (int i = 1; i <= d; i++) {
		if (highpass.find(i) != highpass.end()) {//������ ����
			for (auto& value : highpass[i]) {
				if (dp[i] != 0) {
					dp[i] = min({ dp[i],dp[i - 1] + 1, dp[value.first] + value.second });
				}
				else {
					dp[i] = min(dp[i - 1] + 1, dp[value.first] + value.second);
				}

			}
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}
	cout << dp[d];
	return 0;
}