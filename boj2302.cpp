#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
/**
    https://www.acmicpc.net/problem/2302
    2302번 극장 좌석
    
    N개가 있을 때 (40)
    M개의 고정석이 있다. (0)개라고 하면

    1,2,3,4,n-1,n
    3 1 2 1 1 2 1 => 12

    1 => 1가지

    1,2 => 2가지

    1,2,3 => 3

    1 => 2가지
    2,1,3 => 1가지

    1,2,3,4 => 5


    1,2,3,4,5 => 8가지

    1 => 5가지
    2,1 =>3가지

    DP문제네?


*/
using namespace std;
int n,m;
long long dp[42]={1,1,2};
long long result=1;
bool bit[42];
int main(){
    fast;
    cin >> n >> m;
    for(int i=3;i<=40;i++) dp[i]=dp[i-1]+dp[i-2];
    int start=1;
    while(m--){
        int idx;
        cin >> idx;
        bit[idx]=true;    
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(bit[i]){
            result*=dp[cnt];
            cnt=0;
        }else{
            cnt++;
        }
    }
    if(cnt)result*=dp[cnt];
    cout << result;
    return 0;
}