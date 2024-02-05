#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
/*
 * https://www.acmicpc.net/problem/3197
 * 3197번 백조의 호수
 *
 * . : 물
 * x : 빙판
 * L : 백조
 *
 * 1. 빙판 bfs한 번
 * 2. 백조 bfs한 번으로 가능할 듯
 * 0,0
 * n-1,n-1(1500,1500)
 * */
using namespace std;
int visited[1502][1502];
vector<int> parent;//해당하는 부분의 부모를 저장
int find(int a){
    if(parent[a]==-1)return a;
    return parent[a]=find(parent[a]);
}
void merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)return;
    if(a>b)parent[a]=b;
    else parent[b]=a;
}
queue<pair<int,int>>water;
int r,c;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<pair<int,int>>iceberg;
vector<vector<char>>board;
int first=-1,second=-1;
int idx=0;

void spreadWater(){
    while(!water.empty()){
        auto&[x,y]=water.front();water.pop();
        for(int j=0;j<4;j++){
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(nx < 0 || nx>=r || ny < 0 || ny>=c)continue;//경계면 체크
            if(board[nx][ny]=='X'){//녹일 빙판
                board[nx][ny]='.';//빙판을 물로 바꾸기
                visited[nx][ny]=visited[x][y];
                iceberg.push({nx,ny});
            }else if(board[nx][ny]=='.')merge(visited[nx][ny],visited[x][y]);
        }
    }
}
void melt(){
    while(!iceberg.empty()){
        auto&[x,y]=iceberg.front();iceberg.pop();
        for(int j=0;j<4;j++){
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(nx<0 || nx>=r || ny < 0 || ny>=c)continue;//경계면 체크
            if(board[nx][ny]=='.'){//물들 싹다 같은 집합으로 바꾸기
                merge(visited[nx][ny],visited[x][y]);
            }
        }
        water.push({x,y});//현재 좌표 전부가 다 물이다.
    }
}
void solve(){
    int TIME=0;
    while(find(first)!=find(second)){
        spreadWater();//물을 퍼져 나간다.
        melt();//물과 맞닿아 있는 빙판을 녹인다.
        TIME++;
    }
    cout << TIME;
}
#define Size 5000000
int main() {
    fast;memset(visited,-1,sizeof visited);
    cin >> r >> c;parent.resize(Size,-1);
    board.resize(r,vector<char>(c,' '));
    for(int i=0;i<r;i++){
        string s;cin >> s;
        for(int j=0;j<c;j++){
            board[i][j]=s[j];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]=='L'){//백조일 때
                if(first==-1)first=idx;
                else second=idx;
                water.push({i,j});
                visited[i][j]=idx++;
                board[i][j]='.';//물로 바꾸기
            }
            else if(board[i][j]=='.'){
                visited[i][j]=idx++;
                water.push({i,j});
            }
        }
    }
    solve();
    return 0;
}
