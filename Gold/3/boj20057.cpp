#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/20057
   20057번 마법사 상어와 토네이도
   499 * 499 = 249001
   y * 5 / 100

	1. 이동한다.
	2. 바라보는 방향에 따라 모래를 흩날린다.
	2-1 흩날릴 때 경계면을 넘어가는지 확인!
	3. 흩날리고 남은 값을  다음 칸에 뿌려준다.


	1 : 동
	2 : 서
	3 : 남
	4 : 북
	1%,2%,5%,7%,10% 계산해야 한다.
*/
using namespace std;
int n;
int arr[502][502];
long long sand = 0;//버려지는 모래들 모으기.
map<int, pair<int, int>>MOVE = { {1,{0,1}},{2,{0,-1}},{4,{-1,0}},{3,{1,0}} };//
bool isBoundary(int x, int y) {//경계면 체크
	return (x < n && x >= 0) && (y < n && y >= 0);
}
void spreadSand(int x, int y, int see, long long& sand) {
	int percent1 = arr[x][y] / 100;
	int percent2 = arr[x][y] / 50;
	int percent5 = arr[x][y] / 20;
	int percent7 = (arr[x][y] * 7) / 100;
	int percent10 = arr[x][y] / 10;
	if (see == 1) {//동
		if (isBoundary(x - 1, y - 1)) {//경계면 안에 있음
			arr[x - 1][y - 1] += percent1;
		}
		else {//벗어남.
			sand += percent1;
		}
		if (isBoundary(x + 1, y - 1)) {
			arr[x + 1][y - 1] += percent1;
		}
		else {
			sand += percent1;
		}

		if (isBoundary(x - 1, y)) {
			arr[x - 1][y] += percent7;
		}
		else {
			sand += percent7;
		}
		if (isBoundary(x + 1, y)) {
			arr[x + 1][y] += percent7;
		}
		else {
			sand += percent7;
		}

		if (isBoundary(x - 2, y)) {
			arr[x - 2][y] += percent2;
		}
		else {
			sand += percent2;
		}
		if (isBoundary(x + 2, y)) {
			arr[x + 2][y] += percent2;
		}
		else {
			sand += percent2;
		}

		if (isBoundary(x - 1, y + 1)) {
			arr[x - 1][y + 1] += percent10;
		}
		else {
			sand += percent10;
		}
		if (isBoundary(x + 1, y + 1)) {
			arr[x + 1][y + 1] += percent10;
		}
		else {
			sand += percent10;
		}

		if (isBoundary(x, y + 2)) {
			arr[x][y + 2] += percent5;
		}
		else {
			sand += percent5;
		}

		if (isBoundary(x, y + 1)) {
			arr[x][y + 1] += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
		else {
			sand += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
	}
	else if (see == 2) {//서
		if (isBoundary(x - 1, y + 1)) {//경계면 안에 있음
			arr[x - 1][y + 1] += percent1;
		}
		else {//벗어남.
			sand += percent1;
		}
		if (isBoundary(x + 1, y + 1)) {
			arr[x + 1][y + 1] += percent1;
		}
		else {
			sand += percent1;
		}

		if (isBoundary(x - 1, y)) {
			arr[x - 1][y] += percent7;
		}
		else {
			sand += percent7;
		}
		if (isBoundary(x + 1, y)) {
			arr[x + 1][y] += percent7;
		}
		else {
			sand += percent7;
		}

		if (isBoundary(x - 2, y)) {
			arr[x - 2][y] += percent2;
		}
		else {
			sand += percent2;
		}
		if (isBoundary(x + 2, y)) {
			arr[x + 2][y] += percent2;
		}
		else {
			sand += percent2;
		}

		if (isBoundary(x - 1, y - 1)) {
			arr[x - 1][y - 1] += percent10;
		}
		else {
			sand += percent10;
		}
		if (isBoundary(x + 1, y - 1)) {
			arr[x + 1][y - 1] += percent10;
		}
		else {
			sand += percent10;
		}

		if (isBoundary(x, y - 2)) {
			arr[x][y - 2] += percent5;
		}
		else {
			sand += percent5;
		}

		if (isBoundary(x, y - 1)) {
			arr[x][y - 1] += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
		else {
			sand += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
	}
	else if (see == 3) {//남
		if (isBoundary(x - 1, y - 1)) {//경계면 안에 있음
			arr[x - 1][y - 1] += percent1;
		}
		else {//벗어남.
			sand += percent1;
		}
		if (isBoundary(x - 1, y + 1)) {
			arr[x - 1][y + 1] += percent1;
		}
		else {
			sand += percent1;
		}

		if (isBoundary(x, y - 1)) {
			arr[x][y - 1] += percent7;
		}
		else {
			sand += percent7;
		}
		if (isBoundary(x, y + 1)) {
			arr[x][y + 1] += percent7;
		}
		else {
			sand += percent7;
		}

		if (isBoundary(x, y - 2)) {
			arr[x][y - 2] += percent2;
		}
		else {
			sand += percent2;
		}
		if (isBoundary(x, y + 2)) {
			arr[x][y + 2] += percent2;
		}
		else {
			sand += percent2;
		}

		if (isBoundary(x + 1, y - 1)) {
			arr[x + 1][y - 1] += percent10;
		}
		else {
			sand += percent10;
		}
		if (isBoundary(x + 1, y + 1)) {
			arr[x + 1][y + 1] += percent10;
		}
		else {
			sand += percent10;
		}

		if (isBoundary(x + 2, y)) {
			arr[x + 2][y] += percent5;
		}
		else {
			sand += percent5;
		}

		if (isBoundary(x + 1, y)) {
			arr[x + 1][y] += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
		else {
			sand += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
	}
	else {//북
		if (isBoundary(x + 1, y - 1)) {//경계면 안에 있음
			arr[x + 1][y - 1] += percent1;
		}
		else {//벗어남.
			sand += percent1;
		}
		if (isBoundary(x + 1, y + 1)) {
			arr[x + 1][y + 1] += percent1;
		}
		else {
			sand += percent1;
		}

		if (isBoundary(x, y - 1)) {
			arr[x][y - 1] += percent7;
		}
		else {
			sand += percent7;
		}
		if (isBoundary(x, y + 1)) {
			arr[x][y + 1] += percent7;
		}
		else {
			sand += percent7;
		}

		if (isBoundary(x, y - 2)) {
			arr[x][y - 2] += percent2;
		}
		else {
			sand += percent2;
		}
		if (isBoundary(x, y + 2)) {
			arr[x][y + 2] += percent2;
		}
		else {
			sand += percent2;
		}

		if (isBoundary(x - 1, y + 1)) {
			arr[x - 1][y + 1] += percent10;
		}
		else {
			sand += percent10;
		}
		if (isBoundary(x - 1, y - 1)) {
			arr[x - 1][y - 1] += percent10;
		}
		else {
			sand += percent10;
		}

		if (isBoundary(x - 2, y)) {
			arr[x - 2][y] += percent5;
		}
		else {
			sand += percent5;
		}

		if (isBoundary(x - 1, y)) {
			arr[x - 1][y] += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
		else {
			sand += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
	}
	arr[x][y] = 0;//토네이도 지나가면 0으로 됨.
}
void ChangeSee(int& see) {
	if (see == 1) {
		see = 4;
	}
	else if (see == 2) {
		see = 3;
	}
	else if (see == 3) {
		see = 1;
	}
	else {
		see = 2;
	}
}
void solve() {
	int cnt = 0, move = 1;
	int see = 2;//처음 보는 곳 서쪽
	int x = (n - 1) / 2;
	int y = x; //초기 시작 좌표들
	while (1) {
		for (int i = 0; i < move; i++) {//move만큼 바라보는 방향 움직여야함.
			auto next = MOVE[see];
			//좌표 움직이기.
			x += next.first;
			y += next.second;
			//모래 흩날린다.
			spreadSand(x, y, see, sand);
			if (x == 0 && y == 0) {//961 - 908 53차이남. 
				cout << sand;
				exit(0);
			}
		}
		cnt++;
		ChangeSee(see);//방향 바꾸기
		if (cnt == 2) {
			cnt = 0;
			move++;
		}
	}
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

