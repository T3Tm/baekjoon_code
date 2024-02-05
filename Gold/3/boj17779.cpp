#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17779
	17779번 게리맨더링 2
	n*n 격자에서 5개의 선거구로 나뉘어야 한다.
	1. 선거구는 구역을 적어도 하나 포함해야 한다. 한 서거구에 포함되어 있는 구역은 모두 연결되어야 한다.
	(인접한 구역은 0개 이상이어야한다. , 모두 같은 선거구에 포함된 구역이어야 한다.)


	1. 기준점(x,y) 와 경계의 길이 d1,d2를 정한다
	2.
*/
using namespace std;
int n;
int answer = INT_MAX;
int arr[22][22];
int getbound(int x, int y, int ex, int ey, int tmp[][22], int num) {
	int cnt = 0;
	for (int i = x; i <= ex; i++) {
		for (int j = y; j <= ey; j++) {
			if (tmp[i][j] != 5) {
				tmp[i][j] = num;
				cnt += arr[i][j];
			}
		}
	}
	return cnt;
}
int getfive(int x, int y, int d1, int d2, int tmp[][22]) {
	int cnt = 0;
	bool visited[22][22] = { false };
	for (int i = x, j = y; i <= x + d1 && j >= y - d1; i++, j--) {
		if (tmp[i][j] != 5) {
			cnt += arr[i][j];
		}
		tmp[i][j] = 5;//5번의 경계면
	}
	for (int i = x, j = y; i <= x + d2 && j <= y + d2; i++, j++) {
		if (tmp[i][j] != 5) {
			cnt += arr[i][j];
		}
		tmp[i][j] = 5;//5번의 경계면
	}
	for (int i = x + d1, j = y - d1; i <= x + d1 + d2 && j <= y - d1 + d2; i++, j++) {
		if (tmp[i][j] != 5) {
			cnt += arr[i][j];
		}
		tmp[i][j] = 5;//5번의 경계면
	}
	for (int i = x + d2, j = y + d2; i <= x + d1 + d2 && j >= y - d1 + d2; i++, j--) {
		if (tmp[i][j] != 5) {
			cnt += arr[i][j];
		}
		tmp[i][j] = 5;//5번의 경계면
	}
	for (int j = 1; j <= d1; j++) {
		for (int i = x + j, z = y - j + 1; tmp[i][z] != 5; z++) {
			cnt += arr[i][z];
			tmp[i][z] = 5;
		}
	}
	for (int j = 1; j < d2; j++) {
		for (int i = x + d1 + j, z = y - d1 + j + 1; tmp[i][z] != 5; z++) {
			cnt += arr[i][z];
			tmp[i][z] = 5;
		}
	}
	return cnt;
}
void solve() {
	for (int x = 0; x < n - 2; x++) {
		for (int y = 1; y < n - 1; y++) {//기준 점 정하기  n^2
			for (int d1 = 1; x + d1 + 1 < n && y - d1 >= 0; d1++) {//d1 구하기
				for (int d2 = 1; x + d1 + d2 < n && y + d2 < n; d2++) {//d2 구하기
					//경계면 구하기.
					int tmp[22][22] = { false };
					int f5 = getfive(x, y, d1, d2, tmp);//먼저 5번의 경계를 쳐놓기.
					int f1 = getbound(0, 0, x + d1 - 1, y, tmp, 1);//경계면 치기.
					int f2 = getbound(0, y + 1, x + d2, n - 1, tmp, 2);
					int f3 = getbound(x + d1, 0, n - 1, y - d1 + d2 - 1, tmp, 3);
					int f4 = getbound(x + d2 + 1, y - d1 + d2, n - 1, n - 1, tmp, 4);
					answer = min(answer, max({ f1,f2,f3,f4,f5 }) - min({ f1,f2,f3,f4,f5 }));
				}
			}
		}
	}
	cout << answer;
}
int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	return 0;
}