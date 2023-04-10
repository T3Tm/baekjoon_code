#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1517
	1517�� ���� ��Ʈ
	���� ��Ʈ���� A,B�� ���ϴ� ��� B��� �κп��� temp �� ��ĥ �� B�� ���� ���� ���
	�󸶳� ���� ������ Ȯ���Ѵ�. �׷��� �� Ƚ���� ����.
*/
using namespace std;
int n;
vector<int>arr;
long long answer;
void merge(int s1,int e1,int s2,int e2) {//
	vector<int> temp;//�ϴ� ��Ƴ��� arr���ٰ� �־ ��������.
	int t1 = s1, t2 = s2;
	for (; t1 <= e1 && t2 <= e2;) {//t1�� t2�� ���ؼ� �ִ´�.
		if (arr[t1] > arr[t2]) {//�ڿ� �ִ� ���� �� �۱⿡ t2�� ������ ���� ���ߵ�.
			temp.push_back(arr[t2++]);
			answer += (e1 - t1 + 1);
		}
		else {//���� ������� �׳� ���� �ƾ���. swap ���ص� ��.
			temp.push_back(arr[t1++]);
		}
	}
	while (t1 <= e1) {//�տ� �ִ� ���ڸ� ���� �� �־���.
		temp.push_back(arr[t1++]);
	}
	while (t2 <= e2) {
		temp.push_back(arr[t2++]);
	}
	int idx = 0;
	for (int i = s1; i <= e2; i++) {//�ش� ���� ���� arr�� �־����.
		arr[i] = temp[idx++];
	}
}
void mergesort(int start,int end) {//start���� end���� �󸶳� �ɸ����� Ȯ���Ѵ�.
	if (start < end) {//1������ ũ�ų� ������
		mergesort(start, (end + start) / 2);
		mergesort((end + start) / 2 + 1, end);
		merge(start, (end + start) / 2, (end + start) / 2 + 1,end);
	}
}
void solve() {
	mergesort(0, n - 1);
	cout << answer;
}
int main() {
	fast;
	cin >> n;
	arr.resize(n,0);
	for (int i = 0; i < n; i++)cin >> arr[i];
	solve();
	return 0;
}