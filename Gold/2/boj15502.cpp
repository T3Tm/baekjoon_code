#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/15502
    k-균등 문자열
    k균등하기 위해 i번째와 i+k번째 문자열이 같아야 한다.
*/
typedef long long ll;
int n, m;
const ll MOD = 1000000007;
int parent[1002];
int find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = find(parent[x]);
}
void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x > y) {
        parent[x] = y;
    } else if (x < y) {
        parent[y] = x;
    }
}
ll llpow(int base, int exponent) {
    if (exponent == 1) return base;
    ll ret = llpow(base, exponent / base) % MOD;
    if (exponent % 2) {
        return (ret * ret * base) % MOD;
    }
    return (ret * ret) % MOD;
}
void inputs() {
    cin >> n >> m;
    int a, b, k;
    memset(parent, -1, sizeof(int) * (n + 1));
    while (m--) {
        cin >> a >> b >> k;
        for (int i = a; i + k <= b; i++) {
            merge(i, i + k);
        }
    }
}
void solve() {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) {
            count++;
        }
    }
    cout << llpow(2, count) % MOD;
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    inputs();
    solve();
    return 0;
}