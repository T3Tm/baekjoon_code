#include<bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/5430
	5430번 AC
*/
using namespace std;
int main() {
	fast;
	int t; cin >> t;
	while (t--) {
		string cmd; cin >> cmd;
		int n; cin >> n;
		char tmp; cin >> tmp;//시작 [괄호
		deque<int>array;
		for (int i = 0; i < n; i++) {//갯수 만큼 숫자 받기
			int number;
			cin >> number;
			if (i != n - 1)cin >> tmp;
			array.push_back(number);
		}
		cin >> tmp;//마지막 괄호
		bool r = true, err = false;


		for (auto& command : cmd) {
			if (command == 'R') {
				r = !r;//자기 자신을 거꾸로 바꾼다.
			}
			else {//D일때
				if (array.empty()) {
					cout << "error" << endl;
					err = !err;
					break;
				}
				if (r) {
					array.pop_front();
				}
				else {
					array.pop_back();
				}
			}
		}
		if (err)continue;
		cout << '[';
		int idx = array.size();
		for (int i = 0; i < idx; i++) {
			if (r) {//앞부터 출력
				cout << array.front();
				array.pop_front();
			}
			else {
				cout << array.back();
				array.pop_back();
			}
			if (i != idx - 1) {
				cout << ',';
			}
		}
		cout << ']' << endl;
	}
}