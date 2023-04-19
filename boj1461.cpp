#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1461
	1461번 도서관

	현재 0에 있고, 마구 놓은 책도 다 0에 있다

	책을 모두 제자리에 놔둘 때 드는 최소 걸음수 계산하자.

	한 번에 M권의 책을 들 수 있다.
	M권을 들고 움직였다가 다시 원점으로 가야하는데.

	왔다갔다하면 당연히 안 좋다. => 한쪽을 몰아서 갔다가 가는 것이 당연히 좋은데.  << 이것도 에러가 있다.



*/
using namespace std;
int n, k;
long long answer;
int main() {
	fast; cin >> n >> k;
	vector<int>minus, plus;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num < 0)minus.push_back(num);
		else plus.push_back(num);
	}
	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end(), greater<int>());
	if (minus.empty()) {//plus로만 짜야된다.
		int i;
		answer += plus[0];//한 배 계산하기
		for (i = k; i + (k - 1) < plus.size(); i += k) {
			answer += plus[i] * 2;
		}
		if (plus.size() % k && i < plus.size()) {//똑같이 또 딱 가지 못하면 남는 거 한 번에 처리
			answer += plus[i] * 2;
		}
	}
	else if (plus.empty()) {//minus로만 짜야된다.
		int i;
		answer += -minus[0];//한 배 계산하기
		for (i = k; i + (k - 1) < minus.size(); i += k) {
			answer += (-minus[i]) * 2;
		}
		if (minus.size() % k && i < minus.size()) {//똑같이 또 딱 가지 못하면 남는 거 한 번에 처리
			answer += (-minus[i]) * 2;
		}
	}
	else if (-minus[0] > plus[0]) {//음수 쪽의 큰 값을 제일 마지막에 가져가자.
		//일단 양수들을 그럼 적절히 가져가자
		int i;
		for (i = 0; i + (k - 1) < plus.size(); i += k) {
			answer += plus[i] * 2;//갔다가 0으로 오기.
		}
		if (plus.size() % k && i < plus.size()) {//딱 나눠서 갔다오지를 못함. 남은 뒤에 남은 k-1~갯수들을 다같이 갔다오기.
			answer += plus[i] * 2;
		}
		//양수 쪽은 끝났음. 그러면 음수로 진입
		//제일 큰 것은 한번만 계산하고 나머지들은 *2배씩 계산 먼저 1배 계산하자.
		answer += -minus[0];//한 배 계산하기
		for (i = k; i + (k - 1) < minus.size(); i += k) {
			answer += (-minus[i]) * 2;
		}
		if (minus.size() % k && i < minus.size()) {//똑같이 또 딱 가지 못하면 남는 거 한 번에 처리
			answer += (-minus[i]) * 2;
		}
	}
	else if (-minus[0] <= plus[0]) {//
		int i;
		for (i = 0; i + (k - 1) < minus.size(); i += k) {
			answer += (-minus[i]) * 2;//갔다가 0으로 오기.
		}
		if (minus.size() % k && i < minus.size()) {//딱 나눠서 갔다오지를 못함. 남은 뒤에 남은 k-1~갯수들을 다같이 갔다오기.
			answer += (-minus[i]) * 2;
		}
		//양수 쪽은 끝났음. 그러면 음수로 진입
		//제일 큰 것은 한번만 계산하고 나머지들은 *2배씩 계산 먼저 1배 계산하자.
		answer += plus[0];//한 배 계산하기
		for (i = k; i + (k - 1) < plus.size(); i += k) {
			answer += plus[i] * 2;
		}
		if (plus.size() % k && i < plus.size()) {//똑같이 또 딱 가지 못하면 남는 거 한 번에 처리
			answer += plus[i] * 2;
		}
	}
	cout << answer;
	return 0;
}