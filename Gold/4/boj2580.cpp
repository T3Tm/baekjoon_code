#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/2580
	스도쿠
	가로 세로 모두 방문하면서 없는 숫자 찾아내는 것은 최대 깊이
	1. 0의 위치를 보고 한 번에 맞힐 수 있는 숫자는 바로 넣는다
	2. deque가 비었는지 확인하여 아직 넣은 값이 없으면 다시 돌린다.
	1,2,3사분면은
	
	행이 다 3보다 작다.
	
	열이 3보다 작으면 1, 6보다 작으면 2, 9보다 작으면 3

	행이 6보다 작으면 .
	
	4,5,6
	사분면 들어갈 수 있는 값 배열 
	행 들어갈 수 있는 값 배열
	열 들어갈 수 있는 값 배열
*/
typedef struct loc {
	int row, column;
}loc;

int sdoku[11][11];
int rowpossible[11][11];
int columnpossible[11][11];
int squarepossible[11][11];
map<pair<int, int>, int>convert = { {{0,0},0},{{0,1},1},{{0,2},2},{{1,0},3},{{1,1},4},{{1,2},5},{{2,0},6},{{2,1},7},{{2,2},8}};
deque<loc>location;
void makeSdoku(int idx) {
	if (idx == location.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sdoku[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	auto value = location[idx];
	// 그다음 1개 이상인 것들은 그것들을 저장해서 그것들만 넣어서 
	// 셋팅 해봄,
	
	int Row = value.row, Column = value.column;
	int quardrant = convert[{Row / 3, Column/3}];
	bool possible[11] = { false };
	for (int i = 1; i < 10; i++) {
		if (rowpossible[Row][i])possible[i] = 1;
	}
	for (int j = 1; j < 10; j++) {
		if (columnpossible[Column][j])possible[j] = 1;
	}
	for (int t = 1; t < 10; t++) {
		if (squarepossible[quardrant][t])possible[t] = 1;
	}
	for (int number = 1; number < 10; number++) {
		if (!possible[number]) {
			rowpossible[Row][number] = 1;
			columnpossible[Column][number] = 1;
			squarepossible[quardrant][number] = 1;
			sdoku[Row][Column] = number;
			makeSdoku(idx + 1);
			sdoku[Row][Column] = 0;
			rowpossible[Row][number] = 0;
			columnpossible[Column][number] = 0;
			squarepossible[quardrant][number] = 0;
		}
	}
}
int main() {
	fast;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sdoku[i][j];
			if (!sdoku[i][j])location.push_back({ i,j });
			rowpossible[i][sdoku[i][j]] = 1;
			columnpossible[j][sdoku[i][j]] = 1;
			int quardrant = convert[{i/3,j/3}];
			squarepossible[quardrant][sdoku[i][j]] = 1;
		}
	}
	makeSdoku(0);
	return 0;
}