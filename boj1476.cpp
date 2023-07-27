#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
/*
 * https://www.acmicpc.net/problem/1476
 * 1476번 날짜 계산
 * */
using namespace std;
int main(){
    fast;
    int e,s,m; cin >> e >> s >> m;
    int x=1,y=1,z=1;
    int count=1;
    while(x!=e || s!=y || m!=z)count++,x=(x+1>15?1:x+1),y=(y+1>28?1:y+1),z=(z+1>19?1:z+1);
    cout << count;
}