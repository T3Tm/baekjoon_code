#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/2233
	사과나무

	save배열은 binaryNumber에 각 idx값이 몇 번 정점인지 저장한 거

	0이면 새로운 번호를 save에 저장해준다.
	1이면
*/
int save[4004],parent[2002],depth[2002];//
vector<vector<int>>graph(2002,vector<int>());
string binaryNumber;
void lca(int v1, int v2) {
	//v1 와 v2 정점 저장
	if (depth[v1] > depth[v2])swap(v1, v2);
	//둘의 깊이 맞춰주기
	while (depth[v1] != depth[v2])v2 = parent[v2];
	
	while (v1 != v2) {//같은 부모 맞춰주기
		v1 = parent[v1];
		v2 = parent[v2];
	}
	for (int i = 0; i < binaryNumber.length(); i++) {
		if (v1 == save[i])cout << i + 1 << " ";
	}
}
void dfs(int cur,int dep) {
	depth[cur] = dep;
	for (auto next : graph[cur]) {
		if (!parent[next]) {
			parent[next] = cur;
			dfs(next, dep + 1);
		}
	}
}
int main() {
	fast;
	int n, x, y;
	cin >> n >> binaryNumber >> x >> y;
	stack<int>numbers;
	numbers.push(0);
	int number = 1;
	//이진수열해독
	for (int i = 0; i < binaryNumber.length(); i++) {
		if (!(binaryNumber[i]-'0')) {
			graph[numbers.top()].push_back(number);
			save[i] = number;
			numbers.push(number++);
		}
		else {
			save[i] = numbers.top();
			numbers.pop();
		}
	}
	dfs(1, 0);
	lca(save[x-1], save[y-1]);
	return 0;
}