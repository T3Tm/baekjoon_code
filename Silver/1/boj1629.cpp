#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
  https://www.acmicpc.net/problem/1629
  1629¹ø °ö¼À
*/
using namespace std;
using ll = long long;
int a, b, c;
ll divpow(ll a, ll b, ll c) {
	if (b == 0)return 1;
	else if (b == 1)return a%c;

	if (b % 2 == 0)return divpow(a, b / 2, c) % c * divpow(a, b / 2, c) % c;
	else return divpow(a, b / 2, c) % c * divpow(a, b / 2, c) % c * a % c;
}
void solve() {
	ll result = divpow(a, b, c);
	cout << result;
}
int main() {
	fast;
	cin >> a >> b >> c;
	solve();
	return 0;
}