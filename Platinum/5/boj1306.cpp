#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
/*
 * https://www.acmicpc.net/problem/1306
 * 1306번 달려라 홍준
 *
 * */
using namespace std;
int main() {
    fast;
    int n,m; cin >> n >> m;
    vector<int>arr(n);
    for(auto &i:arr)cin >> i;
    priority_queue<pair<int,int>> a;
    for(int i=0;i<m+(m-1)-1;i++)a.push({arr[i],i});
    for(int i=m-1;i<n-m+1;i++){
        a.push({arr[i+(m-1)],i+m-1});
        while(!a.empty() && a.top().second<i-(m-1))a.pop();
        cout << a.top().first << " ";
    }
    return 0;
}