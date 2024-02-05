#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
 https://www.acmicpc.net/problem/2229
 2229번 조 짜기
 
 2번 아이는 앞에 있는 아이들과 조를 짤 때 0번과 짤 수도 있고 1번과 짤 수 있다.
 
 1번과 짠다면
 dp[i] = dp[:i] + value;
*/
using namespace std;
int n,arr[1005],dp[1005];
int main() {
    fast; cin >> n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++){
        int m=arr[i],M=arr[i];
        for(int j=i;j<=n;j++){
            m=max(m,arr[j]);//최댓값 갖고 오기6
            M=min(M,arr[j]);//최솟값 갖고 오기
            dp[j]=max(m-M+dp[i-1],dp[j]);
        }
    }
    cout << dp[n];
    return 0;
}