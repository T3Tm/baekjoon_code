#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2217
	2217�� ����
	1. ������ �ּҰ� * ���� ���� �� �������� �Ǻ��ؾߵ��� �ʳ�
	2.
*/
using namespace std;
int n;
int arr[100002];
int main() {//�ش��ϴ� �ּҿ� 
	fast;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	int maxvalue = 0;
	for (int i = 0; i < n; i++) {
		maxvalue = max(maxvalue, arr[i] * (n - i));
	}
	cout << maxvalue;
	return 0;
}