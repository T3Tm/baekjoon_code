#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl "\n"
/*
	https://www.acmicpc.net/problem/1436
	1436번 영화감독 숌
*/

using namespace std;
int main() {
	int n,result;
	cin >> n;
	int count = 1;
	for (int i = 666;; i++) {
		if (count == n) {
			result = i;
			break;
		}
		string temp = to_string(i);
		for (int idx = 1; i <= temp.size() - 2; idx++) {
			if (temp[idx - 1] == '6' && temp[idx] == '6' && temp[idx + 1] == '6') {
				count++;
				break;
			}
		}
	}
	cout << result;
	return 0;
}