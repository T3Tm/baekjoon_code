#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cout.tie(nullptr),cin.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2553
	2553�� ������ ���丮�� ��
	0�� �ƴ� ���� ���� �ڸ� ���� ����Ͽ��� �ȴ�.
*/
using namespace std;
int n;
long long answer = 1;
int main() {
	fast;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		answer *= i;
		while (!(answer % 10)) {
			answer /= 10;
		}
		answer %= 100000000;
	}
	cout << answer % 10;
	return 0;
}