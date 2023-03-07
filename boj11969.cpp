#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/11969
    11969번 Breed Counting

*/
using namespace std;
int n,q;
int arr[100002][4];
int main(){
    fast;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int breedID;
        cin >> breedID;
        arr[i][1]=arr[i-1][1];
        arr[i][2]=arr[i-1][2];
        arr[i][3]=arr[i-1][3];
        arr[i][breedID]++;
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        for(int i=1;i<4;i++)cout << arr[b][i]-arr[a-1][i] << ' '; 
        cout << endl;
    }
    return 0;
}