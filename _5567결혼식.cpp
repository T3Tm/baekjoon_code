#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/5567
	결혼식
	상근이 동기는 모두 N명이다, 
	상근이 학번 : 1
	학번은 모두 : N번 까지이다.

	2<=N <=500
	리스트 길이 1<=  m<=10000
	a와 b가 친구이다.

	초대하는 동기 

	자신의 친구와, 친구의 친구까지 다 초대할 것이다.
	
	즉 그래프 적으로 연결이 돼있냐
	dfs로 돌면서 count 세주면 될듯싶네
*/
using namespace std;
int answer;
map<int, vector<int>>graph;
int Count[501];
void wedding(int cur, int depth) {//친구는 depth가 1일 거임, 친구의 
	if (depth == 2)return;
	for (auto next : graph[cur]) {
		wedding(next,depth+1);
		Count[next] = 1;
	}
}
int main() {
	fast;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	wedding(1,0);
	for (int i = 2; i <= n; i++) {
		answer += Count[i];
	}
	cout << answer;
	return 0;
}