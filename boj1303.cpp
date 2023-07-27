#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
/*
 * https://www.acmicpc.net/problem/1303
 * 1303번 전쟁 - 전투
 * */
using namespace std;
int n,m;
int main(){
    fast;cin >> m >> n;
    vector<string>board(n);
    for(auto &row:board)cin >> row;

    bool visited[102][102]{};
    int dx[]{0,0,1,-1};
    int dy[]{1,-1,0,0};
    auto dfs = [&](auto self,int x,int y,int count=1)->int{
        visited[x][y]=true;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx < 0 || nx>=n || ny<0 || ny>=m)continue;
            if(visited[nx][ny])continue;
            if(board[x][y]!=board[nx][ny])continue;
            count=max(count,self(self,nx,ny,count+1));
        }
        return count;
    };
    int w=0,b=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                int ret=dfs(dfs,i,j);
                if(board[i][j]=='W')w+=ret*ret;
                else b+=ret*ret;
            }
        }
    }
    cout << w << ' ' << b;
}