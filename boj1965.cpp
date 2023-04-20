#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1965
	1965번 상자넣기

	상자의 크기가 뒤에 있는 상자의 크기보다 작으면, 앞에 있는 상자를 뒤에 있는 상자 안에 넣을 수 있다.
	1,5,2,3,7
*/
using namespace std;
int n;
int dp[1002];
int main() {
	fast; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		dp[num] = *max_element(dp, dp + num) + 1;
	}
	cout << *max_element(dp, dp + 1002);
	return 0;
}