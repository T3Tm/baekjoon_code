#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/14912
	숫자 빈도수
*/
using namespace std;
int main(){
	fast;
	int n, d;
	long long cnt=0;
	cin >> n >> d;
	for (int i = n; i >= 1; i--) {
		int copy = i;
		while (copy) {
			if (copy % 10 == d)cnt++;
			copy /= 10;
		}
	}
	cout << cnt;
	return 0;
}