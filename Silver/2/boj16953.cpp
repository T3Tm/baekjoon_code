#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16953
	16953�� A -> B

	A���� B�� ������� �ϴ� ��
	������ 2�� ���ϴ� ����
	1�� ���� �����ʿ� �߰��ϴ� ������ �ִ�.
	B���� 2�� ������. �� ������ 1�� �ִ� ������ ���� ���̴�.

	�ֳĸ� ������ ������ ���� 2���ϱ� or 1���� �̴ϱ�.
*/
using namespace std;
long long a, b, answer;
int main() {
	fast; cin >> a >> b;
	while (b != a && b) {
		if (b % 2 && b % 10 == 1)b /= 10;//���� ������ 10 ���ֱ�
		else if (b % 2) {
			cout << -1; exit(0);
		}
		else b /= 2; //2�� ������
		answer++;
	}
	answer++;
	if (!b)answer = -1;
	cout << answer;
	return 0;
}