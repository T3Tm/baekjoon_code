#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
/*
https://www.acmicpc.net/problem/1874
1874번 스택 수열
*/

using namespace std;
int n;
int main(){
    fast;cin >> n;
    stack<int>s;
    int arr[100002]{};
    for(int i=0;i<n;i++)cin >> arr[i];
    vector<string>result;
    int idx=0;
    for(int i=1;i<=n;i++){
        s.push(i);
        result.push_back("+");
        while(!s.empty() && s.top()==arr[idx]){
            result.push_back("-");
            s.pop();
            idx++;
        }
    }
    while(!s.empty()){
        if(s.top()==arr[idx]){
            result.push_back("-");
            s.pop();
            idx++;
        }else{
            result.clear();
            result.push_back("NO");
            break;
        }
    }
    for_each(result.begin(),result.end(),[](string &a){cout << a << endl;});
}