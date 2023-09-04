#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/2493
    2493번 탑
    즉 좌큰수를 알아내시오라는 문제
    오른쪽부터 시작해서 자기를 넣고 자기보다 큰 아이가 나오면 그 값을 출력해주면 된다.            
*/
using namespace std;
int n;
int main(){
    fast;cin >> n;
    int arr[500002]{};
    for(int i=0;i<n;i++)cin >> arr[i];
    
    vector<int>result(n);
    stack<int>s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()]<arr[i]){
            int idx = s.top();s.pop();
            result[idx]=i+1;
        }
        s.push(i);
    }
    for_each(result.begin(),result.end(),[](int&v){cout << v << ' ';});
}