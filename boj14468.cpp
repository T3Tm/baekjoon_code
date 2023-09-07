#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'

/*
	https://www.acmicpc.net/problem/14468
	14468�� �Ұ� ���� �ǳʰ� ���� 2
*/
using namespace std;
int main() {
	fast; set<pair<int, int>>g;
	string a; cin >> a;
	int idx[27]{};
	int cnt[27]{};
	for (int i = 0; i < a.size(); i++) {
		cnt[a[i] - 'A']++;
		if (cnt[a[i] - 'A'] == 2) {
			for (int j = idx[a[i] - 'A'] + 1; j < i; j++) {
				if (cnt[a[j] - 'A'] == 1)g.insert({ a[i],a[j] });
			}
		}
		idx[a[i] - 'A'] = i;//idx
	}
	cout << g.size();
}