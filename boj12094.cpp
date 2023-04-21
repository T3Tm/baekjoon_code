#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/12094
	12094번 2048 (Hard)

	왼쪽으로 밀려면
	맨 왼쪽을 기준으로 값을 다 땡겨오면 된다.
	근데 중요한 것은 이미 합쳐진 아이라면 같아도 합치면 안된다.


*/
using namespace std;
int n, arr[22][22], answer;
struct loc {
	int x, y;
};
loc MOVE[4]{ {-1,0},{0,1},{1,0},{0,-1} };//위 오른쪽 아래 왼쪽
int maxresult[12];
void arrcpy(int src[][22], int dst[][22]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dst[i][j] = src[i][j];
		}
	}
}
int play(int inarr[][22], int dir, int dst[][22]) {//방향에 맞게 값을 다 넣어주면 된다.
	int newarr[22][22]{ 0 };
	auto [dx, dy] = MOVE[dir];//방향에 맞게 밀어주자. 밀어줄 때 한 방향으로 밀어줄 것이다.
	int maxvalue = 0;
	if (!dir || dir == 3) {//값이 감소하는 아이들 
		for (int i = 0; i < n; i++) {//dir==0 이면 i는 열 dir==3 i는 행
			int idx = 0;//newarr에 들어갈 idx값
			for (int j = 0; j < n; j++) {//여기의 값이 하나씩 newarr에 들어가면 된다.
				if (!dir) {//위로
					if (!inarr[j][i])continue;
					if (newarr[idx][i] == inarr[j][i]) {//합칠 수 있음.
						newarr[idx][i] <<= 1;//두배 해주기.
						maxvalue = max(maxvalue, newarr[idx][i]);
						idx++;
						continue;
					}
					else if (newarr[idx][i] != inarr[j][i] && newarr[idx][i]) {
						idx++;//지금 못 합치니까 다음 것에 넣자.
					}
					newarr[idx][i] = inarr[j][i];
					maxvalue = max(maxvalue, newarr[idx][i]);
				}
				else {//왼쪽으로
					if (!inarr[i][j])continue;
					if (newarr[i][idx] == inarr[i][j]) {//합칠 수 있음.
						newarr[i][idx] <<= 1;//두배 해주기.
						maxvalue = max(maxvalue, newarr[i][idx]);
						idx++;
						continue;
					}
					else if (newarr[i][idx] != inarr[i][j] && newarr[i][idx]) {
						idx++;//지금 못 합치니까 다음 것에 넣자.
					}
					newarr[i][idx] = inarr[i][j];
					maxvalue = max(maxvalue, newarr[i][idx]);
				}
			}
		}
	}
	else {//값이 증가하는 아이들
		for (int i = n - 1; i >= 0; i--) {//dir==1 행, dir==2 열
			int idx = n - 1;//newarr에 들어갈 idx값
			for (int j = n - 1; j >= 0; j--) {//여기의 값이 하나씩 newarr에 들어가면 된다.
				if (dir == 2) {//아래
					if (!inarr[j][i])continue;
					if (newarr[idx][i] == inarr[j][i]) {//합칠 수 있음.
						newarr[idx][i] <<= 1;//두배 해주기.
						maxvalue = max(maxvalue, newarr[idx][i]);
						idx--;
						continue;
					}
					else if (newarr[idx][i] != inarr[j][i] && newarr[idx][i]) {
						idx--;//지금 못 합치니까 다음 것에 넣자.
					}
					newarr[idx][i] = inarr[j][i];
					maxvalue = max(maxvalue, newarr[idx][i]);
				}
				else {//오른쪽
					if (!inarr[i][j])continue;
					if (newarr[i][idx] == inarr[i][j]) {//합칠 수 있음.
						newarr[i][idx] <<= 1;//두배 해주기.
						maxvalue = max(maxvalue, newarr[i][idx]);
						idx--;
						continue;
					}
					else if (newarr[i][idx] != inarr[i][j] && newarr[i][idx]) {
						idx--;//지금 못 합치니까 다음 것에 넣자.
					}
					newarr[i][idx] = inarr[i][j];
					maxvalue = max(maxvalue, newarr[i][idx]);
				}
			}
		}
	}
	arrcpy(newarr, dst);//움직인 다음 아이 주기.
	return maxvalue;
}
bool next_true(int src[][22], int src1[][22]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (src[i][j] != src1[i][j])return true;
		}
	}
	return false;
}
void play2048(int depth, int curarr[][22], int datamax[]) {
	if (depth == 10) {
		for (int i = 9; i >= 0; i--) {
			maxresult[i] = datamax[i];//값 저장하기.
		}
		return;
	}
	for (int i = 0; i < 4; i++) {//상하좌우 움직일 수 있다.
		int temp[22][22]{ 0 };
		int curmax = play(curarr, i, temp);//현재 최댓값 받아오기.
		if (next_true(temp, curarr)) {//다르기 때문에 넘어가도 됨.
			//해당 지점에서 만약 최대로 움직여도 최댓값을 못 만들면 애초에 들어가질 않는다.
			//지금 최댓값을 알아내야됨 그럼.
			if (curmax << (9 - depth) > maxresult[9]) {//0이면
				datamax[depth] = curmax;
				answer = max(answer, curmax);
				play2048(depth + 1, temp, datamax);
				datamax[depth] = 0;
			}
		}
	}
}
void solve() {
	for (int i = 0; i < n; i++) {
		answer = max(answer, *max_element(arr[i], arr[i] + n));
	}
	maxresult[0] = answer;//초기의 제일 최댓값 저장.
	int datamax[12]{ 0 };
	play2048(0, arr, datamax);
	cout << max(maxresult[9], answer);
}
int main() {
	fast; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	return 0;
}