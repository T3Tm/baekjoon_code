#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2170
	2170번 선 긋기
*/
using namespace std;
int n,answer;
vector<pair<int, int>>arr;
int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		arr.push_back({ x,y });
	}
	sort(arr.begin(), arr.end());//정렬
	auto [f, e] = arr[0];//처음과 끝
	answer += e - f;
	for (int i = 1; i < n; i++) {//
		auto [nf, ns] = arr[i];//다음 처음과 끝이 주어짐.
		if (nf > e) {//넘어간다.
			f = nf, e = ns;
			answer += ns - nf;
		}
		else {// 
			if(ns>e){
				answer += ns - e;
				e = ns;
			}
		}
	}
	cout << answer;
	return 0;
}
