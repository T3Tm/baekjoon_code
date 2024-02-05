#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/17390
   17390번 이건 꼭 풀어야 해!
    
*/      
using namespace std;
int n,q;
int prefix[300002];
int main(){
    fast;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> prefix[i];//n
    }
    sort(prefix,prefix+n);
    for(int i=1;i<n;i++)prefix[i]+=prefix[i-1];// n
    while(q--){//n
        int a,b;
        cin >> a >> b;
        if(a==1)cout << prefix[b-1] << endl;
        else cout << prefix[b-1]-prefix[a-2] << endl;
    }
    return 0;
}