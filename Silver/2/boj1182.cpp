#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/1182
	부분수열의 합
	N개의 정수로 이루어진 수열이 있다.

	크기가 양수인 부분 수열인데 원소를 다 더하면 S가 된다.

	중요한 건 연속 수열이 아니기에 
	
	정수 최대 20 개 주니까
	20C1ㅂ
*/
int main() {
	fast;
	int n, s,count=0;
	cin >> n >> s;
	int arr[21];
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {//nC0
		vector<int>pick(n-i, 0);
		for (int j = 0; j < i; j++) pick.push_back(1);
		do {
			int total = 0;
			for (int j = 0; j < n; j++) {
				if (pick[j]) total+=arr[j];
			}
			if (total == s)count++;
		} while (next_permutation(pick.begin(),pick.end()));
	}
	cout << count;
	return 0;
}