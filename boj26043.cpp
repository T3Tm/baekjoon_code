#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/26043
	26043번 식당 메뉴
	2개의 메뉴가 제공된다.
	식사 준비되는 n개의 정보가 저장된 S가 주어짐.
	S에 저장된 첫 번째 정보부터 N번째 정보까지 순서대로 처리 후,
	본인이 좋아하는 메뉴를 먹은 학생 목록 A
	본인이 좋아하지 않는 메뉴를 먹은 학생 목록 B
	식당에 왔는데 못 먹은 애 학생들 C를 출력하자.

	1. 1 a b => a라는 애가 b의 음식을 좋아한다.
	2. 2 b => b인 식사 1인분이 준비돼서 입장하시오.
*/
using namespace std;
int n;
deque<pair<int, int>>stand;
vector<int>Nomatch;
vector<int>match;
int main() {//해당하는 최소에 
	fast;
	cin >> n;
	while (n--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int a, b;
			cin >> a >> b;
			stand.push_back({ a,b });//a라는 학생이 b음식을 먹고 싶어함.
		}
		else {
			int b;
			cin >> b;
			auto value = stand.front(); stand.pop_front();
			if (b != value.second) {
				Nomatch.push_back(value.first);
			}
			else {
				match.push_back(value.first);
			}
		}
	}
	if (match.empty()) {//비어있으면 None 출력
		cout << "None" << endl;
	}
	else {
		sort(match.begin(), match.end());
		for (auto& value : match) {
			cout << value << " ";
		}
		cout << endl;
	}
	if (Nomatch.empty()) {//비어있으면 None 출력
		cout << "None" << endl;
	}
	else {
		sort(Nomatch.begin(), Nomatch.end());
		for (auto& value : Nomatch) {
			cout << value << " ";
		}
		cout << endl;
	}
	if (stand.empty()) {//비어있으면 None 출력
		cout << "None" << endl;
	}
	else {
		sort(stand.begin(), stand.end());
		for (auto& value : stand) {
			cout << value.first << " ";
		}
		cout << endl;
	}
	return 0;
}