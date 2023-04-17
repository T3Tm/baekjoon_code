#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1717
	1717번 집합의 표현

	union find 문제네
	
*/
using namespace std;
int n, m;
int parent[1000002];
int Search(int a) {
	if (a == parent[a])return a;
	return parent[a] = Search(parent[a]);
}
void merge(int a,int b) {//a집합과 b집합을 합친다.
	a = Search(a);
	b = Search(b);
	//더 큰 것의 어머니를 작은 애로 만든다.
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
		if (!c) {//a집합과 b집합을 합치기
			merge(a, b);
		}
		else {//a와 b가 같은 집합인지 확인하기.
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