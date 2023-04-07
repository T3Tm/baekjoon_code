#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/5002
	5002번 도어맨
*/
using namespace std;
int main() {
	fast;
	int gap; cin >> gap;
	string t; cin >> t;
	int w = 0, m = 0;
	int i;
	for (i = 0; i < t.size(); i++) {
		char value = t[i];
		if (value == 'W')w++;
		else m++;

		if (abs(w - m) > gap) {
			char next = t[i + 1];
			if (next == 'W')w++;
			else m++;

			if (abs(w - m) > gap) {
				break;
			}
			i++;
		}
	}
	cout << i;
	return 0;
}