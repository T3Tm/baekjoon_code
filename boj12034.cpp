#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/12034
	12034번 김인천씨의 식료품가게 (Large)
*/
using namespace std;
int main() {
	fast; 
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		int n; cin >> n;
		map<int, int>numinfo;
		for (int j = 0; j < 2*n; j++) {
			int num; cin >> num;
			if (numinfo.find(num) != numinfo.end())numinfo[num]++;
			else numinfo[num] = 1;
		}
		cout << "Case #" << i << ":";
		auto it = numinfo.begin();
		while (it != numinfo.end()) {
			if ((*it).second == 0) {
				it++; continue;
			}
			if (numinfo.find((*it).first / 3 * 4) != numinfo.end()) {
				(*it).second--;
				numinfo[(*it).first / 3 * 4]--;
				cout << " " << (*it).first;
			}
			if (!(*it).second)it++;
		}
		cout << endl;
	}
	return 0;
}