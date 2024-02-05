#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1071
	1071번 소트
	A[i]+1 != A[i+1]
	연속된 두 수가 연속된 값이 아니게
	가능한 것이 여러 가지라면 사전순으로 가장 앞서는 것을 출력한다.
*/
using namespace std;
int n, arrcnt[1003];
priority_queue<int>arr;//얘를 정렬한 뒤에 arrcnt갯수만큼 출력하면 됨.
int main() {
	fast; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (!arrcnt[num])arr.push(-num);
		arrcnt[num]++;
	}
	if (arr.size() == 1) {
		for (int i = 0; i < arrcnt[-arr.top()]; i++) {
			cout << -arr.top() << ' ';
		}
	}
	if (arr.size() >= 2) {
		int out = -2;
		while (arr.size() >= 2) {
			int fir = -arr.top(); arr.pop();
			int sec = -arr.top();
			int cur = fir;
			if (fir + 1 == sec && arr.size() <= 1) {//sec를 출력하고 fir출력
				arr.pop(); arr.push(-fir);
				cur = sec;
			}
			else if (out + 1 == fir) {
				arr.pop(); arr.push(-fir);
				cur = sec;
			}
			arrcnt[cur]--;
			if (arrcnt[cur])arr.push(-cur);
			cout << cur << ' ';
			out = cur;
		}
		while (!arr.empty()) {
			int cur = -arr.top(); arr.pop();
			arrcnt[cur]--;
			if (arrcnt[cur])arr.push(-cur);
			cout << cur << ' ';
		}
	}
	return 0;
}