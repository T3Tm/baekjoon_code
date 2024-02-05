#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/15721
	번데기
*/
int main() {
	int a,t;
	char c;
	cin >> a >> t >> c;
	string word;
	int j = 0;
	for (int i = 1;; i++) {
		word.assign("0101");
		word.append(i + 1, '0');
		word.append(i + 1, '1');
		for (int idx = 0; idx < word.size(); idx++) {
			if (c == word[idx])t--;
			if (!t) {
				cout << j;
				return 0;
			}
			j++;
			if (j == a) j = 0;
		}
	}
}