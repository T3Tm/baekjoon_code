#include <bits/stdc++.h>//
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17182
	17182�� ���� Ž�缱

	�� ���� �ٸ� ������ ���� �ּ� ���ϴ� �� �ɸ��� �ð�
	nlogn�� ��� n�࿡ ���ؼ� �ϴ� �ð�
	n^nlogn
	100*logn�� �ð����� �ذ� ����

*/
using namespace std;
struct loc {
	int c, x;
	bool operator () (loc& a, loc& b) {
		return a.c > b.c;
	}
};
int n, k;
int arr[12][12];
int dist[12][12];//�Ÿ� ����.
int answer = 100000;//�ִ�
int result[12];
bool visited[12];
void Dijkstra(int start) {//�ϳ��� �࿡�� �ٸ� ����� �Ÿ� ���ϱ�.
	priority_queue<loc, vector<loc>, loc>Loc;
	Loc.push({ 0,start });//��� ��?
	dist[start][start] = 0;//
	while (!Loc.empty()) {
		auto pre = Loc.top(); Loc.pop();
		for (int i = 0; i < n; i++) {
			if (pre.c + arr[pre.x][i] < dist[start][i]) {//�ش��ϴ� ������ ���µ� �ɸ��� �� �ּҰ� �ٲ� �� ����.
				dist[start][i] = pre.c + arr[pre.x][i];
				Loc.push({ dist[start][i],i });//�ش� ������ ����.
			}
		}
	}
}
void comb(int depth) {
	if (depth == n) {
		int temp = 0;
		int pre = result[0];
		for (int i = 1; i < n; i++) {
			int next = result[i];
			temp += dist[pre][next];
			pre = next;
		}
		answer = min(answer, temp);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			result[depth] = i;
			comb(depth + 1);
			visited[i] = false;
		}
	}
}
int main() {
	fast;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dist[i][j] = 1002;//�ִ�
		}
	}
	for (int i = 0; i < n; i++) {
		Dijkstra(i);
	}
	result[0] = k;
	visited[k] = true;
	comb(1);
	cout << answer;
	return 0;
}