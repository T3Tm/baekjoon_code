#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/25192
    25192번 인사성 밝은 곰곰이
*/
            
using namespace std;
int n,result;
int main(){
    fast;cin >> n;
    set<string>check;
    while(n--){
        string a;cin >> a;
        if(a=="ENTER"){
            result+=check.size();
            check.clear();
        }
        else check.insert(a);
    }
    cout << result + check.size();
}