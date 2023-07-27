#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
/*
 * https://www.acmicpc.net/problem/18111
 * 18111번 마인크래프트
 * */
using namespace std;
int main(){
    fast;
    int n,m,b;cin >> n >> m >> b;
    int arr[502][502]{};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int time=-1,result_h=0;
    for(int h=0;h<=256;h++){
        int inner_b=b;//초기 b상태
        int inner_Time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]>h){//블럭이 더 많이 쌓여있음
                    inner_Time+=2*(arr[i][j]-h);
                    inner_b+=arr[i][j]-h;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]<h){//설정한 높이가 더 크면 인벤토리에서 갖고 와야하는데 없으면 정답으로 만들면 안됨
                    if(h-arr[i][j]>inner_b){//못 쌓음 ㅈㅈ
                        inner_Time=-1;
                        goto EXIT;
                    }
                    inner_Time+=h-arr[i][j];
                    inner_b-=h-arr[i][j];
                }
            }
        }
        if(inner_Time==-1)continue;
        if(time>inner_Time){
            time=inner_Time;
            result_h=h;
        }
        else if(time==inner_Time){
            result_h=h;
        }
        else if(time==-1){
            time=inner_Time;
            result_h=h;
        }
    EXIT:;
    }
    cout << time << ' ' << result_h;
}