#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<long long>tree;
void init(){
    for(int i=n-1; i > 0;i--)tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

void update(int p, long long val){
    for(tree[p += n] = val; p > 1; p >>= 1) tree[p >> 1] = tree[p] + tree[p^1];
}

//[l, r)
long long query(int l, int r){
    long long ret{};
    for(l += n , r += n; l < r; l >>= 1, r >>= 1){
        if(l&1)ret += tree[l++];
        if(r&1)ret += tree[--r];
    }
    return ret;
}

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    tree.resize(n * 2);

    for(int i=n;i<2 * n;i++){
        cin >> tree[i];
    }

    init();
    for(int i=0;i<m + k;i++){
        int cmd;cin >> cmd;
        if(cmd == 1){
            int p;long long v;
            cin >> p >> v;
            update(p-1,v);
        }else{
            int l,r;cin >> l >> r;
            cout << query(l-1,r) << '\n';
        }
    }
    
    return 0;
}