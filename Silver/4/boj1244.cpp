#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1244
	1244번 스위치 켜고 끄기
	
	남자, 자기가 받은 수 배수
*/
using namespace std;
int n,num;
bool arr[102];
void turnOnOff(int gen,int num) {
	if (gen == 1) {
		for (int i = num; i < n; i += (num+1)) {
			arr[i] = !arr[i];
		}
	}
	else {
		arr[num] = !arr[num];
		for (int i = 1; num + i < n && num - i >= 0; i++) {
			if (arr[num + i] != arr[num - i])break;
			arr[num + i] = !arr[num + i];
			arr[num - i] = !arr[num - i];
		}

	}
}
void solve() {
	cin >> num;//학생 수
	while (num--) {
		int g, innum;
		cin >> g >> innum;
		turnOnOff(g,innum-1);
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i-1] << ' ';
		if (i % 20 == 0)cout << endl;
	}
}
int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	solve();
	return 0;
}