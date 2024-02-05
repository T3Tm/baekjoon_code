#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
 * https://www.acmicpc.net/problem/10211
 * 10211번 Maximum Subarray
 * 
*/
using namespace std;
int main(){
    fast;
    int t;
    cin >> t;
    while(t--){
        int n,arr[1002]={0},result=-1001;
        cin >> n;
        for(int i=0;i<n;i++)cin >> arr[i];
        int prefix[1003]={0,arr[0]};
        for(int i=2;i<=n;i++){
            prefix[i]=prefix[i-1]+arr[i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                result=max(result,prefix[i]-prefix[j-1]);
            }
        }
        cout << result << endl;
    }
    return 0;
}