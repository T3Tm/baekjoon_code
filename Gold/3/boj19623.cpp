#include<bits/stdc++.h>
using namespace std;
struct D{
    int x,y,v;
};
bool cmp(const D&a,const D&b){
    if(a.y==b.y)return a.x < b.x;
    return a.y < b.y;
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    int n;cin >> n;
    int dp[100002]{};
    vector<D>arr(n+1);
    map<int,int,greater<int>>idx{{0,0}};
    int ret = 0;
    for(int i=1;i<=n;i++){
        cin >> arr[i].x >> arr[i].y >> arr[i].v;
    }
    sort(arr.begin(),arr.end(),cmp);
    for(int i=1;i<=n;i++){
        auto it = idx.lower_bound(arr[i].x);
        dp[i] = max(dp[i-1],dp[(*it).second] + arr[i].v);
        idx[arr[i].y] = i;
    }
    cout << dp[n];
}