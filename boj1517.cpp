#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1517
	1517번 버블 소트
	머지 소트에서 A,B를 비교하는 가운데 B라는 부분에서 temp 로 합칠 때 B가 먼저 들어가는 경우
	얼마나 먼저 들어가는지 확인한다. 그러면 비교 횟수가 나옴.
*/
using namespace std;
int n;
vector<int>arr;
long long answer;
void merge(int s1,int e1,int s2,int e2) {//
	vector<int> temp;//일단 담아놓고 arr에다가 넣어서 정렬하자.
	int t1 = s1, t2 = s2;
	for (; t1 <= e1 && t2 <= e2;) {//t1과 t2를 비교해서 넣는다.
		if (arr[t1] > arr[t2]) {//뒤에 있는 수가 더 작기에 t2가 앞으로 먼저 들어가야됨.
			temp.push_back(arr[t2++]);
			answer += (e1 - t1 + 1);
		}
		else {//원래 순서대로 그냥 가도 됐엇다. swap 안해도 됨.
			temp.push_back(arr[t1++]);
		}
	}
	while (t1 <= e1) {//앞에 있는 숫자를 아직 덜 넣었음.
		temp.push_back(arr[t1++]);
	}
	while (t2 <= e2) {
		temp.push_back(arr[t2++]);
	}
	int idx = 0;
	for (int i = s1; i <= e2; i++) {//해당 구간 값을 arr에 넣어놓자.
		arr[i] = temp[idx++];
	}
}
void mergesort(int start,int end) {//start부터 end까지 얼마나 걸리는지 확인한다.
	if (start < end) {//1개보다 크거나 같을떄
		mergesort(start, (end + start) / 2);
		mergesort((end + start) / 2 + 1, end);
		merge(start, (end + start) / 2, (end + start) / 2 + 1,end);
	}
}
void solve() {
	mergesort(0, n - 1);
	cout << answer;
}
int main() {
	fast;
	cin >> n;
	arr.resize(n,0);
	for (int i = 0; i < n; i++)cin >> arr[i];
	solve();
	return 0;
}