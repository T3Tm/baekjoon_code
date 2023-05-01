#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
*	https://www.acmicpc.net/problem/1026
* 1026번 보물
*/
using namespace std;
int main() {
	fast; int a[52]{}, b[52]{}, n; cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++)cin >> b[i];
	sort(a, a + n);
	sort(b, b + n, [](int& a, int& c) {return a > c; });
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	cout << sum;
	return 0;
}