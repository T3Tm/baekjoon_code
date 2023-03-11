#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/4134
    4134번 다음 소수
*/
using namespace std;
bool prime(int n){
    if(n==1)return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }    
    return true;
}
int n;
int main(){
    fast;
    cin >> n;
    while(n--){
        int number;
        cin >> number;
        for(int i=number;;i++){
            if(prime(i)){
            cout << i << endl;
            break;
            }
        }
    }
    return 0;
}