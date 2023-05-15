#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
 https://www.acmicpc.net/problem/1817
 1817번 짐 챙기는 숌
 앞에서부터 차례대로 넣는다.
 
*/
using namespace std;
int n,m;
int main() {
    fast;cin >> n >> m;
    int total=0,answer=1;
    for(int i=1;i<=n;i++){
        int num;cin >> num;
        total+=num;
        if(total>m){
            answer++,total=num;
        }
    }
    cout << (n==0?0 :answer);
    return 0;
}
