#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
 https://www.acmicpc.net/problem/14002
 14002번 가장 긴 증가하는 부분 수열
*/
using namespace std;
int n,arr[1002],dp[1002];
vector<int>dps{0};
int main() {
    fast;cin >> n;
    for(int i=0;i<n;i++){
        int num;cin >> num;
        arr[i]=num;
        if(dps.back()<num){
            dp[i] = dps.size();
            dps.push_back(num);
        }else{//
            auto it = lower_bound(dps.begin(),dps.end(),num);
            int idx=it-dps.begin();
            dp[i] = idx;
            *it=num;
        }
    }
    vector<int>result;
    cout << dps.size()-1 << endl;
    for(int i=n-1;i>=0;i--){
        if(dps.size()-result.size()== dp[i]+1){
            result.push_back(arr[i]);
        }
    }
    for(auto it=result.rbegin();it!=result.rend();it++)cout << *it << ' ';
    return 0;
}