#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/19637
	IF문 좀 대신 써줘

*/
vector<pair<string, int>>condition;
int main() {
	fast;
	int n, m, value,t;
	string word;
	cin >> n >> m;
	t = n;
	while (t--) {
		cin >> word >> value;
		condition.push_back({ word,value });
	}
	while (m--) {//mlogn으로 풀어야 1초 안에 되겠네
		cin >> value;
		int s=0, e =n-1;
		int mid;
		while (s <= e) {
			mid = (s + e) / 2;
			if (value > condition[mid].second) {
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
		cout <<  condition[s].first<< endl;
	}
	return 0;
}