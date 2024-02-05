#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
 * https://www.acmicpc.net/problem/2644
 * 2644번 촌수계산
*/
using namespace std;
int n,m,from,to;
vector<vector<int>>graph;
int visited[102];
int CalVilage(int x){
    queue<int>loc;
    loc.push(x);
    visited[x]=0;
    while(!loc.empty()){
        int x=loc.front();loc.pop();
        if(x==to)return visited[to];
        for(auto &next:graph[x]){
            if(visited[next])continue;
            visited[next]=visited[x]+1;
            loc.push(next);
        }
    }
    return -1;
}
int main(){
    fast;
    cin >> n >> from >> to >> m;
    graph.resize(n+1);
    while(m--){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout << CalVilage(from);
    return 0;
}