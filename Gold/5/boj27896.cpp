#include <bits/stdc++.h>//
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*

	https://www.acmicpc.net/problem/27896
	27896번 특별한 서빙
*/
using namespace std;
int n, m;
long long sum = 0;
int cnt = 0;
priority_queue<int>value;
int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		sum += number;
		value.push(number);
		if (sum >= m) {
			while (sum >= m) {
				sum -= (value.top() * 2); value.pop();
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}