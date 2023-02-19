#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
 * https://www.acmicpc.net/problem/2531
 * 2531 회전 초밥
 * 회전초밥 deque를 이용하면 좋겠네
 * 같은 종류의 초밥이 둘 이상 있을 수 있음.
 * 
 * 1. 최대로 k+1개 먹을 수 있다.
 * 2. 
*/
using namespace std;
int main(){
    fast;
    int n,d,k,c;
    cin >> n >> d >> k >>c;
    vector<int>arr(2*n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        arr[i+n]=arr[i];
    }
    int result=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        bool bits[30001]={false};
        for(int j=i;j<i+k;j++){
            if(!bits[arr[j]]){
                cnt++;
                bits[arr[j]]=true;
            }
        }
        if(!bits[c])cnt++;
        result=max(result,cnt);
    }
    cout << result;
    return 0;
}