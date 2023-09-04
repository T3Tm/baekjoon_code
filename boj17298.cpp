#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/17298 
    17298번 오큰수
*/
            
using namespace std;
int n;
int main(){
    fast;cin >> n;
    stack<int>s;
    
    int arr[1'000'002]{};
    for(int i=0;i<n;i++)cin >> arr[i];

    vector<int>result(n,-1);
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()] < arr[i]){
            int idx=s.top();s.pop();
            result[idx]=arr[i];
        }
        s.push(i);
    }
    for_each(result.begin(),result.end(),[](int&a){cout << a << ' ';});
}