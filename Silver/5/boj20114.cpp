#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/20114
    20114 
    
*/
using namespace std;
int main(){
    fast;
    int n,h,w;
    cin >> n>>h>>w;
    vector<char>result(n,'?');
    for(int i=0;i<h;i++){
        string temp;
        cin >> temp;
        for(int idx=0;idx<temp.size();idx++){
            if(temp[idx]!='?')result[idx/w]=temp[idx];
        }
    }
    for(auto &value :result){
        cout << value;
    }
    return 0;
}