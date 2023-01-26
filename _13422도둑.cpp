#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/13422
	도둑
	누적합
*/
using namespace std;
int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int>arr(n,0);
		vector<int>prefix(2 * n +1, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			prefix[i+1] = arr[i];
			prefix[i+1+n] = arr[i];
		}
		for (int i = 1; i < n + m; i++) prefix[i] += prefix[i - 1];
		int cnt = 0;
		for (int i = m; i < n + m; i++) {
			if (prefix[i] - prefix[i - m] < k)cnt++;
		}
		if (m == n)cnt /= m; //m과 n이 같으면 같은 쌍들이 m번 나옴
		cout << cnt << endl;
	}
	return 0;
}