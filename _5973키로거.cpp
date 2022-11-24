#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/5397
	키로거
	stack , deque를 이용하기
*/
int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		string password;
		cin >> password;
		deque<char>out;
		stack<char>save;
		for (auto value : password) {
			if (value == '<') {
				if (!out.empty()) {
					save.push(out.back());
					out.pop_back();
				}
			}
			else if (value == '>') {
				if (!save.empty()) {
					out.push_back(save.top());
					save.pop();
				}
			}
			else if (value == '-') {
				if (!out.empty()) {
					out.pop_back();
				}
			}
			else {
				out.push_back(value);
			}
		}
		while (!save.empty()) {
			out.push_back(save.top());
			save.pop();
		}
		while (!out.empty()) {
			cout << out.front();
			out.pop_front();
		}
		cout << endl;
	}
}