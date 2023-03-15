#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/14501
    14501번 퇴사
    

*/
using namespace std;
int n,dp[16];
vector<pair<int,int>>arr(16);
int main(){
    fast;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    for(int i=0;i<n;i++){
        auto value = arr[i];
        for(int j=n;j>=i+value.first;j--){//7에서 2 n==7 idx=6 
            dp[j]=max(dp[j],value.second+dp[i]);
        }
    }
    cout << dp[n];
    return 0;
}