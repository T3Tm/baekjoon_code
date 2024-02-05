#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1339
	1339번 단어 수학
*/
using namespace std;
int arr[30];
inline long long intpow(int n) {
	long long temp = 1;
	for (int i = 0; i < n; i++) {
		temp *= 10;
	}
	return temp;
}
int main() {
	fast;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string a; cin >> a;
		for (int i = 0; i < a.size(); i++) {
			arr[a[i] - 'A'] += intpow(a.size() - i - 1);
		}
	}
	sort(arr, arr + 30, [](const int& a, const int& b) {return a > b; });
	long long answer = 0;
	for (int i = 9; i >= 1; i--) {
		answer += arr[9 - i] * i;
	}
	cout << answer;
	return 0;
}