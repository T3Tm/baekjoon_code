#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
	https://www.acmicpc.net/problem/22943
	22943�� ��

	0~9���� k������ ���ڸ� �� ������ ����Ͽ� ���� �� �ִ� �� �� �Ʒ��� ������ ��� �����ϴ� ���� ���� ����
	1������ ����


	�� �տ��� 0�� �� �� ����.
	1. ���� �ٸ� �� ���� �Ҽ��� ������ ��Ÿ�� �� �ִ� ���
		���� �ٸ�
	2. M���� ������ �������� ���� ������ ���� ���� �ΰ��� �Ҽ��� ���� ���
	9��� ���� 3*3 �̶�� �Ҽ��� ���̴�.

	���� ���) k�� 1�̰� M�� 11�� ���
	0~9
	1<=k<=5
	2<=M<=10^9 10��

	0���� 9���� 5������ ���ڸ� �� ���� ����Ͽ� ���� �� �ִ� ����.

	��Ʈ��ŷ����

	[] [] [] [] []
	9  9  8  7  6

	9*9*8*7*6 �� ����� ������
	�׷� 9*9*8*7*6 �̶�� ��Ʈ��ŷ ����� ������
	�ش��ϴ� ������ n�� if(TwoAddPrime[n] && TwoMulPrime[n])cnt++;
	�� �� ��ó���� ���� O(1)�� �˾Ƴ� �� ����.
	O(1)
	O(1)

	���� �ٸ� �ΰ��� �Ҽ��� ���� ���ϱ�.
	o(n^2) => 4õ���� �����ϸ� ���δٸ� �ΰ��� �Ҽ��� ���� �� ���� �� ����.
	44,930,460

	98765 ��� ���ڰ� ���� �� �ִµ� �ش��ϴ� ���ڰ� ���� �ٸ� �ΰ��� �Ҽ��� ������ ��Ÿ������ �˷���

*/
using namespace std;
bool TwoAddPrime[100000];//�ִ� �������� ��.
bool TwoMulPrime[100000];
int n, k;
long long cnt;
vector<int>primes;//�Ҽ��� �־����
bool prime[100000] = { true,true };//�Ҽ����� Ȯ��
pair<int, int>startend[5] = { {1,9},{0,9},{0,9},{0,9},{0,9} };
bool avail[10];
void GetNumber(int number, int depth) {
	if (depth == n) {
		if (TwoAddPrime[number]) {
			while (number % k == 0) {
				number /= k;
			}
			if (TwoMulPrime[number])cnt++;
		}
		return;
	}
	for (int i = startend[depth].first; i <= startend[depth].second; i++) {
		if (!avail[i]) {
			avail[i] = true;
			GetNumber(number * 10 + i, depth + 1);
			avail[i] = false;
		}

	}
}
int main() {
	fast;
	cin >> n >> k;
	for (int i = 2; i * i <= 100000; i++) {
		if (!prime[i])
			for (int j = i * i; j <= 100000; j += i) {
				prime[j] = true;
			}
	}
	for (int i = 2; i <= 98765; i++) {//�Ҽ��� �־����
		if (!prime[i])primes.push_back(i);
	}
	for (int i = 0; i < 9480; i++) {
		for (int j = 0; j < 9480; j++) {
			if (i != j) {//���� ������ �ȵ�.
				long long add = primes[i] + primes[j];
				if (add < 100000) {
					TwoAddPrime[add] = true;
				}
			}
			long long value = primes[i] * (long long)primes[j];
			if (value < 100000) {
				TwoMulPrime[value] = true;
			}
		}
	}
	GetNumber(0, 0);
	cout << cnt;
	return 0;
}

