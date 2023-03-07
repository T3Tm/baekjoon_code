#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
 * https://www.acmicpc.net/problem/17203
 * 17203번 ∑|ΔEasyMAX|
 * 초당 박자 변화량의 합
 * 특정 부분들의 구간별 초당 박자 변화량의 합 구하자.
 * ak+1 - ak 라고 정의하고 j-1<i 경우 ak+1 - ak = 0
 * 
 * j - |aj+1-aj|
 * prefix[2] = a2-a1
*/
using namespace std;
int n,q;//2000*999
int arr[1002];
int prefix[1002];
int main(){
    fast;
    cin >> n >> q;
    for(int i=0;i<n;i++)cin >> arr[i];
    for(int i=2;i<=n;i++){//1~2초
        prefix[i]=prefix[i-1]+abs(arr[i-1]-arr[i-2]);
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        if(b-1<a)cout << 0 << endl;
        else{
            cout << prefix[b]-prefix[a] << endl;
        }
        
    }
    return 0;
}