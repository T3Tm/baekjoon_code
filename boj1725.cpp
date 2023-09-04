#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/1725
    1725번 히스토그램
*/
using namespace std;
int main(){
    fast;
    int n;cin >> n;
    int arr[100004]{};
    for(int i=1;i<=n;i++)cin >> arr[i];
    stack<int>u;//자신보다 큰 값이면 나가긴 하나 자기보다 큰 값을 오른쪽에 계속 저장
    vector<pair<int,int>>result(n+1);
    for(int i=1;i<=n;i++){
        while(!u.empty() && arr[u.top()] > arr[i]){
            int idx=u.top();u.pop();
            result[idx].second=i-1;
        }
        u.push(i);
    }
    while(!u.empty()){
        int idx=u.top();u.pop();
        result[idx].second=n;
    }
    for(int i=n;i>=1;i--){
        while(!u.empty() && arr[u.top()] > arr[i]){
            int idx=u.top();u.pop();
            result[idx].first=i+1;
        }
        u.push(i);
    }
    while(!u.empty()){
        int idx=u.top();u.pop();
        result[idx].first=1;
    }
    int line=0;
    for(int i=1;i<=n;i++){
        line=max(line,(result[i].second-result[i].first+1)*arr[i]);
    }
    cout << line << endl;
}