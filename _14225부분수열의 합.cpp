#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/14225
	부분수열의 합
*/
int bit[2000001];
int main() {
	fast;
	int n;
	cin >> n;
	vector<int>array(n);
	for (int i = 0; i < n; i++)cin >> array[i];
	for (int i = 1; i <= n; i++) {
		vector<int>pick(n-i,0);
		for (int j = 0; j < i; j++) pick.push_back(1);
		do {
			int total = 0;
			for (int idx = 0; idx < n; idx++) {
				if (pick[idx])total += array[idx];
			}
			bit[total] = 1;
		} while (next_permutation(pick.begin(), pick.end()));
	}
	for (int i = 1; i < 2000001; i++) {
		if (!bit[i]) {
			cout << i;
			break;
		}
	}
	return 0;
}