#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/4803
	트리
	1. 그래프 받는다.
	2. 그래프를 dfs로 방문한다.
	3. 방문을 할 때 현재 좌표와 다음 좌표와 같은 집합에 있지 않다면
	집합을 합쳐준다.
	4. 만약 다음에 갈 곳이 이미 같은 집합에 있는 요소라면? 그럼 사이클이 발생했다는 것
	그럼 더 작은 수에게 방문 배열에 2를 넣어서 나중에 갯수 안 세줌.
*/
int parent[501];
int v[501];
vector<vector<int>>graph;
void setvisited() {
	for (int i = 0; i < 501; i++) {
		v[i] = 0;
	}
}
void setparent() {
	for (int i = 0; i < 501; i++) {
		parent[i] = -1;
	}
}
int Find(int cur) {
	if (parent[cur] == -1)return cur;
	return parent[cur] = Find(parent[cur]);
}
void merge(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a < b)parent[b] = a;
	else parent[a] = b;//더 작은 쪽이 부모가 되게끔 만들기
}
void dfs(int cur) {
	v[cur] = 1;
	for (auto next : graph[cur]) {
		int a = Find(next);
		int b = Find(cur);
		if (a != b)merge(next, cur);//cur랑 next랑 연결한다.
		else {
			//이미 같은 곳? 근데 그게 다음에 갈 곳?
			// 사이클 발생 그럼 부모의 v에 2를 저장
			if (next > cur)v[cur] = 2;
			else v[next] = 2;
		}
		if (!v[next]) {
			dfs(next);
		}
	}
}
int main() {
	fast;
	for (int i = 1;; i++) {
		int n, m;
		cin >> n >> m;
		//정점의 갯수 n과 간선의 갯수 m 주어짐.
		if (n == 0 && m == 0)break;
		graph.assign(n + 1, vector<int>());
		setparent();
		setvisited();
		while (m--) {//한 방향 경로 설정
			int v1, v2;
			cin >> v1 >> v2;
			graph[v1].push_back(v2);
		}
		for (int i = 1; i <= n; i++) {
			if (!v[i])dfs(i);
		}
		int count = 0;
		vector<int>check;
		for (int i = 1; i <= n; i++) {
			if (parent[i] == -1) {
				count++;
				check.push_back(i);
			}
		}
		//같은 집합 내에 있는 애들 중에 사이클이 생겼는지 확인 해줘야함.
		// 즉 check 에 있는 애들 중에서 사이클 있었는지 판별해보자.
		for (auto value : check) {
			bool flag = false;
			//value 즉 부모가 사이클을 가짐.
			if (v[value] == 2)flag = true;
			else {//아닐 때 부모 집합에 있는 값중에서 사이클 찾아내기
				for (int i = 1; i <= n; i++) {
                    //부모와 같은 집합이면서 지금 해당하는 값이 만약 사이클이면 flag에 true
					if (parent[i] == value && v[i] == 2) {
						flag = true;
						break;
					}
				}
			}
			if (flag)count--;
		}
		if (count > 1) {
			cout << "Case " << i << ": A forest of " << count <<" trees.\n" ;
		}
		else if (count == 1) {
			cout << "Case " << i << ": There is one tree.\n";
		}
		else {
			cout << "Case " << i << ": No trees.\n";
		}
		
	}
	return 0;
}