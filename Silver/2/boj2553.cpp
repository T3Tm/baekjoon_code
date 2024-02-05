#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cout.tie(nullptr),cin.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2553
	2553번 마지막 팩토리얼 수
	0이 아닌 가장 작은 자릿 수를 출력하여야 된다.
*/
using namespace std;
int n;
long long answer = 1;
int main() {
	fast;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		answer *= i;
		while (!(answer % 10)) {
			answer /= 10;
		}
		answer %= 100000000;
	}
	cout << answer % 10;
	return 0;
}