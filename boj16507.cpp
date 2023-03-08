#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/16507
    16507번 어두운 건 무서워
    O(nm)이면 가능

*/
using namespace std;
int r,c,q;
int arr[1002][1002];
int main(){
    fast;
    cin >> r >> c >> q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=1;j<c;j++){
            arr[i][j]+=arr[i][j-1];
        }
    }
    while(q--){//queries Queries
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int total=0;
        for(int i=r1-1;i<r2;i++){
            if(c1-2<0)total+=arr[i][c2-1];
            else total+=arr[i][c2-1]-arr[i][c1-2];
        }
        cout << total/((r2-r1+1)*(c2-c1+1)) << endl;   
    }
    return 0;
}