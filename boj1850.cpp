#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1850
	1850�� �ִ�����
*/
using namespace std;
using lld = long long;
lld a, b;
lld gcd(lld t1, lld t2) {
	return (t1 % t2 == 0 ? t2 : gcd(t2, t1 % t2));
}
int main() {
	fast;
	cin >> a >> b;//a�� ���� ��ŭ 1�� �ִ� ���̰� b�� ���� ��ŭ 1�� �ִ� ���̴�.
	//�ִ� �������� ���� ���� 
	if (a < b)swap(a, b);
	string temp(gcd(a, b), '1');
	cout << temp;
	return 0;
}