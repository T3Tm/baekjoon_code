#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2800
	2800번 괄호 제거
*/
using namespace std;
struct loc {
	int front, back;
};
stack<int>bracket;//괄호 idx 넣기
vector<loc>brackets;
set<string>result;
int main() {//해당하는 최소에 
	fast;
	string temp;
	cin >> temp;

	for (int idx = 0; idx < temp.size(); idx++) {
		auto& value = temp[idx];
		if (value == '(') {
			bracket.push(idx);
		}
		else if (value == ')') {
			brackets.push_back({ bracket.top(),idx });
			bracket.pop();
		}
	}
	for (int i = 1; i <= (int)brackets.size(); i++) {
		vector<int>pick((int)brackets.size() - i, 0);
		for (int j = 0; j < i; j++)pick.push_back(1);//뽑기 횟수
		do {
			set<int>dont;
			for (int i = 0; i < pick.size(); i++) {
				if (pick[i]) {
					dont.insert(brackets[i].front);
					dont.insert(brackets[i].back);
				}
			}
			string t;
			for (int z = 0; z < temp.size(); z++) {
				if (dont.find(z) == dont.end()) {
					t.push_back(temp[z]);
				}
			}
			result.insert(t);
		} while (next_permutation(pick.begin(), pick.end()));
	}
	for (auto& value : result) {
		cout << value << endl;
	}
	return 0;
}