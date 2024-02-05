#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/11441
	합 구하기
	
	N개의 수 A1 ~ An이 입력으로 주어진다. 총 M개의 구간이 i,j가 주어질 때  
*/
using namespace std;
int main(){
	fast;
	int n,m;
	cin >> n;
	vector<int>arr(n);
	vector<int>newarr(n + 1, 0);
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		newarr[i] = arr[i - 1];
		newarr[i] = newarr[i] + newarr[i - 1];
	}
	cin >> m;
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << newarr[j] - newarr[i-1] << endl;
	}
	return 0;
}