#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2217
	2217번 로프
	1. 각각의 최소가 * 갯수 했을 때 가능한지 판별해야되지 않나
	2.
*/
using namespace std;
int n;
int arr[100002];
int main() {//해당하는 최소에 
	fast;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	int maxvalue = 0;
	for (int i = 0; i < n; i++) {
		maxvalue = max(maxvalue, arr[i] * (n - i));
	}
	cout << maxvalue;
	return 0;
}