#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/11723
    11723번 집합
    
    1. add  | 이라는 연산자를 이용하여 나타내면 된다.
    2. remove  제거는 & 를 이용
    3. check w
*/
            
using namespace std;
int result,l,inputs;
int bitCount(int a){
    if(!a)return 0;
    return a%2+bitCount(a/2); 
}
int main(){
    fast;cin >> l;
    while(l--){
        string a;cin >> a;
        if(a[0]=='a'){
            if(a[1]=='d'){
                cin >> inputs;
                result|=(1<<inputs);
            }else{
                result=-1;
            }
        }else if(a[0]=='r'){
            cin >> inputs;result&=~(1<<inputs);
        }else if(a[0]=='c'){
            cin >> inputs;
            cout << (result&(1<<inputs)?1:0) <<endl;
        }else if(a[0]=='t'){
            cin >> inputs;result^=(1<<inputs);
        }else{
            result=0;
        }
    }
}