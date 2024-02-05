#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16940
	bfs 스페셜 저지
	
	bfs랑 백트래킹 이용해서 풀면 될 것 같다 
	x를 꺼내서 연결할 수 있는 것들을 next vector에 넣는다.

	그 다음 vector에서 백트래킹을 이용해서 차례로 next 들어간다.

	그 다음 next를 다 넣었을 때 맨 처음에 연결된 
	next에 있는 것들 다 빼내야함. 
	pair

	{bfs 몇 번째 방문, 몇 번째 방문의 순서
*/
using namespace std;
vector<vector<int>>graph;
vector<pair<int,int>>visited(100001,{0,0});
int connection[100001] = { 1 };
int compare[100001];
int n;
void specialJudge(int cur) {
	queue<int>loc;
	loc.push(cur);
	while (!loc.empty()) {
		int cur = loc.front(); loc.pop();
		int count = 0;
		for (auto next : graph[cur]) {
			if (!visited[next].first) {
				count++;
				visited[next].first = visited[cur].first + 1;
				visited[next].second = cur;
				loc.push(next);
			}
		}
		connection[cur] = count;
	}
}
//(2,1),(3,1)
bool check() {
	int prenumber = 0;
	int pre = 0;
	deque<int>prevalue;
	for (int i = 0; i < n; i++) {
		if (visited[compare[i]].second == prenumber && pre<=visited[compare[i]].first) {//처음에 넣은 숫자 맞냐?
			prevalue.push_back(compare[i]);
			pre = visited[compare[i]].first;
			connection[prenumber]--;
		}
		else return false;
		while (connection[prenumber] == 0 && !prevalue.empty()) {
			prenumber = prevalue[0];
			prevalue.pop_front();
		}
	}
	return true;
}
int main() {
	cin >> n;
	graph.resize(n+1);
	visited[0] = { 1,1 };
	visited[1] = { 1,0 };
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < n; i++) cin >> compare[i];
	specialJudge(1);
	if (check()) cout << 1;
	else cout << 0;
	return 0;
}