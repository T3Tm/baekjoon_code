#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cout.tie(nullptr),cin.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2980
	2980�� ���ο� ��ȣ��
	����Ž���ص� ��.
*/
using namespace std;
int n, l;
struct my {
	int time, x;
};
int main() {
	fast;
	cin >> n >> l;
	my t = { 0,0 };//���� �ð��� ��ǥ �˰� �ֱ�.
	for (int i = 0; i < n; i++) {
		int d, r, g;
		cin >> d >> r >> g;
		t.time += (d - t.x);//���� ���� �ð��� �߰��� �ֱ�.
		if (t.time % (r + g) + 1 > r) {//���� ���� �ð��� �ǳ� �� �ִ��� �Ǵ��ؾߵ�.
			t.time++;//�ǳ� �� ����.
		}
		else {//�� �ǳʴϱ� 
			t.time += r - (t.time % (r + g)) + 1;//�ȵǴ� �ð� ��ŭ ���ϱ�.
		}
		t.x = d + 1;//�ǳʱ�.
	}
	if (t.x < l) {
		t.time += (l - t.x);
	}
	cout << t.time;
	return 0;
}