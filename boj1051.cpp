#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/1051
    숫자 정사각형
*/
            
using namespace std;
int main(){
    fast;
    int n,m;cin >> n >> m;
    vector<string>board(n);
    for(auto&row:board)cin >> row;
    
    auto find = [&](int x,int y,int size)->bool{
        return (board[x][y]==board[x][y-size]) && (board[x][y-size]==board[x-size][y]) && (board[x-size][y]==board[x-size][y-size]);
    };
    int maxsize=0;
    for(int size=1;size<=min(n,m);size++){
        for(int i=size-1;i<n;i++){
            for(int j=size-1;j<m;j++){
                if(find(i,j,size-1))maxsize=max(maxsize,size);
            }
        }
    }
    cout << maxsize*maxsize;
}