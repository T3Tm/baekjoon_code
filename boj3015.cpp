#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/3015
	3015번 오아시스 재결합

	0,1,2,3,4,5,6

	5번까지 갔을 때
	4번과 5번은 그냥 볼 수 있음
	3번과 5번은 4번이 크지 않았다면 볼 수 있음.
	그럼 젤 큰 애면?
*/
using namespace std;
long long n, answer;
int arr[500002];
int save[500002];//왼쪽에서 봤을 때 제일 큰 녀석이 저장돼있음.
int cnt[500002];
void rightbig() {
	stack<pair<int, int>>tmp;
	for (int i = n - 1; i >= 0; i--) {
		while (!tmp.empty() && tmp.top().first < arr[i]) {
			auto [v, idx] = tmp.top(); tmp.pop();
			save[idx] = i;
		}
		tmp.push({ arr[i],i });
	}
}
void solve() {//
	rightbig();//자신의 왼쪽에 큰 아이 저장
	stack<pair<int, int>>tmp;//무조건 작은 값을 갖고 감
	for (int i = 0; i < n; i++) {
		while (!tmp.empty() && tmp.top().first < arr[i]) {//젤 작은 값보다 큰 값을 만나면 구간의 갯수 구해주면 됨.
			auto [v, idx] = tmp.top(); tmp.pop();
			answer++;//arr[i]를 볼 수 있는 아이.
			answer += (int)tmp.size() - cnt[save[idx]];
		}
		cnt[i] = tmp.size();
		tmp.push({ arr[i],i });
	}
	while (!tmp.empty()) {
		auto [v, idx] = tmp.top(); tmp.pop();
		answer += (int)tmp.size() - cnt[save[idx]];
	}
	cout << answer;
}
int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	solve();
	return 0;
}