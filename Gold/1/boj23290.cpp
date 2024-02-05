#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/23290
	23290번 마법사 상어와 복제

	둘 이상의 물고기가 같은 칸에 있을 수도 있으며
	마법사 상어와 물고기가 같은 칸에 있을 수도 있다. << 주의

	방향 만들기
	1. 모든 물고기가 한 칸 이동한다. 만약 해당 칸으로 이동 못하면 45도 반시계로 계속 방향 바꿔주기 (격자 벗어나면 안됨.)
	2. 상어가 연속해서 3칸 이동한다. //상어는 상하좌우로 인접한 칸에 이동한다.
	2-1 물고기를 만나면 물고기가 사라지고, 물고기 냄새를 남긴다.
	2-2 가능한 이동 방법 중에서 제외되는 물고기의 수가 가장 많은 방법으로 이동하면 된다.
	2-3  그러한 방법이 여러가지인 경우 사전 순으로 가장 앞서는 방법을 이용한다. 사전 순에 대한 문제의 하단 노트에 있다.
	3. 2번 전 연습에서 생긴 물고기의 냄새가 격자에서 사라진다. << 마법 연습 2번 지나면 삭제 돼야하니까 물고기 냄새가 몇 번째동안 됐는지 확인.
	4. 물고기 복사 완료 1에서의 위치와 방향을 그대로 갖게 된다.
	111,112
	←, ↖, ↑, ↗, →, ↘, ↓, ↙
	1  2   3  4  5   6  7  8
*/
using namespace std;
struct loc {
	int x, y;
};
struct FISH {
	int x, y, d;
};
struct comb {
	string com;
	int cnt;//물고기 지워지는 거 확인.
};
struct newArray {
	vector<int>idxvalues;//물고기 갯수,몇 번 인덱스들이 있는지 확인.
	int smell;//물고기 냄새 알아보기.
};
map<int, loc>convert = { {1,{0,-1}},{2,{-1,-1}},{3,{-1,0}},{4,{-1,1}},{5,{0,1}},
	{6,{1,1}},{7,{1,0}},{8,{1,-1}} };//숫자를 방향으로 바꾸기
