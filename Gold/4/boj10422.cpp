#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/10422
    10422번 괄호
*/
int n;
long long dp[2502];
int MOD = 1'000'000'007;
void inputs() {
}
long long PreComputation(int num) {
    if (dp[num] != -1) return dp[num];
    dp[num] = 0;
    for (int i = 0; i < num; i++) {
        dp[num] = (dp[num] + PreComputation(i) * PreComputation(num - 1 - i)) % MOD;
    }
    return dp[num];
}
void solve() {
    memset(dp, -1, sizeof dp);
    dp[0] = dp[1] = 1;
    PreComputation(2500);
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        cout << (a & 1 ? 0 : dp[a / 2]) << endl;
    }
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    solve();
    return 0;
}