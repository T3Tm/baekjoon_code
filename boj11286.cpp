#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/11286
    11286번 절댓값 힙
*/
            
using namespace std;
struct DD{
    int absx,mx,x;
    bool operator<(const DD & a)const {
        if(this->absx!= a.absx)return this->absx<a.absx;
        else if(this->mx != a.mx)return this->mx<a.mx;
        return this->x<a.x;
    };
};
int main(){
    fast;
    int n,q;cin >> n;
    DD t;
    priority_queue<DD>b;
    while(n--){cin >> q;
        if(!q){
            if(b.empty())cout << 0 << endl;
            else {
                cout << b.top().x << endl;
                b.pop();
            }
        }else b.push({-abs(q),-q,q});
    }
}