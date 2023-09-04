#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/6549
    6549번 히스토그램에서 가장 큰 직사각형
    
    작은 값을 유지할 수 있도록
    
    왼쪽부터 시작해서
    자기보다 작은 값이 나오면 자신의 인덱스에다가 * 현재 i 곱해서 계산하면 직사각형 나옴
    결과는 result로 나오게 함.
*/
typedef long long ll;
using namespace std;
int main(){
    fast;
    while(1){
        int n;cin >> n;
        if(n==0)break;
        ll arr[100003]{};
        for(int i=1;i<=n;i++)cin >> arr[i];
        stack<pair<int,int>>s;//자신보다 큰 값이면 나가긴 하나 자기보다 큰 값을 오른쪽에 계속 저장
        ll result=0;
        int maxInsert=0;
        for(int i=1;i<=n;i++){
            maxInsert=i;
            while(!s.empty() && arr[s.top().first] >= arr[i]){
                auto[idx,maxIdx]=s.top();s.pop();
                result=max(result,(i-maxIdx)*arr[idx]);//큰 것은 지금까지의 값을 계산
                maxInsert=maxIdx;
            }
            s.push({i,maxInsert});
        }
        while(!s.empty()){
            auto[idx,maxIdx]=s.top();s.pop();
            result=max(result,(n-maxIdx+1)*arr[idx]);
        }
        cout << result << endl;
    }
}