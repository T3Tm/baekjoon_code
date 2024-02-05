#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/1743
    1743번 음식물 피하기
*/
using namespace std;
int n,m,k,answer;
vector<vector<int>>graph;
bool visited[102][102];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};//동 서 남 북
int gatherTrash(int x,int y,int depth){
    visited[x][y]=true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
        if(visited[nx][ny] || graph[nx][ny]==0 )continue;
        depth=max(depth,gatherTrash(nx,ny,depth+1));
    }
    return depth;
}
int main(){
    fast;
    cin >> n >> m >> k;
    graph.resize(n,vector<int>(m,0));
    while(k--){
        int r,c;
        cin >> r >> c;
        graph[r-1][c-1]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==1 && !visited[i][j]){
                answer=max(answer,gatherTrash(i,j,1));
            }
        }
    }
    cout << answer;
    return 0;
}