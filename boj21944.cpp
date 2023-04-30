#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/21944
	21944번 문제 추천 시스템 Version 2

	recommend G x
		x가 1이면 알고리즘 분류가 G인 문제 중 가장 어려운 문제 번호를 출력한다.

		x -1인 경우 알고리즘 분류가 G인 문제중 가장 쉬운 문제 번호를 출력한다.

	recommend2 x
		x가 1이면 알고리즘 분류 상관없이 가장 어려운 문제 번호를 출력한다.

		x가 -1이면 알고리즘 분류 상관없이 가장 쉬운 문제 번호를 출력한다.

	recommend3 x L
		x가 1인 경우 난이도가 L보다 크거나 같은 문제중 가장 쉬운 문제 번호를 출력한다.

		조건을 만족하는 번호가 없으면 -1을 출력한다.

		x가 -1인 경우 난이도가 L보다 작은 문제중 가장 어려운 문제 번호를 출력한다.

		조건을 만족하는 번호가 없으면 -1을 출력한다.

	add P L G

		난이도가 L이고 알고리즘이 G인 P문제 번호를 추가한다.

	solved P

		추천 문제 리스트에서 문제 번호 P를 제거한다.
*/
using namespace std;
map<int, set<pair<int, int>>>recommend;//알고리즘 분류 : {난이도, 번호}
int n;
int diff[100002];//해당 문제의 난이도 저장
void solve() {
	int m; cin >> m;
	while (m--) {
		string cmd; cin >> cmd;
		if (cmd[0] == 'a') {//a O(logn*logn)
			int p, l, g; cin >> p >> l >> g;
			diff[p] = l;
			recommend[g].insert({ l,p });
		}
		else if (cmd[0] == 's') {//solve O(100*logn)
			int p; cin >> p;
			auto it = recommend.begin();
			while (it != recommend.end()) {
				if ((*it).second.find({ diff[p],p }) != (*it).second.end()) {//찾아냄
					break;
				}
				it++;
			}
			(*it).second.erase({ diff[p],p });//제거하기
			diff[p] = 0;
		}
		else if (cmd[0] == 'r') {
			if (cmd.back() == 'd') {//recommend 1
				int g, x; cin >> g >> x;
				if (x == 1) {
					auto it = prev(recommend[g].end());//lgn
					cout << (*it).second << endl;
				}
				else {
					auto it = recommend[g].begin();//lgn
					cout << (*it).second << endl;
				}

			}
			else if (cmd.back() == '2') {//recommend 2
				int x; cin >> x;
				auto it = recommend.begin();
				int indiff, answer;
				if (x == 1) {
					indiff = 0, answer = 0;
					while (it != recommend.end()) {
						if (!(*it).second.empty()) {
							auto inner = prev((*it).second.end());//가장 어려운
							if (indiff < (*inner).first || (indiff == (*inner).first && answer < (*inner).second)) {
								indiff = (*inner).first;
								answer = (*inner).second;
							}
						}
						it++;
					}
				}
				else {
					indiff = 101, answer = 100001;
					while (it != recommend.end()) {
						auto inner = (*it).second.begin();//num
						if (inner == (*it).second.end());
						else if (indiff > (*inner).first || (indiff == (*inner).first && answer > (*inner).second)) {
							indiff = (*inner).first;
							answer = (*inner).second;
						}
						it++;
					}
				}
				cout << answer << endl;
			}
			else {//recommend 3
				int x, l; cin >> x >> l;
				auto it = recommend.begin();
				int indiff, answer = -1;
				if (x == 1) {//l보다 크거나 같은 문제 중 가장 쉬운 문제
					indiff = 101;
					while (it != recommend.end()) {//l 난이도-1
						auto inner = (*it).second.lower_bound({ l,1 });//난이도 l에서 1
						if (inner == (*it).second.end());
						else if ((*inner).first >= l && indiff > (*inner).first || (indiff == (*inner).first && answer > (*inner).second)) {
							indiff = (*inner).first;
							answer = (*inner).second;
						}
						it++;
					}
				}
				else {//l보다 작은 문제중 가장 어려운 문제 번호
					indiff = 0;
					while (it != recommend.end()) {
						if (!(*it).second.empty()) {
							auto inner = prev((*it).second.lower_bound({ l,1 }));
							if (inner == (*it).second.end());
							else if ((*inner).first < l && indiff < (*inner).first || (indiff == (*inner).first && answer < (*inner).second)) {
								indiff = (*inner).first;
								answer = (*inner).second;
							}
						}
						it++;
					}
				}
				cout << answer << endl;
			}
		}
	}
}
int main() {
	fast; cin >> n;
	for (int i = 0; i < n; i++) {
		int p, l, g; cin >> p >> l >> g;
		diff[p] = l;//해당 문제에 l난이도로 저장
		recommend[g].insert({ l,p });
	}
	solve();
	return 0;
}