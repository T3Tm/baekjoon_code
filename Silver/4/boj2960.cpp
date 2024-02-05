#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cout.tie(nullptr),cin.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2960
	2960번 에라토스테네스의 체
*/
using namespace std;
int n, k;
int arr[1002] = { true,true };
int main() {
	fast;
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) {
			arr[i] = true;
			k--;//
			if (!k) {
				cout << i;
				break;
			}
			for (int j = i * 2; j <= n; j += i) {
				if (!arr[j]) {
					k--;
					arr[j] = true;
				}
				if (!k) {
					cout << j;
					goto EXIT;
				}
			}
		}
	}
EXIT:
	return 0;
}