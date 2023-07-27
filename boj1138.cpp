#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
/*
 * https://www.acmicpc.net/problem/1138
 * 1138번 한줄로 서기
 * 그리디하게 낮은 0부터 하나씩처리
 *
 * */
using namespace std;
int main(){
    fast;
    int n;cin >> n;
    int arr[12]{};
    for(int i=0;i<n;i++)cin >> arr[i];

    bool visited[12]{};
    int result[12]{};
    int insert=0;
    int Max=10;
    while(Max--){
        for(int i=0;i<n;i++){
            if(arr[i]==0 && !visited[i]){
                result[insert++]=i+1;
                for(int j=0;j<i;j++)arr[j]=max(arr[j]-1,0);//하나씩 앞에 큰 거 땡겨주기
                visited[i]=true;
                break;
            }
        }
    }
    for_each(result,result+n,[](int& t){cout << t << ' ';});
}