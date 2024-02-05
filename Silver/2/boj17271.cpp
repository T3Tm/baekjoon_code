#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
 https://www.acmicpc.net/problem/17271
 17271번 리그 오브 레전설 (Small)
 N초 동안 A,B를 이용해서 만들 수 있는 조합들
 dp랑 백트래킹을 이용해서 풀 수 있을 듯
 dp를 이용해서 일단 풀어보자.
*/
using namespace std;
const int MOD=1e9+7;
long long dp[10003];
int n,m;
int main() {
    fast;cin >> n >> m;memset(dp,-1,sizeof dp);
    for(int i=m;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-m])%MOD;
    }
    cout << (dp[n]==-1 ? 1 : -dp[n]);
    return 0;
}
