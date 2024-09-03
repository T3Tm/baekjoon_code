#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1000001;
long long tree[2*SIZE];
int n,m;
void update(int i,long long k){
    for(tree[i+=n]=k;i>1;i>>=1)tree[i>>1] = tree[i] + tree[i^1];
}
long long query(int i, int j){
    long long ret{};
    for(i+=n,j+=n;i<j;i>>=1,j>>=1){
        if(i&1)ret+=tree[i++];
        if(j&1)ret+=tree[--j];
    }
    return ret;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for(int p=0;p<m;p++){
        int cmd, i, j ;cin >> cmd >> i >> j;
        if(!cmd){
            if(i > j)swap(i,j);
            cout << query(i-1,j) << '\n';
        }else{
            update(i-1,j);
        }
    }
    return 0;
}