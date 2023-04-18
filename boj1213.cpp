#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1213
	1213번 팰린드롬 만들기

	S를 팰린드롬으로 바꿔라
	만약 |S| %2 == 0이면 각 문자들의 갯수가 짝수개여야함.
	하지만 |S|%2 이면 하나의 문자가 홀수개 다른 것은 다 짝수개 여야한다.
*/
using namespace std;
map<char, int>alpha;
string answer;
int main() {
	fast;
	string tmp; cin >> tmp;
	for (auto& value : tmp) {
		if (!alpha.count(value)) alpha[value] = 0;
		alpha[value]++;
	}
	bool flag = (tmp.size() % 2 ? 1 : 0);//길이가 짝수 인지 홀수인지 판단
	char one;//하나의 문자만 따로 빼내기.
	for (auto [key, value] : alpha) {//홀수 두번 나오는지 판단.
		if (tmp.size() % 2 && value % 2) {//짝수면 flag 0이라고 돼있는데 이거나오면 오바
			if (flag) {//지금은 괜찮음
				flag = false;
				one = key;
			}
			else {
				answer = "I'm Sorry Hansoo";
				break;
			}
		}
		else if (tmp.size() % 2 == 0 && value % 2) {
			answer = "I'm Sorry Hansoo";
			break;
		}
		for (int i = 0; i < value / 2; i++) {
			answer.push_back(key);
		}
	}
	string ttmp = answer; reverse(ttmp.begin(), ttmp.end());
	if (answer.back() != 'o' && tmp.size() % 2) {
		answer = answer + one + ttmp;
	}
	else if (answer.back() != 'o') {
		answer = answer + ttmp;
	}
	cout << answer;
	return 0;
}