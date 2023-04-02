#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/19236
	19236번 청소년 상어

	1. 상어가 (0,0) 자리에 들어가면서 물고기의 방향을 갖는다.
	2. 물고기의 번호가 작은 순서대로 이동하기 시작한다.
	3. 상어는 방향에 있는 칸으로 1,2,3칸 골라서 갈 수 있다.
	4. 상어가 이동할 수 있는 칸이 없으면 공간에서 벗어나 집으로 간다.(이러면 끝)
*/
using namespace std;
struct loc {
	int num, s;//숫자랑 번호
};
struct SHARK {
	int x, y, s;//좌표와 방향
};
struct LOC {
	int x, y;
};
map<int, LOC>MOVE = { {1,{-1,0}},{2,{-1,-1}},{3,{0,-1}},{4,{1,-1}},
	{5,{1,0}},{6,{1,1}},{7,{0,1}},{8,{-1,1}} };
loc arr[6][6];
SHARK shark;
long long answer;//결과 값 갖고 오기~
bool isBoundary(int x, int y) {
	return (x >= 0 && x < 4) && (y >= 0 && y < 4);
}
void arrcpy(loc src[6][6], loc dst[6][6]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dst[i][j] = src[i][j];
		}
	}
}
void fishmove(loc tmp[6][6]) {//처음에 0,0으로 시작.
	vector<LOC>save(18, { -1,-1 });//해당 번호의 좌표 저장해놓기
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			save[tmp[i][j].num] = { i,j };//좌표 저장하기.
		}
	}
	for (int i = 1; i <= 16; i++) {//경로들 보고 바꾸기 시작.
		auto temp = save[i];
		if (temp.x == -1 && temp.y == -1)continue;
		for (int i = 0; i < 8; i++) {
			auto next = MOVE[tmp[temp.x][temp.y].s];//해당 좌표의 방향 알아내기.
			int nx = temp.x + next.x;
			int ny = temp.y + next.y;
			if (!isBoundary(nx, ny)) {//경계면 넘어갔으면 해당하는 아이의 방향을 바꾼다.
				tmp[temp.x][temp.y].s = (tmp[temp.x][temp.y].s + 1 == 9 ? 1 : tmp[temp.x][temp.y].s + 1);
				continue;
			}
			if (arr[nx][ny].num == 17) {//상어 있으면 17
				tmp[temp.x][temp.y].s = (tmp[temp.x][temp.y].s + 1 == 9 ? 1 : tmp[temp.x][temp.y].s + 1);
				continue;
			}
			swap(arr[temp.x][temp.y], arr[nx][ny]);
			save[arr[temp.x][temp.y].num] = { temp.x,temp.y };
			save[arr[nx][ny].num] = { nx,ny };
			break;
		}
	}
}
void solve(loc tmp[6][6], SHARK srk, long long result) {//해당 재귀 깊이
	answer = max(answer, result);
	tmp[srk.x][srk.y] = { 17,srk.s };//해당 좌표 상어 놓기
	fishmove(arr);
	loc cache[6][6];//해당 depth에 저장하기.
	arrcpy(tmp, cache);//배열 일단 복사하기.
	auto [dx, dy] = MOVE[srk.s];//dx,dy, 
	for (int i = 1; i <= 4; i++) {//재귀 그만 들어가..
		SHARK new_srk = { srk.x + (dx * i) ,srk.y + (dy * i) };
		new_srk.s = tmp[new_srk.x][new_srk.y].s;
		int num = tmp[new_srk.x][new_srk.y].num;
		if (isBoundary(new_srk.x, new_srk.y) && num > 0) {//들어가면 안됨
			tmp[srk.x][srk.y] = { 0,0 };//들어가기 전 상어 좌표로 놓기
			solve(tmp, new_srk, result + num);
			arrcpy(cache, tmp);//다시 복구
		}
	}
}
int main() {
	fast;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j].num >> arr[i][j].s;
		}
	}
	answer = arr[0][0].num;
	shark = { 0,0,arr[0][0].s };
	solve(arr, shark, answer);
	cout << answer;
	return 0;
}