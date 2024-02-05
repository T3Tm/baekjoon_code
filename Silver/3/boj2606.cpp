#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
/*
 * https://www.acmicpc.net/problem/2606
 * 2606번 바이러스
 * */
using namespace std;
int main(){
    fast;
    int n,m;cin >> n >> m;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool visited[102]{};
    auto dfs=[&](auto self,int x=1,int count=0)->int{
        visited[x]=true;
        for(auto node:graph[x]){
            if(visited[node])continue;
            count=max(count,self(self,node,count+1));
        }
        return count;
    };
    cout << dfs(dfs);
}