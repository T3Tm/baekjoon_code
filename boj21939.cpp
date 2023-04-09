#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/21939
	21939�� ���� ��õ �ý��� Version 1
*/
using namespace std;
int n, m;
set<pair<int, int>>problems;//������
int arr[100002];
void solve() {
	cin >> m;
	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd[0] == 'r') {//��õ�����~
			int x;
			cin >> x;
			if (x == -1) {
				auto it = problems.begin();
				cout << (*it).second << endl;
			}
			else {
				auto it = problems.end();
				it--;
				cout << (*it).second << endl;
			}
		}
		else if (cmd[0] == 'a') {//�߰��ض�
			int p, l;//���� l�� p
			cin >> p >> l;
			arr[p] = l;
			problems.insert({ l,p });
		}
		else {//Ǯ���~
			int p;
			cin >> p;
			problems.erase({ arr[p],p });
			arr[p] = 0;
		}
	}
}
int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, l;
		cin >> p >> l;
		problems.insert({ l,p });
		arr[p] = l;
	}
	solve();
	return 0;
}