#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
/*
 * https://www.acmicpc.net/problem/3020
 * 3020번 개똥벌레
 * Upper_bound - lower_bound = 정답

 * */
using namespace std;
int n,h;
int main(){
    fast;cin >> n >> h;
    int bottom[100002]{};
    int top[100002]{};
    int top_idx=0,bottom_idx=0;
    for(int i=0;i<n;i++){
        if(i%2) cin >> top[top_idx++];
        else cin >> bottom[bottom_idx++];
    }
    auto cmp=[](int &a,int &b)->bool{return a<b;};
    sort(top,top+top_idx,cmp);
    sort(bottom,bottom+bottom_idx,cmp);
    int cnt=0;
    int result=n;
    for(int mid=1;mid<=h;mid++){
        auto it=lower_bound(bottom,bottom+bottom_idx,mid);
        auto it2 = lower_bound(top,top+top_idx,h-mid+1);
        int cnt1=bottom_idx-(it-bottom);
        int cnt2=top_idx-(it2-top);
        if(cnt1+cnt2<result){
            result=cnt1+cnt2;
            cnt=0;
        }
        if(result==cnt1+cnt2)cnt++;
    }
    cout << result << ' ' << cnt;
}