#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/8979
    8979번 올림픽
    1. 금
    2. 은
    3. 동
*/
using namespace std;

struct mypair{
    int g,s,b,number;
};
bool compare(mypair&a,mypair&b){
    if(a.g == b.g){
        if(a.s == b.s){
            if(a.b==b.b)return a.number <b.number;
            return a.b>b.b;
        }
        return a.s>b.s;
    }
    return a.g > b.g;
}
int n,k;
vector<mypair>a;
int main(){
    fast;cin >> n >> k;
    a.resize(n);
    for(int i=0;i<n;i++){
        auto& v=a[i];
        cin>> v.number >> v.g >> v.s >> v.b  ;
    }
    sort(a.begin(),a.end(),compare);
    int t=1;
    int g=1;
    for(int i=0;i<n;i++){
        if(i!=0){
            if(a[i-1].g==a[i].g && a[i-1].s == a[i].s && a[i-1].b == a[i].b){
                g++;
            }else{
                t+=g;
                g=1;
            }
        }
        if(a[i].number==k){
            cout << t;
            break;
        }
    }
}