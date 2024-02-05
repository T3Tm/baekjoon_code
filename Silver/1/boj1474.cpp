#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1474
	1474번 밑 줄
	A공간B공간C공간D공간E공간F
	라고 돼있을 때 공간에 _가 들어갈 것이다.

	A_BCDEF 1에 넣을 때는
	AB_CDEF 2
	ABC_DEF 3
	ABCD_EF 4
	ABCDE_F 5

	라고 해서
	sort 해버린다.
*/
using namespace std;
int n, m;
vector<string>words;
vector <pair< string, int>> order;
vector<int>underbarCnt;
int prelen = 0;
int main() {
	fast;
	cin >> n >> m;
	underbarCnt.resize(n + 2, 0);
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		prelen += (int)temp.size();
		words.push_back(temp);
	}

	for (int i = 1; i <= n - 1; i++) {
		string temp;
		for (int j = 0; j < n; j++) {
			if (j == i)temp.push_back('_');
			temp.append(words[j]);
		}
		order.push_back({ temp,i });
	}
	sort(order.begin(), order.end());
	int idx = 0;
	while (prelen++ != m) {
		underbarCnt[order[idx++].second]++;//갯수 늘려주기
		if (idx == n - 1)idx = 0;
	}
	for (int idx = 0; idx < n; idx++) {
		cout << words[idx];
		for (int i = 0; i < underbarCnt[idx + 1]; i++) {
			cout << '_';
		}
	}
	return 0;
}