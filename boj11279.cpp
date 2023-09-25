#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/11279
    11279번 최대 힙
*/
            
using namespace std;
int main(){
    fast;
    int n,q;cin >> n;
    priority_queue<int>b;
    while(n--){cin >> q;
        if(!q){
            if(b.empty())cout  << 0 << endl;
            else {
                cout << b.top() << endl;
                b.pop();
            }
        }else b.push(q);
    }
    
}