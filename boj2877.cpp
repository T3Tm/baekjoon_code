#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2877
	2877번 4와 7

	4와 7로 이뤄진 수중에,
	k번째 작은 수를 구해라.
	1번째 작은 수
	4
	2번째 작은수
	7

	44,47

	74,77

	444,447

	474,477

	744,747

	774,777

	4,7 ,44,47,74,77 ,444,447,474,477,744,747,774,777
	1 2  0  1  2  3    1  2   3   4  5   6   7  8
	0 1  00 01 10 11  000 001 010 011 100
	오호! 대박
*/
using namespace std;
int insertN, arr[32];
void trans(int n, int depth) {
	if (n < 2) {
		arr[depth] = n;
	}
	else {
		trans(n / 2, depth + 1);
		arr[depth] = n % 2;
	}
}
void solve() {
	long long end = 0, mul = 2;
	int i;
	for (i = 1; i <= 29; i++) {
		end += mul;
		if (insertN <= end)break;//n이 end 안에 속한다는 것을 알아낸다. i를 알아내야함.
		mul *= 2;//2,4,6,8
	}
	//mul 
	insertN -= (end - mul) + 1;
	trans(insertN, 0);
	for (i--; i >= 0; i--) {
		cout << (arr[i] ? 7 : 4);
	}
}
int main() {
	fast; cin >> insertN;
	solve();
	return 0;
}