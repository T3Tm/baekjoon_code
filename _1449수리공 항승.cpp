#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/1449
	수리공 항승
*/
int main() {
	fast;
	int n, l;
	cin >> n >> l;
	int totalTape = 1;
	int attachTape = l - 1;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int minloc = arr[0], maxloc = arr[0] + l - 1;
	for (int i = 1; i < n; i++) {
		if (minloc <= arr[i] && arr[i] <= maxloc && attachTape) attachTape--;
		else {
			totalTape++;
			attachTape = l - 1;
			maxloc = arr[i] + l - 1;
			minloc = arr[i];
		}
	}
	cout << totalTape;
	return 0;
}