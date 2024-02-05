#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl "\n"
/*
 https://www.acmicpc.net/problem/23029
 23029번 시식 코너는 나의 것
 1,2,4
 1,3,4
 1,3,4,6
 */
using namespace std;
int n,arr[100004],dp[100004];
int main(){
    fast;cin>> n;
    for(int i=1;i<=n;i++)cin >> arr[i];
    dp[1]=arr[1];
    dp[2]=max({arr[1]+arr[2]/2,arr[2],dp[1]});
    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-1],max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]/2));
    }
    cout << dp[n];
    return 0;
}