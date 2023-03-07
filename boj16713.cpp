#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
    https://www.acmicpc.net/problem/16713
    16713번 Generic Queries
    XOR이란?
    둘이 다르면 1
    같으면 0   
    2.5초
    길이가 N인 수열 
    as_i,as_i+1~ae_i까지 모두 XOR한 값이다.
    xor연산 같은 경우 똑같은 걸로 해서 -연산같이 진행하면 된다.
    모든 쿼리의 답을 XOR한 값을 출력하시오.
*/
using namespace std;
int n,q;
long long arr[1000002];
long long result;
int main(){
    fast;
    cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> arr[i];
    for(int i=2;i<=n;i++)arr[i]=arr[i-1]^arr[i];
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        result^=arr[b]^arr[a-1];
    }
    cout << result;
}