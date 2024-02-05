#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
/*
 * https://www.acmicpc.net/problem/2841
 * 2841번 외계인의 기타 연주
 *
 * */
using namespace std;
int main(){
    fast;int n,p;cin >>n >> p;
    vector<stack<int>>pret(8);
    int count=0;
    for(int i=0;i<n;i++){
        int melody,prets;cin >> melody >> prets;
        if(!pret[melody].empty()&& pret[melody].top() > prets){
            while(!pret[melody].empty() && pret[melody].top()>prets)pret[melody].pop(),count++;
        }
        if(!pret[melody].empty() && pret[melody].top()==prets)continue;
        pret[melody].push(prets);
        count++;//한 번침
    }
    cout << count;
}