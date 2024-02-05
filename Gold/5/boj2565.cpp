#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2565
	2565번 전깃줄

	A와 B사이에 하나 둘씩 전깃줄을 추가하니 서로 교차하는 경우가 발생

	몇 개의 전깃줄을 없애서 교차하지 않도록 만들 거임.
*/
using namespace std;
int n;
struct myarr {
	int a, b;
	bool operator<(const myarr& b) {
		return a < b.a;
	}
};
myarr arr[102];
int dp[502];
int main() {
	fast; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr[i] = { a,b };
	}
	sort(arr, arr + n);//오름차순으로 하자
	for (int i = 0; i < n; i++) {//작은a부터 b에 최고로 연결이 많이 되는 것을 알아보자
		dp[arr[i].b] = *max_element(dp, dp + arr[i].b) + 1;
	}
	cout << n - *max_element(dp, dp + 502);
	return 0;
}