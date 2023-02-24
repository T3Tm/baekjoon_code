#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/10812
    10812번 바구니 순서 바꾸기
    i,j
    i, i +1 , k-1, k ,k +1,j-1,j
    k,k+1,j-1,j,i,i+1

*/
using namespace std;
int n,m;
int arr[102];
void change(int x,int y,int k){
    int temp[102]={0};
    int i=x;
    for(int z=k;z<=y;z++,i++){
        temp[i]=arr[z];
    }
    for(int z=x;z<=k;z++,i++){
        temp[i]=arr[z];
    }
    for(int i=x;i<=y;i++){
        arr[i]=temp[i];
    }
}
int main(){
    fast;
    cin >> n >> m;
    for(int i=1;i<=n;i++)arr[i]=i;
    while(m--){
        int i,j,k;
        cin >> i >> j >> k;
        change(i,j,k);
    }
    for(int i=1;i<=n;i++)cout << arr[i] << ' ';
    return 0;
}