#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/27958
	27958번 사격 연습
*/
using namespace std;
struct newArr {
	int num, preNum;//지금 숫자, 초기 숫자.
};
int n, k;
newArr arr[10][10];
int bullet[6];
int answer;
void arrcpy(newArr src[][10], newArr dst[][10]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dst[i][j] = src[i][j];
		}
	}
}
void spread(newArr tmp[][10], int x, int y) {
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
		if (tmp[nx][ny].num == 0) {//해당하는 곳이 0이라는 것은 어차피 더해졌었거나 필요없었던 거임.
			tmp[nx][ny].num = tmp[x][y].preNum / 4;
			tmp[nx][ny].preNum = tmp[x][y].preNum / 4;
		}
	}
}
void tang(int depth, newArr tmp[][10], int result) {
	if (depth == k) {
		answer = max(answer, result);
		return;
	}
	newArr cache[10][10];
	arrcpy(tmp, cache);
	for (int i = 0; i < n; i++) {//행 관련
		int idx = -1;
		for (int j = 0; j < n; j++) {
			if (tmp[i][j].num) {//과녁이 있는지 확인.
				idx = j;
				break;
			}
		}
		if (idx != -1) {
			if (bullet[depth] >= tmp[i][idx].num || tmp[i][idx].num >= 10) {//보너스 블럭
				int value = tmp[i][idx].preNum;//초기 체력만큼 더해야됨.
				if (value >= 4 && value < 10)spread(tmp, i, idx);
				tmp[i][idx].num = 0;
				tang(depth + 1, tmp, result + value);
				arrcpy(cache, tmp);
			}
			else {//못 부심.
				tmp[i][idx].num -= bullet[depth];
				tang(depth + 1, tmp, result);
				tmp[i][idx].num += bullet[depth];
			}
		}
	}
}
void solve() {
	tang(0, arr, 0);
	cout << answer;
}
int main() {
	fast;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j].num;
			arr[i][j].preNum = arr[i][j].num;
		}
	}
	for (int i = 0; i < k; i++)cin >> bullet[i];
	solve();
	return 0;
}