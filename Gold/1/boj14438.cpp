#include <bits/stdc++.h>

using namespace std;
const int SIZE = 100000 * 2 + 1;

int tree[SIZE];
//1 l r l을 r로 바꾸기
//2 l r
int n;
void init(){//
    for(int i=n-1;i>0;i--)tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
}

void update(int l, int v){
    for(tree[l+=n] = v;l > 1;l >>= 1)tree[l >> 1] = min(tree[l], tree[l ^ 1]);
}
int query(int l, int r){
    int ret = 0x3f3f3f3f;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)ret = min(ret, tree[l++]);
        if(r&1)ret = min(ret, tree[--r]);
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    memset(tree, 0x3f, sizeof tree);
    cin >> n;
    for(int i = n;i<2*n;i++)cin >> tree[i];
    init();
    

    
    int m;cin >> m;
    while(m--){
        int cmd,l,r;
        cin >> cmd >> l >> r;
        if(cmd == 1){
            update(l-1,r);
        }else{
            cout << query(l-1,r)<<'\n';
        }
    }
    return 0;
}