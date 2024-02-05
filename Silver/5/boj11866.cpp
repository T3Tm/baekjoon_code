#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl "\n"
/*
	https://www.acmicpc.net/problem/11866
	11866번 요세푸스 문제 0
*/

using namespace std;
queue<int>start;
queue<int>result;
int n, k;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)start.push(i);
	int cnt = 0;
	while (!start.empty()) {
		int save = start.front();
		start.pop();
		cnt++;
		if (cnt == k) {
			result.push(save);
			cnt = 0;
		}
		else {
			start.push(save);
		}
	}
	int value = result.size();
	if (value >= 2) {
		cout << "<" << result.front() << ",";
		result.pop();
		for (int i = 0; i < (value - 2); i++) {
			cout << " " << result.front() << ",";
			result.pop();
		}
		cout << " " << result.front() << ">";
	}
	else if (value == 1) {
		cout << "<" << result.front() << ">";
	}

	return 0;
}