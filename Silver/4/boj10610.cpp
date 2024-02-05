#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/10610
	10610번 30

	양수 N을 봤다 30이라는 수를 존경하기 때문에, 30의 배수가 가장 큰 수를 만들고 싶다.

	잠만 어차피 다 더했을 때 3의 배수라는 것은 그 숫자들의 순열에 상관이 없다는 것.!

	큰 수대로 나열하면 된다. 그리고 그 수가 30의 배수인지 판별하면 되네.
*/
using namespace std;
string n;
bool cmp(char& a, char& b) {
	return a > b;
}
int main() {
	fast; cin >> n;
	sort(n.begin(), n.end(), cmp);
	int three = 0;
	for (auto value : n) {
		three += value - '0';
	}
	if (three % 3 == 0 && n.back() == '0') {//30의 배수임
		cout << n;
	}
	else {
		cout << -1;
	}
	return 0;
}