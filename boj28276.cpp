#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
#define MaxboardSize 100000+2
/*
 * https://www.acmicpc.net/problem/28276
 * 28276번 Yawned-Zoned
 * 1. 하품 수를 이분탐색으로 한다. 
 * 2. bfs를 통해서 칸막이를 나눈다.
 * 3. 해당하는 부분으로 칸막이의 갯수가 넘어가는지 판단
 * 4. 된다면 ㅇㅋ
 * 5. 안되면 최대 하품 수를 줄여서 진행
 * */
using namespace std;
int r,c,w;
vector<string>board;
int dx[]{-1,1,0};
int dy[]{0,0,1};//

int dfs(int mid){//mid의 갯수를 보고 bfs를 하면서 mid갯수 채우기
    int visited[MaxboardSize][MaxboardSize]{};memset(visited,-1,sizeof visited);
    int left=0,right=c-1;//왼쪽 오른쪽 경계면 잘 체크해줘야 됨.
    int ret=0;
    queue<pair<int,int>>q;
    for(int j=0;j<c;j++){
        for(int i=0;i<r;i++){
            if(board[i][j]=='1'){
                q.push({i,j});
                visited[i][j]=1;
            }
        }
        while(!q.empty()){
            auto[x,y]=q.front();q.pop();
            for(int t=0;t<3;t++){
                int nx=x+dx[t];
                int ny=y+dy[t];
                if(nx<0 || nx>=r || ny< 0 || ny>=c)continue;//경계면 체크
                if(visited[nx][ny]){//이미 갔던 곳이라면

                }
            }
        }
    }
    return ret;//경계면 갯수 넘겨주기
}
void solve(){
    int left=1,right=1e6;//하품할 수 있는 수
    while(left<=right){
        int mid=(left+right)/2;
        int W=dfs(mid);//bfs를 돌리면서 칸막이의 갯수를 센다.
        if(W>w){//칸막이의 갯수가 넘어가므로 하품할 수 있는 수를 줄여야된다.
            right=W-1;
        }else{//칸막이의 갯수가 동일하거나 같으므로 더 하품할 수 있는 사람이 있을 때 체크.
            left=W+1;
        }
    }
    cout << left;//left, right 둘 중 하나가 정답이니 어쩃든 bfs만들면 끝.
}
int main(){
    fast;cin >> r>> c >>w;
    board.resize(r);
    for(auto&row:board)cin >> row;
    solve();
}