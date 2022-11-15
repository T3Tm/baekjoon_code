#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define INF 16
using namespace std;
/*
    https://www.acmicpc.net/problem/14938
    14938번 서강그라운드
    지역의 갯수(정점의 갯수), 수색범위, 길의 갯수 (간선의 갯수)
    어디 정점에서 어디로 갈 수 있다.
    for 문으로 1번부터 n번까지 돌린다.
    각 정점에서 다른 정점까지의 최단 거리를 구한다. 다익스트라로.
    그 다음에 각 정점에서 다른 정점까지 거리가 m보다 작으면 해당 인덱스의 아이템 갯수를 더한다.
*/
int n, m, r;
map<int, vector<pair<int, int>>>g;
int ground(int start, vector<int>&items) {//시작 정점 받기 시작 정점으로 부터 다른 정점까지의 거리 구하기
    vector<int>distance = vector<int>(n+1, INF);
    distance[start] = 0;
    priority_queue<pair<int,int>>seogang;
    seogang.push({ 0,start }); //거리, start
    while (!seogang.empty()) {
        auto value = seogang.top(); seogang.pop();
        for (auto next : g[value.second]) {
            int newDist = value.first + next.second;
            if (newDist < distance[next.first]) {
                distance[next.first] = newDist;
                seogang.push({ newDist,next.first });
            }
        }
    }
    int item=0;
    for (int idx = 1; idx <= n;idx++) {//안에 값을 보면서 무엇인지 확인
        if (distance[idx] <= m)item += items[idx];
    }
    return item;
}
int main(){
    cin >> n >> m >> r;
    vector<int>items= vector<int>(n+1,0); // n개의 정점에 대한 item 갯수
    for (int i = 1; i <= n; i++)cin >> items[i];
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        g[a].push_back(pair<int, int>(b, l));//a에서 b까지 L거리임.
        g[b].push_back(pair<int, int>(a, l));
    }
    int item = 0;
    for (int i = 1; i <= n; i++) item=max(item,ground(i, items));
    cout << item;
    return 0;
}