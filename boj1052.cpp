#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1052
	1052�� ����
	N���� ������ �ְ� ���� ���Ѵ�� ���� �� �ִ�.
	��� �������� ���� 1L ����.
	�� ���� K���� ������ �ű� �� �ִ�.

	1. ���� ���� ���� ����ִ� ���� �� ���� ����. �� ���� �� ���� ������
	�ٸ� �� �ʿ� �ִ� ���� ��� �״´�. (�� ����� �ʿ��� ��ŭ ��� �Ѵ�.)

	n,k ���� ��
	n>k�϶��� ��� �ϸ� �Ǵ� �ų�?
	if n%2 �̸� 1�� ���� n/=2 �ϸ� �ȴ�. �״��� +1 �ϸ��.
	�ƴϸ� n/=2;
	3 �̸�
	1  �� �ǰڴ�.
	����
*/
using namespace std;
long long answer;
vector<long long>modwater;//���� ����
int main() {
	fast;
	int n, k; cin >> n >> k;
	long long water = 1;//���� ���� ���� ���.
	while (n) {
		if (n % 2) {
			modwater.push_back(water);//������ ���� �׳� ������.
			n = (n - 1) / 2;//�� ���� ���� 1L �̴�. �߰� �߰� ������ ������ ������ �˾ƾ� �ɵ�.
		}
		else n /= 2;
		water <<= 1;//2�� �ž��Ѵ�. 
	}
	// modwater[i]-modwater[i-1]�� �ʿ���. 
	if (modwater.size() > k) {//�׷� mod�� �ִ� ������ ������ ��ġ�ؼ� k�� ����������.
		long long len = modwater.size();
		long long watercnt = len;
		for (int i = 1; i < len && watercnt>k; i++) {//i+1��°
			answer += modwater[i] - modwater[i - 1];//1�� ���� �����ֱ�
			modwater[i] <<= 1;//2�����ֱ�.//3������ 2������.
			watercnt--;//�� �� ����Ǹ� 2���� 1���� ��.
		}
	}
	cout << answer;
	return 0;
}