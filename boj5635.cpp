#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/5635
    5635번 생일
*/
            
using namespace std;
struct DD{
    string name;
    int d,m,y;
    bool operator<(const DD&a)const{
        if(this->y!=a.y)return this->y > a.y;
        else if(this->m!= a.m)return this->m > a.m;
        return this->d > a.d;
    };
};
int main(){
    fast;
    int n,d,m,y;cin >> n;
    string name;
    vector<DD>a;
    while(n--){
        cin >> name >> d >> m >> y;
        a.push_back({name,d,m,y});
    }
    sort(a.begin(),a.end());
    cout << a[0].name << endl << a.back().name;
}