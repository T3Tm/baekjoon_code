#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/7562
    7562번 나이트의 이동
*/
            
using namespace std;
int t,n,x,y,a,b;
int dx[]{1,2,2,1,-1,-2,-2,-1};
int dy[]{2,1,-1,-2,-2,-1,1,2};
int bfs(){
    queue<pair<int,int>>loc;
    loc.push({x,y});
    int visited[303][303]{};memset(visited,-1,sizeof visited);
    visited[x][y]=0;
    while(!loc.empty()){
        auto[x,y]=loc.front();loc.pop();
        if(x==a && y == b)return visited[x][y];
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
            if(visited[nx][ny]!=-1)continue;
            visited[nx][ny]=visited[x][y]+1;
            loc.push({nx,ny});
        }
    }
    return -1;
}
int main(){
    fast;cin >> t;
    while(t--){
        cin >> n >> x >> y >> a >> b;
        cout << bfs() << endl;
    }
}