#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/21608
	21608번 상어 초등학교


	1. 비어있는 칸 중 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
	-> 각 자리에 좋아하는 애가 몇 번 인접해있는지 확인하면서 최대 칸 확인.
	2. 1이 여러 개라면 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
	-> 해당하는 자리에서 인접한 칸이 제일 많은 칸.
	3. 2도 많다면, 행의 번호가 가장 작은 거
	4. 3도 많다면 열의 번호가 가장 작은 거.

	1.배열을 확인해서 비어있는 자리에다가 인접한 칸의 갯수, 해당하는 좋아하는 번호가 적힌 애들의 갯수 세기
	2. 제일 큰 값을 갖고 오는데, 그 값의 배열 값중 제일 큰 인덱스 갖고 오기.
	3. 2도 여러 개가 있을 때 행이 제일 적은 거 갖고 오기.
	4. 3도 많으면 열의 번호가 가장 작은 거 갖고 오기
	5. 자리 갖고 온 것에 nuber를 집어 넣어준다.

	6. 모든 배치가 끝났다면 모든 좌석에서 인접한 것을 확인하면서 점수 누적한다.
	7. 출력한다.
*/
using namespace std;
struct loc {
	int adjNumber, lovenumber;//인접한 비어있는 칸,좋아하는 애 몇인지, 몇 번앉았니?
};
int n;
int row;
int arr[22][22];//누가 들어갔는지 확인하기.
vector<vector<bool>>Wholove;//해당하는 인덱스가 누구 좋아하는지 저장해놓은 곳.
long long answer;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
inline int Intpow(int n) {
	return n * n;
}
inline long long mypow(long long n) {
	long long temp = 1;
	for (int i = 0; i < n - 1; i++)temp *= 10;
	return temp;
}
void wheresit(int num) {
	int minrow = 21, mincolumn = 21;
	loc minvalue = { 0 };
	//1,2,3
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!arr[i][j]) {//비어있을 때
				long long lovecnt = 0, emptycnt = 0;//인접한 애들 중에 좋아하는 애 알아내기
				for (int z = 0; z < 4; z++) {
					int nx = i + dx[z];
					int ny = j + dy[z];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
					if (Wholove[num][arr[nx][ny]]) {//해당하는 칸 인접한 칸에 좋아하는 학생 수.
						lovecnt++;
					}
					if (arr[nx][ny] == 0)emptycnt++;
				}
				if (lovecnt > minvalue.lovenumber) {
					minvalue.lovenumber = lovecnt;
					minvalue.adjNumber = emptycnt;
					minrow = i;
					mincolumn = j;
				}
				else if (lovecnt == minvalue.lovenumber) {
					if (minvalue.adjNumber < emptycnt) {
						minvalue.lovenumber = lovecnt;
						minvalue.adjNumber = emptycnt;
						minrow = i;
						mincolumn = j;
					}
				}
				if (minrow == 21 && mincolumn == 21) {//일단은 비어있다는 것이니까.
					minvalue.lovenumber = lovecnt;
					minvalue.adjNumber = emptycnt;
					minrow = i;
					mincolumn = j;
				}
			}
		}
	}
	arr[minrow][mincolumn] = num;//자리 앉히기.
}
void getHuman() {//학생들의 만족도 구하기/
	for (int i = 0; i < n; i++) {//값을 돌면서 값 구하기.
		for (int j = 0; j < n; j++) {
			long long cnt = 0;
			for (int z = 0; z < 4; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
				if (Wholove[arr[i][j]][arr[nx][ny]]) {//해당하는 칸 인접한 칸에 좋아하는 학생 수.
					cnt++;
				}
			}
			if (cnt != 0)answer += mypow(cnt);
		}
	}
}
void solve() {
	for (int i = 0; i < row; i++) {
		int number, t1, t2, t3, t4;
		cin >> number >> t1 >> t2 >> t3 >> t4;
		for (auto& value : { t1,t2,t3,t4 }) {
			Wholove[number][value] = true;//해당하는 idx에 좋아하는지 파단 O(1)이면 판단가능.
		}
		wheresit(number);//어디 앉을지 체크해주고 앉기까지.
	}
	getHuman();
}
int main() {
	fast;
	cin >> n;
	row = Intpow(n);
	Wholove.resize(row + 1, vector<bool>(row + 1, 0));//n^2 크기로 만들어 놓기.
	solve();
	cout << answer;//값 출력 끝
	return 0;
}