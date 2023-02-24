#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/10810
    10810번 공 넣기
*/
using namespace std;
int n,m;
int arr[102];
int main(){
    fast;
    cin >> n >> m;
    while(m--){
        int i,j,k;
        cin >> i >> j >> k;
        for(int idx=i;idx<=j;idx++)arr[idx]=k;
    }
    for(int i=1;i<=n;i++)cout << arr[i] << ' ';
    return 0;
}