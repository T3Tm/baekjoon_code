#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1717
	1717�� ������ ǥ��

	union find ������
	
*/
using namespace std;
int n, m;
int parent[1000002];
int Search(int a) {
	if (a == parent[a])return a;
	return parent[a] = Search(parent[a]);
}
void merge(int a,int b) {//a���հ� b������ ��ģ��.
	a = Search(a);
	b = Search(b);
	//�� ū ���� ��Ӵϸ� ���� �ַ� �����.
	if (a > b)swap(a, b);
	parent[b] = a;
}
void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}
void solve() {
	init();
	while (m--) {
		int c, a, b; cin >> c >> a >> b;
		if (!c) {//a���հ� b������ ��ġ��
			merge(a, b);
		}
		else {//a�� b�� ���� �������� Ȯ���ϱ�.
			if (Search(a)== Search(b))cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
int main() {
	fast;
	cin >> n >> m;
	solve();
	return 0;
}