#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1913
	1913번 달팽이

	1은 그럼 정가운데 있다.
	즉
	n/2 ,n/2에서 부터 시작
	위,오,아,아,왼,왼,위,위,위,오,오,오
	위,오,아,왼
	0,1,2,3
*/
using namespace std;
int n, a;
struct loc {
	int x, y;
};
map<int, loc>MOVE{ {0,{-1,0}},{1,{0,1}},{2,{1,0}},{3,{0,-1}} };
int arr[1002][1002];
int main() {
	fast; cin >> n >> a;
	int row, column = row = n / 2;
	int plus = 0, prevalue = 2, go = 1, dir = 0;
	pair<int, int>result{ n / 2,n / 2 };
	arr[row][column] = 1;
	while (1) {
		auto [dx, dy] = MOVE[dir];
		for (int i = 0; i < go; i++) {
			int nx = row + dx;
			int ny = column + dy;
			if (nx == -1 && ny == 0)goto EXIT;
			arr[nx][ny] = prevalue++;
			row = nx, column = ny;
			if (arr[nx][ny] == a)result = { nx,ny };
		}
		plus++;
		dir = (dir + 1) % 4;
		if (plus == 2) {
			plus = 0;
			go++;
		}
	}
EXIT:
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << result.first + 1 << ' ' << result.second + 1;
	return 0;
}