#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
void back(int depth, vector<char>& result, vector<int>& idxs) {
	if (depth == idxs.size()) {//result가 온전한 쌍인지 체크만 해주면됨.
		stack<char>t;
		for (int i = 0; i < result.size(); i++) {
			if (result[i] == '(') {
				t.push('(');
			}
			else {
				if (t.empty())return;//못 만듦
				else t.pop();
			}
		}
		if (!t.empty())return;//못 만듦
		for (auto C : result)cout << C;
		exit(0);
	}
	result[idxs[depth]] = '(';
	back(depth + 1, result, idxs);
	result[idxs[depth]] = ')';
	back(depth + 1, result, idxs);
}
int main() {
	fast;
	int n; cin >> n;
	string tmp; cin >> tmp;
	vector<char>T;
	vector<int>idxs;//G부분 다 갖고 오기.
	for (int i = 0; i < tmp.size(); i++) {
		T.push_back(tmp[i]);
		if (tmp[i] == 'G')idxs.push_back(i);
	}
	back(0, T, idxs);
	return 0;
}