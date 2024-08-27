#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[1005][1005];
int v[2][1005];
int dfs(int x, int y){
    if(y == n)return 0;
    if (x == m)return 0x3f3f3f3f;
    if (dp[x][y] != -1)return dp[x][y];

    dp[x][y] = min(dfs(x+1,y), dfs(x+1,y+1)+abs(v[1][x] - v[0][y]));
    return dp[x][y];
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    memset(dp, -1, sizeof dp);

    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> v[0][i];
    for(int i=1;i<=m;i++)cin >> v[1][i];

    sort(v[0]+1,v[0]+n+1);
    sort(v[1]+1,v[1]+m+1);

    if(m < n){//m이 무조건 큰 것
        swap(n,m);
        swap(v[0],v[1]);
    }
    n++,m++;
    cout << dfs(1,1);
    return 0;
}