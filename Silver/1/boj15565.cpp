#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/15565
	귀여운 라이언
	투 포인터로 풀면 끝나겠네
*/
int main() {
	fast;
	int front, cnt, end = front = cnt = 0;
	int result = 10000001;
	int n, k;
	cin >> n >> k;
	vector<int>arr(n);
	for (end = 0; end < n; end++) {
		cin >> arr[end];//인형 정보
	}
	end = 0;
	while (end < n) {
		if (arr[end] == 1)cnt++;
		if (cnt > k) {
			front++;
			while (arr[front] != 1)front++;
			cnt--;
		}
		if (cnt == k) {
			while (arr[front] != 1)front++;
			result = min(result, end - front+1);
		}
		end++;
	}
	if (result == 10000001)cout << -1;
	else cout << result;
	return 0;
}