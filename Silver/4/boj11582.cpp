#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin >> arr[i];

    int k;cin >> k;
    
    int front{};
    for(int i{},cnt{};i<n;i++){
        cnt++;
        if(cnt != n/k)continue;
        
        sort(arr + front, arr + i + 1);
        front += cnt;
        cnt = 0;   
    }
    for(int i=0;i<n;i++)cout << arr[i] << ' ';
    return 0;
}