#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1817
	짐 챙기는 숌
*/
using namespace std;
int main() {
	fast;
	int n, m;
	cin >> n >> m;
	int cnt;
	if (n == 0)cnt = 0;
	else cnt = 1;
	vector<int>arr(n,0);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int prelength = 0;
	for (int i = 0; i < n; i++) {
		if (prelength + arr[i] > m) {
			cnt++;
			prelength = arr[i];
		}
		else prelength += arr[i];
	}
	cout << cnt;
	return 0;
}