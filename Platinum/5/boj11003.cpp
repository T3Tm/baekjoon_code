#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/11003
    11003번 최솟값 찾기
    2,4,6,8 공차 = 2 
    2,2,2,2 공차 = 0
*/
            
using namespace std;
int main(){
    fast;
    int n,l;cin >> n >> l;
    deque<pair<int,int>>s;
    for(int i=0;i<n;i++){
        int num;cin >> num;
        while(!s.empty() && s.front().second<i-l+1)s.pop_front();
        if(s.empty() || s.front().first>num){
            s.push_front({num,i});
        }else if(s.front().first==num){
            s.front().second=i;
        }
        else if(s.back().first>num){
            auto[value,idx]=s.back();s.pop_back();
            s.push_back({num,i});
            s.push_back({value,idx});
        }else if(s.back().second==num){
            s.back().second=i;
        }
        else{
            s.push_back({num,i});
        }
        cout << s.front().first << ' ';
    }
}