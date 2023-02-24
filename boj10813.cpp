#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/10813
    10813번 공 바꾸기
*/
using namespace std;
int n,m;
int arr[102];
int main(){
    fast;
    cin >> n >> m;
    for(int i=1;i<=n;i++) arr[i]=i;
    while(m--){
        int i,j;
        cin >> i >> j;
        swap(arr[i],arr[j]);
    }
    for(int i=1;i<=n;i++)cout << arr[i] << ' ';
    return 0;
}