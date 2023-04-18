#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1041
	1041번 주사위
*/
using namespace std;
int n;
long long arr[8];//6개의 입력
long long answer;
int main() {
	fast; cin >> n;
	int total = 0;
	for (int i = 0; i < 6; i++)cin >> arr[i], total += arr[i];
	if (n != 1) {
		long long one = *min_element(arr, arr + 6);
		long long two = 1000;
		for (int i = 1; i < 5; i++)two = min({ two,arr[0] + arr[i], arr[5] + arr[i] });
		for (auto [x, y] : { pair{1,2},pair{1,3},pair{2,4},pair{3,4} }) {
			two = min(two, arr[x] + arr[y]);
		}
		long long three = 1500;
		for (auto [x, y] : { pair{1,2},pair{1,3},pair{2,4},pair{3,4} }) {
			three = min({ three,arr[0] + arr[x] + arr[y],arr[5] + arr[x] + arr[y] });
		}
		answer = 4 * three + two * 4 * (n - 1 + n - 2) + one * (n - 2) * ((n - 1) * 4 + n - 2);
	}
	else answer = total - *max_element(arr, arr + 6);
	cout << answer;
	return 0;
}