#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cout.tie(nullptr),cin.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2980
	2980번 도로와 신호등
	선형탐색해도 됨.
*/
using namespace std;
int n, l;
struct my {
	int time, x;
};
int main() {
	fast;
	cin >> n >> l;
	my t = { 0,0 };//현재 시간과 좌표 알고 있기.
	for (int i = 0; i < n; i++) {
		int d, r, g;
		cin >> d >> r >> g;
		t.time += (d - t.x);//현재 나의 시간에 추가로 넣기.
		if (t.time % (r + g) + 1 > r) {//이제 현재 시간에 건널 수 있는지 판단해야됨.
			t.time++;//건널 수 있음.
		}
		else {//못 건너니까 
			t.time += r - (t.time % (r + g)) + 1;//안되는 시간 만큼 더하기.
		}
		t.x = d + 1;//건너기.
	}
	if (t.x < l) {
		t.time += (l - t.x);
	}
	cout << t.time;
	return 0;
}