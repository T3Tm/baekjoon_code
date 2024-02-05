#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/1546
    1546번 평균
*/
using namespace std;
int n;
int arr[1002];
int maximum=0;
int main(){
    fast;
    cin >> n;
    double sum=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        maximum=max(maximum,arr[i]);
    }
    for(int i=0;i<n;i++){
        sum+=((double)arr[i]/maximum*100);
    }
    cout << sum/n;
    return 0;
}