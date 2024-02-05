#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/7490
	0 만들기
*/
using namespace std;
int n;
void make_zero(int depth, int result[]) {
	if (depth == n-1) {//depth가 n-1 과 같을 때 다 정해진 거임
		int a = 1;
		int b = 2;
		queue<string>fix;
		for (int i = 0; i < n - 1;i++) {
			if (result[i] == 2) {//+ 의미
				fix.push(to_string(a));
				fix.push("+");
				a = b;
			}
			else if (result[i] == 3) {//- 의미
				fix.push(to_string(a));
				fix.push("-");
				a = b;
			}
			else {//공백의 의미
				a = a * 10 + b;
			}
			b++;
		}
		fix.push(to_string(a));
		if (fix.size() == 1) {
			a = stoi(fix.front());
		}
		else {
			a = stoi(fix.front()); fix.pop();
			while (!fix.empty()) {
				if (fix.front() == "+") {
					fix.pop();
					b = stoi(fix.front()); fix.pop();
					a += b;
				}
				else {
					fix.pop();
					b = stoi(fix.front()); fix.pop();
					a -= b;
				}
			}
		}
		if (a == 0) {
			int a = 1;
			int b = 2;
			for (int i = 0; i < n - 1; i++) {
				cout << a;
				if (result[i] == 2) {
					cout << "+";
				}
				else if (result[i] == 3) {
					cout << "-";
				}
				else {
					cout << " ";
				}
				a = b;
				b++;
			}
			cout << a <<endl;
		}
		return;
	}
	for (auto value : { 1,2,3 }) {
		if (value == 1) {
			result[depth] = 1;
			make_zero(depth + 1,result);
			result[depth] = 0;
		}
		else if (value == 2) {
			result[depth] = 2;
			make_zero(depth + 1, result);
			result[depth] = 0;
		}
		else {
			result[depth] = 3;
			make_zero(depth + 1, result);
			result[depth] = 0;
		}
	}
}
int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int calculation[10];
		make_zero(0, calculation);
		cout << endl;
	}
	return 0;
}