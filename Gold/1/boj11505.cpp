#include <bits/stdc++.h>
using namespace std;

/*
    현재 문제: 11505번
*/
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 1;
int n, m, k;
int tree[SIZE * 2];

void init(){
    for(int i = n-1;i > 0;i--)tree[i] = (1LL * tree[i << 1] * tree[i << 1 | 1])%MOD;
}

void update(int b, int c){
    for(tree[b+=n] = c; b > 1;b>>=1)tree[b >> 1] = (1LL * tree[b] * tree[b^1])%MOD;
}

int query(int l, int r){
    int ret{1};

    for(l+=n, r+=n;l<r;l>>=1, r>>=1){
        if(l&1)ret = (1LL * ret * tree[l++])%MOD;
        if(r&1)ret = (1LL * ret * tree[--r])%MOD;
    }

    return ret;
}

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=n;i<2 * n; i++){
        cin >> tree[i];
    }

    init();

    for(int i=0;i<m+k;i++){
        int a,b,c;cin >> a >> b >> c;
        if(a&1){
            update(b-1,c);
        }else{
            cout << query(b-1,c) << '\n';
        }
    }
    return 0;
}