#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
/*
 * https://www.acmicpc.net/problem/1620
 * 1620번 나는야 포켓몬 마스터 이다솜
 * */
using namespace std;
map<string,string>dogam;
int main(){
    fast;
    int n,m;cin >> n >> m;
    for(int i=1;i<=n;i++){
        string a;cin >> a;
        string insert=to_string(i);
        dogam[a]=insert;
        dogam[insert]=a;
    }
    for(int i=0;i<m;i++){
        string a;cin >> a;
        cout << dogam[a] << endl;
    }
}