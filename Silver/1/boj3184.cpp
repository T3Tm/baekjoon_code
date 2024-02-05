#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
/*
 * https://www.acmicpc.net/problem/3184
 * 3184번 양
 * */
using namespace std;
int r,c;
int main(){
    fast;cin >> r >> c;
    vector<vector<char>>board(r,vector<char>(c));
    int fox=0,sheep=0;
    for(auto& row:board){
        string temp;cin >>temp;
        for(int i=0;i<c;i++){
            row[i]=temp[i];
            if(row[i]=='v')fox++;
            else if(row[i]=='o') sheep++;
        }
    }
    bool visited[252][252]{};
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    vector<stack<pair<int,int>>> query;
    auto dfs= [&](auto self,int x,int y)->void{
        visited[x][y]=true;//방문 표시
        if(board[x][y]=='v')query[1].push({x,y});
        else if(board[x][y]=='o')query[0].push({x,y});
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx< 0 || nx>=r || ny< 0 || ny>=c || visited[nx][ny])continue;
            if(board[nx][ny]=='#')continue;
            self(self,nx,ny);
        }
    };
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!visited[i][j]){
                query.clear();
                query.resize(2);
                dfs(dfs,i,j);
                int idx=0;
                if(query[0].size()>query[1].size())idx++;
                if(idx) fox-=query[idx].size();
                else sheep-=query[idx].size();
                while(!query[idx].empty()){
                    auto[x,y]=query[idx].top();query[idx].pop();
                    board[x][y]='.';
                }
            }
        }
    }
    cout << sheep << ' ' << fox;
}