#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/14395
    14395번 4연산
    
    정리 해보자면
    1. 2배 연산
    2. 2로 나누기 연산
    3. 제곱 연산
    4. 자신으로 나누기 연산

    1의 연산을 계속한다고 해도
    1 부터
    10^9은 10억이다.
    2에다가 30승만해도 된다.

    bfs로 그리디하게 풀면 된다.


*/
#define size 1000000000
using namespace std;
int s,t;
int main(){
    fast;cin >> s>> t;
    queue<int>loc;
    int visited[size+2];memset(visited,-1,sizeof visited);

    visited[s]=0;
    while(!loc.empty()){
        int value=loc.front();loc.pop();
        if(value==t)break;
        for(auto next:{value*value,value/value,value/2,value*2}){
            if(next<=0 || next>size)continue;
            if(visited[next]!=-1)continue;
            visited[next]=visited[value]+1;
            loc.push(next);
        }
    }
    cout << visited[t];
}