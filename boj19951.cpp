#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/19951
    19951번 태상이의 훈련소 생활
*/
            
using namespace std;
int main(){
    fast;
    int n,m;cin >> n >> m;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)cin >> arr[i];
    vector<int>swiping(n+1);
    while(m--){int a,b,k;cin >> a >> b >> k;
        swiping[a]+=k;
        swiping[b]-=k;
    }
    for(int i=1;i<=n;i++){
        swiping[i]=swiping[i-1]+arr[i];
    }
    for(int i=1;i<=n;i++)cout << swiping[i] << ' ';
}