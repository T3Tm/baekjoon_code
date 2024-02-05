#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
    https://www.acmicpc.net/problem/20007
    떡 돌리기
    떡을 돌리려고 한다.
    떡은 한번에 하나씩만 들고 갈 수 있다.
    집들 사이에는 M개의 양방향 도로가 있다.
    하루에 X보다 먼 거리를 걷지 않고 거리가 가까운 집부터 방문함.

    잠은 꼭 집에서 자야하므로 왕복할 수 없는 거리는 다음 날에 가리로 다짐.
    (즉, 왕복 거리까지 계산해서 X(m)를 계산해줘야됨.)
    N-1개의 이웃집에게 모두 떡을 돌리기 위해 최소 며칠 걸릴 것인가?

    시뮬레이션 + dijstra 문제네요
    2<=N<=1000 집
    1<=M<=10만 도로
    1<=x<=1천만 하루 걷는 양
    0<=y<=N 성현이의 집 위치 (정점) 일직선 아니네
    
*/
int n, m, x, y,answer=1;
map<int, vector<pair<int,int>>>graph;
int visited[1001];//방문 배열
int Distance[1001];
int check() {
    for (int i = 0; i < n; i++) {
        if (!visited[i])return 1;
    }
    return 0;
}
void dijstra() {
	for (int i = 0; i < n; i++) {
		Distance[i] = INT_MAX;
	}
	Distance[y] = 0;
    priority_queue<pair<int, int>>Location;
    Location.push({ 0,y });
	while (!Location.empty()) {
        auto next = Location.top(); Location.pop();
        int cur = next.second, dist = next.first;
        for (auto Next : graph[cur]) {
            if (Distance[Next.second] > dist + Next.first) {
                Distance[Next.second] = dist + Next.first;
                Location.push({ Distance[Next.second],Next.second });
            }
        }
	}
}
void DDUK() {//떡은 한 번에 하나 밖에 못 듦
    int total_dist=0;
    for (int i = 0; i < n;i++) {
        pair<int, int>mindist = { INT_MAX,-1 };
        for (int idx = 0; idx < n; idx++) {
            if (Distance[idx]) {
                if (!visited[idx] && (Distance[idx]<mindist.first)) {
                    //방문하지 않은 것중 젤 작은 곳 찾기
                    mindist = { Distance[idx],idx };
                }
            }
        }
        if (mindist.second==-1)break;//최소로 갈 수 있는 곳이 없음.
        //왕복까지 생각
        if (total_dist + mindist.first * 2 <= x) {
            total_dist += mindist.first * 2;
        }
        else {//못감
            //만약 못가는데 total_dist 쌓아온 것이 없었으면 그냥 가는데 못가는 거니까 안됨.
            if (total_dist == 0)break;
            if (mindist.first * 2 > x)break;
            total_dist = mindist.first*2;
            answer++;
        }
        visited[mindist.second]=1;
    }
}
int main() {
    fast;
    cin >> n >> m >> x >> y;//집은 n개 있다.
    visited[y] = 1;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c,b});//a에서 b까지 c거리
        graph[b].push_back({c,a });
    }
    dijstra();//모든 distance 거리 알게됨.
    DDUK();
    if (check())cout << -1;//모든 집을 방문 못함
    else cout << answer;
    return 0;
}