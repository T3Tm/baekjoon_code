#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2800
	괄호 제거
*/
using namespace std;
string words; //괄호
set<string>result;
stack<int>pairs;
vector<pair<int, int>>parentheses;
int main() {
	fast;
	cin >> words;
	for (int i = 0; i < words.size(); i++) { //해당하는 짝 찾기
		if (words[i] == '(')pairs.push(i);
		else if (words[i] == ')') {
			parentheses.push_back({ pairs.top(),i });
			pairs.pop();
		}
	}
	int total = parentheses.size();
	for (int i = 1; i <= total; i++) {//1개부터 괄호쌍 갯수까지 뽑기
		vector<int>pick(total - i, 0);
		for (int j = 0; j < i; j++)pick.push_back(1);
		do {
			vector<int>idxs;//조합으로 뽑은 제거할 괄호인덱스들 
			for (int z = 0; z < total; z++) {
				if (pick[z]) {
					idxs.push_back(parentheses[z].first);
					idxs.push_back(parentheses[z].second);
				}
			}
			string newword;
			for (int idx = 0; idx < words.size(); idx++) {
				bool flag = false;
				for (auto value : idxs) {
					if (value == idx) {
						flag = true;
						break;
					}
				}
				if (flag)continue; //제거할 괄호 인덱스와 동일하면 건너띄기
				newword.push_back(words[idx]);
			}
			result.insert(newword);//모든 쌍 추가하기
		} while (next_permutation(pick.begin(), pick.end()));
	}
	for (auto comb : result) {//set자료형은 자동으로 오름차순이 돼있음.
		cout << comb << endl;
	}
	return 0;
}