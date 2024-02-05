#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
 https://www.acmicpc.net/problem/17218
 17218번 비밀번호 만들기
 갱신될 때마다 문자를 가져간다.. 이전 최고 문자를 가져간다.
*/
using namespace std;
int dp[43][43];
int main() {
    fast;
    string a,b;cin>> a>>b;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]){//
                dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j-1]);
            }else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string answer;
    int last=dp[a.size()][b.size()];
    int a_start=a.size(),b_start=b.size();
    for(int i=a_start;i>=1;i--){
        for(int j=b_start;j>=1;j--){
            if(a[i-1]==b[j-1]  && last == dp[i][j]){//이럴 때
                answer.push_back(b[j-1]);
                b_start=j-1;
                a_start=i-1;
                last--;
                break;
            }
        }
    }
    reverse(answer.begin(),answer.end());
    cout << answer;
    return 0;
}
