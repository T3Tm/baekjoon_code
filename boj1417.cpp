#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1417
	1417번 국회의원 선거
	N명의 후보
	M명의 마을 주민
	다솜이는 기호 1번

	다른 모든 사람의 득표수 보다 많은 득표수를 가질 때 , 그 사람이 국회의원이 됨.

	다솜이가 매수해야 되는 사람의 최솟값을 출력해라.

	그리디 문제네요.
*/
using namespace std;
int n;
priority_queue<int>t;
int answer;
int main() {
	fast; cin >> n;
	int my; cin >> my;
	for (int i = 0; i < n - 1; i++) {
		int num; cin >> num;
		t.push(num);
	}
	while (!t.empty() && answer + my <= t.top()) {
		auto tmp = t.top(); t.pop();
		answer++;
		t.push(tmp - 1);
	}
	cout << answer;
	return 0;
}