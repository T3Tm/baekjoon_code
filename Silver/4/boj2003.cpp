#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/2003
   2003�� ������ �� 2

   �������� ����.
*/
using namespace std;
int n, m;
int arr[10002];
int main() {
	fast;
	cin >> n >> m;
	int left = 0, right = 0;
	for (int i = 0; i < n; i++)cin >> arr[i];
	long long my_m = arr[0];//�ʱ갪 ����
	long long cnt = 0;
	while (left <= right) {
		if (my_m >= m) {//ũ�ų� ������ ���༭ �ٸ� �ֵ��� ���� �� �ֵ���
			if (my_m == m)cnt++;
			my_m -= arr[left++];//left�� �ø��� ���� ���� ���ش�
		}
		else {//m���� �۱� ������ right�� �ϳ��� �ø��鼭 sum�� ����
			right++;//���̻� right�� �ø��� ���ϸ� �׳� ���� ������. �� �׷��� ������ right�� �� �ø��� ������.
			if (right >= n)break;
			my_m += arr[right];
		}
		if (left > right) {
			swap(left, right);
			left++;
			if (right >= n)break;
			my_m += arr[right];
		}
	}
	cout << cnt;
	return 0;
}

