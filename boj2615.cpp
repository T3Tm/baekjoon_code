#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/2615
    2615번 오목
    0. 0이면 2번째 줄은 출력 x
    1. 가장 왼쪽에 있는 것을 먼저 출력
    2. 가장 위에 있는 것을 먼저 출력
    
    대각선이면 해당하는 곳에 대각선이 안된다고 체크해놓기
    1. 가로 
    2. 세로 ()
    3. 대각선 (왼쪽 아래, 오른쪽 아래)
*/
            
using namespace std;
vector<vector<int>>board(21,vector<int>(21));
struct myarr{int w,h,d[2];}arr[21][21];//가로,세로, 왼쪽대각선, 오른쪽 대각선
int height(int i, int j){
    int TF=arr[i][j].h;
    int cnt{};
    if(TF!=-1){
        stack<pair<int,int>>loc;
        loc.push({i,j});
        int x=i,y=j;
        while(x<19 && board[i][j]==board[x][y])loc.push({x,y}),cnt++,x++;
        if(cnt==5 && TF!=-1)TF=1;
        else TF=-1;
        while(!loc.empty()){
            auto[x,y]=loc.top();loc.pop();
            arr[x][y].h=TF;
        }
    }
    return cnt;
}
int width(int i,int j){
    int TF=arr[i][j].w;
    int cnt{};
    if(TF!=-1){
        stack<pair<int,int>>loc;
        loc.push({i,j});
        int x=i,y=j;
        while(y<19 && board[i][j]==board[x][y])loc.push({x,y}),cnt++,y++;
        if(cnt==5 && TF!=-1)TF=1;
        else TF=-1;
        while(!loc.empty()){
            auto[x,y]=loc.top();loc.pop();
            arr[x][y].w=TF;
        }
    }
    return cnt;
}
int diagonal(int i,int j){
    int ret=0;
    //왼쪽 대각선
    int TF=arr[i][j].d[0];
    int cnt{};
    if(TF!=-1){
        stack<pair<int,int>>loc;
        loc.push({i,j});
        int x=i,y=j;
        while(x<19 && y>=0 && board[i][j]==board[x][y])loc.push({x,y}),cnt++,x++,y--;
        if(cnt==5 && TF!=-1)TF=1;
        else TF=-1;
        while(!loc.empty()){
            auto[x,y]=loc.top();loc.pop();
            arr[x][y].d[0]=TF;
        }
    }
    ret=cnt;
    if(ret==5)ret=20;
    //오른쪽 대각선
    TF=arr[i][j].d[1];
    cnt=0;
    if(TF!=-1){
        stack<pair<int,int>>loc;
        loc.push({i,j});
        int x=i,y=j;
        while(x<19 && y<19 && board[i][j]==board[x][y])loc.push({x,y}),cnt++,x++,y++;
        if(cnt==5 && TF!=-1)TF=1;
        else TF=-1;
        while(!loc.empty()){
            auto[x,y]=loc.top();loc.pop();
            arr[x][y].d[1]=TF;
        }
    }
    if(ret!=20)ret=cnt;

    if(ret==5)ret=21;
    return ret;
}
int main(){
    fast;
    for(int i=0;i<19;i++)for(int j=0;j<19;j++)cin >>board[i][j];
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if(board[i][j]){
                int value;
                value=width(i,j);
                if(value==5){
                    cout << board[i][j] << endl << i+1 <<' '<< j+1;
                    exit(0);
                }
                value=height(i,j);
                if(value==5){
                    cout << board[i][j] << endl << i+1 <<' '<< j+1;
                    exit(0);
                }
                value=diagonal(i,j);
                if(value==20){
                    cout << board[i][j] << endl << i+5 << ' ' << j-3;
                    exit(0);
                }
                else if(value==21){
                    cout << board[i][j] << endl << i+1 << ' '<< j+1;
                    exit(0);
                }
            }
        }
    }
    cout << 0;
}