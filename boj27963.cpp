#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/27963
	27963�� �ձ� ��ȭ
	������ 100���� �����ϸ�
	d,D �̷��� ���� ��
	100-x1/d = v1
	x2/D = v2
	100/v1+v2 =>
*/
int main() {
	fast;
	int d1, d2, x; cin >> d1 >> d2 >> x;
	if (d1 > d2)swap(d1, d2);
	double r = 100 / (((100 - x) / (double)d1) + (double)x / d2);
	cout.precision(13);
	cout << r;
	return 0;
}