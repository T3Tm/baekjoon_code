#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    
    1. n/2명을 뽑는다.
    2. n-n/2명을 따로 뽑는다.
    3. 뽑은 아이들의 값을 구한다.
    4. 그 값의 차이를 계산한다.
    5. 최소를 구한다.
    
*/
            
using namespace std;
int n;
vector<int>pick;
vector<vector<int>>arr;
int w[22];
int output=INT_MAX;
void hap(int &result,int *value,int s){
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(i==j)continue;
            result+=arr[value[i]][value[j]];
        }
    }
}
void picked(int* result,int last,int idx=0,int depth=0){
    if(depth==last){
        //두 개씩 뽑아서 더해내기
        int first=0,second=0;
        hap(first,result,last);
        int inner[22]{},check=0;
        int inneridx=0;
        for(int i=0;i<n;i++){
            if(result[check]==i)check++;
            else inner[inneridx++]=i;
        }
        hap(second,inner,n-last);
        output=min(output,abs(first-second));
        return;
    }
    for(int i=idx;i<n;i++){
        result[depth]=i;
        picked(result,last,i+1,depth+1);
        result[depth]=-1;
    }
}
int main(){
    fast;cin >> n;
    arr.resize(n,vector<int>(n));
    for(auto &row:arr)for(auto &v:row)cin >> v;
    pick.resize(n);
    for(int i=1;i<=n/2;i++){
        picked(w,i);
    }
    cout << output;
}