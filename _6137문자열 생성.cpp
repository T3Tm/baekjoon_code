#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl "\n"
/*
	https://www.acmicpc.net/problem/6137
	문자열 생성
	ABDGKKABA

	AABB
*/
using namespace std;
deque<char>a;
bool compare(int n, int m) {
	bool result = true;
	while (n <= m) {
		if (a[n] == a[m]) {
			n++;
			m--;
		}
		else if (a[n] < a[m]) {
			return true;
		}
		else {
			return false;
		}
	}
	return result;
}
int main() {
	fast;
	int n,idx=0,cnt=0;
	cin >> n;
	while (n--) {
		char t;
		cin >> t;
		a.push_back(t);
	}
	while (!a.empty()) {
		if (compare(idx, a.size() - idx - 1)) {
			cout << a.front();
			a.pop_front();
		}
		else{
			cout << a.back();
			a.pop_back();
		}
		cnt++;
		if (cnt and !(cnt % 80))cout << endl;
	}
	return 0;
}