map<int, int>sharkconvert = { {1,3},{2,1},{3,7},{4,5} };
newArray arr[6][6];//물고기 냄새 남기자.
int m, s;//m개의 물고기가 있음.
vector<FISH>fishes;//물고기들
vector<FISH>temp;//전에 물고기 정보들 쌓아놓기.
loc shark;
int getfish() {
	return fishes.size();
}
bool isboundary(int x, int y) {
	return (x >= 0 && x < 4) && (y >= 0 && y < 4);
}
void fishmove() {//물고기 움직이기.
	int idx = 0;//해당 인덱스를 지울 수 있도록
	for (auto& [x, y, d] : fishes) {
		temp.push_back({ x,y,d });//미리 값 넣어주기.
		int sit = 0;//자리 셋팅 되는지 확인.
		while (sit != 8) {
			auto next = convert[d];
			int nx = x + next.x;
			int ny = y + next.y;
			sit++;
			if (!isboundary(nx, ny)) {
				d = ((d - 1) == 0 ? 8 : d - 1);//반시계로 돌려서 될때까지.
				continue;
			}
			else if (shark.x == nx && shark.y == ny) {//상어 있는 자리인지.
				d = ((d - 1) == 0 ? 8 : d - 1);
				continue;
			}
			else if (arr[nx][ny].smell) {//물고기 냄새 나는지 확인
				d = ((d - 1) == 0 ? 8 : d - 1);
				continue;
			}
			//이제는 자리에 가도 됨.
			x = nx;
			y = ny;
			break;
		}
		arr[x][y].idxvalues.push_back(idx++);//무조건 번호 알아야되기 때문.
	}
}
void sharkmove(int depth) {//상어 움직이기
	comb maxcomb = { "",-1 };
	comb tmp = { "",0 };
	int visited[5][5] = { 0 };
	for (auto first : { 1,2,3,4 }) {//상좌하우 1->3 , 2->1 3->7 4-> 5
		auto firstmove = convert[sharkconvert[first]];
		if (!isboundary(firstmove.x + shark.x, firstmove.y + shark.y))continue;
		bool firstplus = true;
		tmp.cnt += (int)arr[firstmove.x + shark.x][firstmove.y + shark.y].idxvalues.size();
		visited[firstmove.x + shark.x][firstmove.y + shark.y]++;
		for (auto second : { 1,2,3,4 }) {
			bool secondary = false;
			auto secondmove = convert[sharkconvert[second]];
			if (!isboundary(firstmove.x + shark.x + secondmove.x, firstmove.y + shark.y + secondmove.y))continue;
			if (!visited[firstmove.x + shark.x + secondmove.x][firstmove.y + shark.y + secondmove.y]) {
				//이미 방문했으면 안 더함.
				secondary = true;
				tmp.cnt += (int)arr[firstmove.x + shark.x + secondmove.x][firstmove.y + shark.y + secondmove.y].idxvalues.size();
				visited[firstmove.x + shark.x + secondmove.x][firstmove.y + shark.y + secondmove.y]++;
			}
			for (auto third : { 1,2,3,4 }) {//상 좌 하 우
				//움직이는 방향 골랐음 1 -> 3, 2 -> 1,3 -> 7, 4 -> 5
				bool thirdary = false;
				auto thirdmove = convert[sharkconvert[third]];
				if (!isboundary(firstmove.x + shark.x + secondmove.x + thirdmove.x, firstmove.y + shark.y + secondmove.y + thirdmove.y))continue;
				//무조건 움직일 수 있는 경로로 왔음.
				if (!visited[firstmove.x + shark.x + secondmove.x + thirdmove.x][firstmove.y + shark.y + secondmove.y + thirdmove.y]) {
					//이미 방문했으면 안 더함.
					thirdary = true;
					tmp.cnt += (int)arr[firstmove.x + shark.x + secondmove.x + thirdmove.x][firstmove.y + shark.y + secondmove.y + thirdmove.y].idxvalues.size();
					visited[firstmove.x + shark.x + secondmove.x + thirdmove.x][firstmove.y + shark.y + secondmove.y + thirdmove.y]++;
				}
				string strtmp;
				strtmp.push_back(first + '0');
				strtmp.push_back(second + '0');
				strtmp.push_back(third + '0');
				if (tmp.cnt > maxcomb.cnt) {//많이 먹고 온 것을 바꿔줌
					maxcomb.cnt = tmp.cnt;
					maxcomb.com = strtmp;
				}
				else if (tmp.cnt == maxcomb.cnt) {//같으면
					if (strtmp < maxcomb.com) {
						maxcomb.com = strtmp;
					}
				}
				if (thirdary) {
					tmp.cnt -= (int)arr[firstmove.x + shark.x + secondmove.x + thirdmove.x][firstmove.y + shark.y + secondmove.y + thirdmove.y].idxvalues.size();
					visited[firstmove.x + shark.x + secondmove.x + thirdmove.x][firstmove.y + shark.y + secondmove.y + thirdmove.y]--;
				}
			}
			if (secondary) {
				tmp.cnt -= (int)arr[firstmove.x + shark.x + secondmove.x][firstmove.y + shark.y + secondmove.y].idxvalues.size();
				visited[firstmove.x + shark.x + secondmove.x][firstmove.y + shark.y + secondmove.y]--;
			}

		}
		tmp.cnt -= (int)arr[firstmove.x + shark.x][firstmove.y + shark.y].idxvalues.size();
		visited[firstmove.x + shark.x][firstmove.y + shark.y]--;
	}
	set<int>minusidx;
	vector<FISH>fishtmp;//물고기 좌표 옮겨 놓기.
	for (auto& value : maxcomb.com) {//움직이면서 없애주기.
		auto nextloc = convert[sharkconvert[value - '0']];
		auto& sharkloc = shark;
		sharkloc.x += nextloc.x;
		sharkloc.y += nextloc.y;
		for (auto& vales : arr[sharkloc.x][sharkloc.y].idxvalues) {//해당하는 곳에 있는 물고기들.
			minusidx.insert(vales);
			arr[sharkloc.x][sharkloc.y].smell = depth;//s일 때
			arr[sharkloc.x][sharkloc.y].idxvalues.clear();//다 비우기
		}
	}
	for (int i = 0; i < (int)fishes.size(); i++) {
		if (minusidx.find(i) == minusidx.end()) {//제거할 대상이 아닐 때
			fishtmp.push_back(fishes[i]);
		}
	}
	fishes = fishtmp;//값 덮어쓰기.
}
void deletefish(int depth) {//물고기 냄새 없애기
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j].smell - depth >= 2) {//냄새가 사라져야 해요.
				arr[i][j].smell = 0;//냄새 사라짐 
			}
		}
	}
}
void copyfish() {
	while (!temp.empty()) {
		auto& value = temp.back(); temp.pop_back();
		fishes.push_back(value);//값 하나씩 다 넣어주기.
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j].idxvalues.clear();//인덱스 다 없애고 다시 넣자.
		}
	}
}
void solve() {
	int cnt = 0;
	while (s--) {//연습 횟수만큼 진행
		fishmove();//모든 물고기 움직이기.
		sharkmove(s + 1);//상어 이동하기.
		if (cnt >= 2) {
			deletefish(s + 1);//마법 연습 2번 전 것이 있으면 냄새 삭제하기.
		}
		copyfish();
		cnt++;
	}
	cout << getfish();
}
int main() {
	fast;
	cin >> m >> s;
	while (m--) {
		int x, y, d;//좌표와 방향까지
		cin >> x >> y >> d;
		fishes.push_back({ x - 1,y - 1,d });
	}
	cin >> shark.x >> shark.y;
	shark.x--;
	shark.y--;
	solve();
	return 0;
}