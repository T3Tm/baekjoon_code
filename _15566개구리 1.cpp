#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/15566
	개구리 1
	개구리 대화 주제 : 음식, 취미, 가족, 철학
	주제에 대해 흥미도를 1부터 5까지의 수 중 하나로 가진다.
	[ 1, 1, 1, 1] << 이런식?

	각각의 통나무 마다 대화 주제가 결정된다.
	대화는 주제에 흥미도가 일치하면 이뤄진다.
	개구리들이 선호하는 연꽃이 1개 또는 2개가 있다.
	모든 개구리들이 자신이 선호하는 연꽃에 가야 한다. << 무조건
	개구리를 적절히 배치하여 모든 통나무에 정해진 주제로 대화가 가능한지, 불가능한지 

	또 가능하다면 그 방법을 알아내라.
	방법이 여러 가지가 있다면 아무거나 출력해도 좋다.
	
	가능한 배치가 없다면 첫째 줄에 NO를 출력한다.
*/
int n, m;
int visited[16];
typedef struct edge {
	int st, ed, topic;
}edge;
vector<edge>graph;
typedef struct frog {
	int topic[5];
	int first, second;
}frog;
vector<frog>Frog;
bool check(vector<int>& arr) {
	for (auto condition : graph) {
		int st = condition.st, ed = condition.ed;
		int topic = condition.topic;
		if (Frog[arr[st]].topic[topic] != Frog[arr[ed]].topic[topic]) {
			//한 번이라도 틀리면 false를 주고 같으면 아래 true를 반환한다.
			return false;
		}
	}
	return true;
}
void frogresult(int depth,vector<int>& arr) {
	if (depth == n+1) {
		if (check(arr)) {//output이 true가 됐으면 더이상 진행 안 하겠음.
			cout << "YES" << endl;
			for_each(arr.begin() + 1, arr.end(), [](int t) {cout << t << " "; });
			exit(0);
		}
		return;
	}
	for (auto value : { Frog[depth].first, Frog[depth].second}) {
		if (!visited[value]) { // i번째 수를 안 썻을 때만 사용가능
			visited[value] = 1;
			arr[value] = depth;
			frogresult(depth + 1, arr);
			visited[value] = 0;
		}
	}
}
int main() {
	fast;
	cin >> n >> m;
	Frog.resize(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> Frog[i].topic[1] >> Frog[i].topic[2] >> Frog[i].topic[3] >> Frog[i].topic[4];
	}
	for (int i = 1; i <= n; i++) {//first랑 second가 같을 수는 있다.
		cin >> Frog[i].first >> Frog[i].second;
	}
	while (m--) {//간선이 주어진다.
		//통나무의 대화 주제가 T번째 주제임을 뜻한다. (주제는 음식, 취미, 가족, 철학 순이다.)
		int a, b, topic;
		cin >> a >> b >> topic;
		graph.push_back({ a,b,topic });
	}
	vector<int>arr(n+1);
	frogresult(1, arr);
	cout << "NO";
	return 0;
}