#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/5671
	호텔 방 번호
	투숙객에게 불운이 찾아오는 것을 피하기 위해서 
	반복되는 숫자가 없게 방 번호를 만들려고 한다.

	정부는 선영이의 호텔 방 번호는 N보다 크거나 같고, M보다 작거나 같아야한다.
	87,89,90,91,92,93,94,95,96,97,98,102,103,104
*/
using namespace std;
bool check(int n) {
	bool number[10] = { false };
	while (n) {
		if (number[n % 10])return false;
		number[n % 10] = true;
		n /= 10;
	}
	return true;
}
int main() {
	fast;
	int n, m,cnt;
	while (cin >> n >> m) {
		cnt = 0;
		for (int i = n; i <= m; i++) {
			if (check(i))cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}