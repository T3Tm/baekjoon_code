#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/1120
    1120번 문자열
    len(A) <= len(B)
    
    DP + 그리디
    
    LCS
    longest Common sequence
*/
using namespace std;
string x,y;
int main(){
    fast;
    int result=52;
    cin >> x >> y;
    for(int i=0;i<(y.size()-x.size()+1);i++){//O(n^2)
        int cnt=0;
        for(int idx=0,j=i;idx<x.size();idx++){
            if(x[idx]!=y[j+idx]){
                cnt++;
            }
        }
        result=min(cnt,result);
    }
    cout << result;
    return 0;
}