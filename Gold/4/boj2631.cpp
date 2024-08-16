#include <bits/stdc++.h>
using namespace std;

/*
    
*/
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    int arr[202]{};
    for(int i=0;i<n;i++)cin >> arr[i];

    int dp[202]{};//i번째 j번째

    for(int i=0;i<n;i++){
        int now{0};
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                now = max(now, dp[j]);
            }
        }
        dp[i] = now + 1;
    }
    cout << n - *max_element(dp,dp+n);
    return 0;
}