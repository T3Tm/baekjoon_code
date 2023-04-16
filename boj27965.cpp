#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
*	https://www.acmicpc.net/problem/27965
*	27965번 N결수

*/
using namespace std;
inline long long mypow(int c, int k) {
	long long tmp = 1;
	for (int i = 0; i < c; i++)tmp = tmp * 10 % k;
	return tmp;
}
int main() {
	fast;
	long long n, k; cin >> n >> k;
	long long tmp = 0;
	for (int i = 1; i <= n; i++) {
		int j = i;//진적 수 길이 구하기.
		int len = 0;
		while (j) {
			j /= 10, len++;
		}
		tmp = ((tmp * mypow(len, k) % k) + i) % k;
	}
	cout << tmp % k;
	return 0;
}