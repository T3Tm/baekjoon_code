#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
/*
 * https://www.acmicpc.net/problem/2110
 * 2110번 공유기 설치
 * 공유기 사이의 거리를 최대로 해야 되기에
 * 하나의 거리를 n이라고 하고 parametric search 하면 될듯
 * */
using namespace std;
int main(){
    fast;
    int n,c;cin >> n >> c;
    vector<int>arr(n);
    for(auto&i:arr)cin >> i;
    sort(arr.begin(),arr.end(),[](int& a,int& b)->bool{return a<b;});
    int left=1,right=1'000'000'000;//거리가 1부터
    while(left<=right){
        int gap=(left+right)/2;
        int first=arr[0];//
        int count=1;
        for(int i=1;i<n;i++){
            if(first+gap<=arr[i]){
                count++;
                first=arr[i];
            }
        }
        if(count<c){//설치 못함
            right=gap-1;
        }else{
            left=gap+1;
        }
    }
    cout << right;
}