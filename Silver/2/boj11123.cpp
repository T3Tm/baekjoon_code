#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/11123
	양 한마리... 양 두마리...
	
*/
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int h, w;
vector<vector<char>>graph;
void dfs(int x,int y,int visit[][101]) {
	visit[x][y] = 1;
	for (int i = 0; i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
		if (visit[nx][ny] || graph[nx][ny]=='.')continue;
		dfs(nx, ny, visit);
	}
}
int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		int visit[101][101] = { 0 };
		int answer = 0;
		cin >> h >> w;
		graph.assign(h, vector<char>(w, ' '));
		for (int i = 0; i < h; i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j < w; j++) {
				graph[i][j] = temp[j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visit[i][j] && graph[i][j]=='#') {
					dfs(i, j, visit);
					answer++;
				}
			}
		}
		cout << answer << endl;
	}
	return 0;
}