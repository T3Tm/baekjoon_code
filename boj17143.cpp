#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17143
	17143번 낚시왕
*/
using namespace std;
struct SHARK {
	int r, c, s, d, z;//좌표, 속도,방향,크기 
};
int main() {
	fast;
	int r, c, m;//행 렬 상어의 수
	int arr[102][102] = { 0 };
	cin >> r >> c >> m;
	vector<SHARK>shark(m);//상어들 입력받기
	auto isBoundary = [&](int x, int y) {
		return x < 0 || x >= r || y < 0 || y >= c;
	};
	int convert[] = { 1,0,3,2 };
	auto locconvert = [&](int& x, int& y, int& d) {//해당 좌표를 건들여주기.
		if (x < 0) {
			int value = (-x) % (r - 1);
			value = value ? value : r - 1;
			if (((-x - 1) / (r - 1)) % 2) {//홀수 방향 안 바꿈.
				x = (r - 1) - value;
			}
			else {//방향 바꿔줘야함.
				d = convert[d];
				x = value;//1,2,3,n-1까지 나와야함.
			}
		}
		else if (x >= r) {
			int value = (x) % (r - 1);
			value = value ? value : r - 1;
			if (((x - 1) / (r - 1)) % 2) {//방향 바꿔야함.
				d = convert[d];
				x = (r - 1) - value;

			}
			else {
				x = value;
			}
		}
		if (y < 0) {
			int value = (-y) % (c - 1);
			value = value ? value : c - 1;
			if (((-y - 1) / (c - 1)) % 2) {//홀수 방향 안 바꿈.
				y = (c - 1) - value;
			}
			else {//방향 바꿔줘야함.
				d = convert[d];
				y = value;//1,2,3,n-1까지 나와야함.
			}
		}
		else if (y >= c) {
			int value = (y) % (c - 1);
			value = value ? value : c - 1;
			if (((y - 1) / (c - 1)) % 2) {//방향 바꿔야함.
				d = convert[d];
				y = (c - 1) - value;
			}
			else {
				y = value;
			}
		}
	};

	for (int i = 1; i <= m; i++) {
		cin >> shark[i - 1].r >> shark[i - 1].c >> shark[i - 1].s >> shark[i - 1].d >> shark[i - 1].z;
		arr[--shark[i - 1].r][--shark[i - 1].c] = i;//i번째 상어가 들어가있다.
		shark[i - 1].d--;
	}
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,1,-1 };
	/*step 3*/
	auto arrcopy = [&](int newarr[102][102]) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				arr[i][j] = newarr[i][j];
			}
		}
	};
	/*step 2 */
	auto sharkmove = [&]() {
		int newarr[102][102] = { 0 };
		for (int i = 1; i <= m; i++) {
			auto [r, c, s, d, z] = shark[i - 1];//좌표 ,속도,방향,크기
			if (r == -1 && c == -1)continue;//죽은 아이 처리하지 말기.
			r += (dx[d] * s);
			c += (dy[d] * s);
			if (isBoundary(r, c)) {//넘어갔으니 방향을 반대로 만들기
				locconvert(r, c, d);
			}
			if (newarr[r][c] && shark[newarr[r][c] - 1].z > shark[i - 1].z) {
				//움직였던 아이어야 하고. 숫자가 있어야 하며 크기가 더 작으면 먹힘.
				shark[i - 1] = { -1,-1,s,d,z };
				continue;
			}
			else if (newarr[r][c] && shark[newarr[r][c] - 1].z < shark[i - 1].z) {//본인이 더 크니까 그 자리에 있던 애는 죽여야함.
				shark[newarr[r][c] - 1] = { -1,-1,s,d,z };//내가 가려고 했던 자리에 애 죽이기.
			}
			shark[i - 1] = { r,c,s,d,z };
			newarr[r][c] = i;//새로운 공간에 할당해준다.
		}
		arrcopy(newarr);//새로운 배열 다시 복사
	};
	/*step 1 */

	int column = -1;
	long long answer = 0;
	auto fishman = [&]() {
		column++;
		for (int row = 0; row < r; row++) {
			if (arr[row][column]) {//상어 존재함.
				shark[arr[row][column] - 1].r = -1, shark[arr[row][column] - 1].c = -1;
				//상어 삭제 시키기.
				answer += shark[arr[row][column] - 1].z;
				arr[row][column] = 0;//상어 삭제
				break;
			}
		}
		sharkmove();
	};
	for (; column + 1 != c; fishman());

	cout << answer;
	return 0;
}