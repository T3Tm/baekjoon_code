#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/23289
	23289번 온풍기 안녕!
	r*c인 격자판이다. 
	
	init작업을 한다.
	1. 집에 있는 모든 온풍기에서 바람이 한 번 나온다.
	2. 온도가 조절된다
	3. 초콜릿 하나 먹기
	4. 조사칸 온도 확인

	1이면 오른쪽 온풍기 (0,1)
	2이면 왼쪽 온풍기 (0,-1)
	3이면 위 온풍기 (-1,0)
	4이면 아래 온풍기 (1,0)

*/
using namespace std;
pair<int, int>MOVE[]{ {0,1},{0,-1},{-1,0},{1,0} };//오,왼,위,아
int wallcheck[]{1,3,0,2};//dfs 중 벽 체크할 때
struct myarr {
	int num,temper;
	bool wall[4];//위,오,아,왼
};
struct heater {
	int x, y, dir;//방향도 있어야한다.
};
struct loc {
	int x, y;
};
int r, c,w,k;
myarr arr[22][22];
vector<heater>heaters;
vector<loc>view;
bool boundary(loc& pre) {
	return pre.x < 0 || pre.x >= r || pre.y < 0 || pre.y >= c;
}
bool wallchecking(int alpha,int dir,loc& pre,loc next) {//방향과 얼만큼 더하는지 체크
	if (alpha < 0) {//-1
		if (dir == 1) {//오른쪽 위
			return arr[pre.x][pre.y].wall[0] || arr[next.x][next.y].wall[3];
		}
		else if (dir == 2) {
			//왼쪽 위
			return arr[pre.x][pre.y].wall[0] || arr[next.x][next.y].wall[1];
		}
		else if (dir == 3) {
			//위 왼쪽
			return arr[pre.x][pre.y].wall[3] || arr[next.x][next.y].wall[2];
		}
		else {
			//아래 왼쪽
			return arr[pre.x][pre.y].wall[3] || arr[next.x][next.y].wall[0];
		}
	}
	else if (alpha) {//위,오,아,왼
		if (dir == 1) {//
			//오른쪽 아래
			return arr[pre.x][pre.y].wall[2] || arr[next.x][next.y].wall[3];
		}
		else if (dir == 2) {
			//왼쪽 아래
			return arr[pre.x][pre.y].wall[2] || arr[next.x][next.y].wall[1];//
		}
		else if (dir == 3) {
			//위 오른쪽
			return arr[pre.x][pre.y].wall[1] || arr[next.x][next.y].wall[2];
		}
		else {
			//아래 오른쪽
			return arr[pre.x][pre.y].wall[1] || arr[next.x][next.y].wall[0];
		}
	}
	else {//0이다.
		//여기서는 dir에 맞게 그냥 다음에 벽이 있는지 확인
		return arr[pre.x][pre.y].wall[wallcheck[dir-1]];
		//현재 좌표에서 단순히 그 위 , 왼쪽, 오른쪽, 왼쪽에 벽체크
	}
}
void winddfs(loc pre,int value,int dir,bool visited[][22]) {
	visited[pre.x][pre.y] = 1;//현재 장소 방문했음 더이상 값 올리면 안됨.
	arr[pre.x][pre.y].temper+=value;
	if (value == 0)return;//현재 0이면 더이상 진행 안됨.
	if (dir <= 1) {//오른쪽 왼쪽
		auto [dx, dy] = MOVE[dir];//오른쪽 또는 왼쪽으로 갈 때
		for (int i = -1; i <= 1; i++) {
			loc next = { pre.x + dx + i ,pre.y + dy };
			if (boundary(next))continue;//넘어감.
			if (wallchecking(i, dir+1, pre, next))continue;//벽 때문에 못 감.
			//바람이 갈 수 있음.
			if (visited[next.x][next.y])continue;//이미 갔던 바람 좌표면 다시 가면 안됨.
			winddfs(next, value - 1, dir, visited);
		}
	}
	else {//위 아래
		auto [dx, dy] = MOVE[dir];//오른쪽 또는 왼쪽으로 갈 때
		for (int i = -1; i <= 1; i++) {
			loc next = { pre.x + dx ,pre.y + dy +i};
			if (boundary(next))continue;//넘어감.
			if (wallchecking(i, dir + 1, pre, next))continue;//벽 때문에 못 감.
			//바람이 갈 수 있음.
			if (visited[next.x][next.y])continue;//이미 갔던 바람 좌표면 다시 가면 안됨.
			winddfs(next, value - 1, dir, visited);
		}
	}
}
void windy() {
	for (auto [x, y, dir] : heaters) {
		bool visited[22][22]{ 0 };//이미 그 칸에 바람이 도착했었는지 확인.
		auto [dx, dy] = MOVE[dir];//한 번 더하고 바람 불기 시작해야되는데
		loc pre = { x,y }, next = {x+dx,y+dy};
		if (boundary(next))continue;//경계면 넘어가면안됨.
		if (wallchecking(0, dir + 1, pre, next))continue;//벽 있어서 애초에 바람 못 붊
		winddfs(next,5,dir,visited);//바람이 불기
	}
}
void control() {
	vector<tuple<loc, loc, int>>temp;//큰 좌표, 작은 좌표 , 얼마나
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			//현재 좌표에서 오른쪽 아래를 보고 비교하면됨~ 오른쪽 아래만 보기에
			loc pre = { i,j };
			for (auto nextdir : { 0,3 }) {//오른쪽 아래
				auto [dx, dy] = MOVE[nextdir];
				loc next = { pre.x + dx,pre.y + dy };
				if (boundary(next))continue;//경계면 체크
				if (wallchecking(0, nextdir+1, pre, next))continue;//벽 있음
				//이제는 벽 없어서 공기 섞여도 됨.
				if (abs(arr[i][j].temper - arr[next.x][next.y].temper)/4 > 0) {//
					//온도 조절돼야한다.
					if (arr[i][j].temper > arr[next.x][next.y].temper) {
						temp.push_back({ { i,j }, next, abs(arr[i][j].temper - arr[next.x][next.y].temper) / 4 });
					}
					else {
						temp.push_back({ next ,{ i,j }, abs(arr[i][j].temper - arr[next.x][next.y].temper) / 4 });
					}
				}
			}
		}
	}
	while (!temp.empty()) {//한꺼번에 쿼리 처리하기.
		auto [big, small, value] = temp.back(); temp.pop_back();
		arr[big.x][big.y].temper -= value;
		arr[small.x][small.y].temper += value;
	}
}
bool temperature() {
	for (auto [x, y] : view) {
		if (arr[x][y].temper < k)return true;
	}
	return false;
}
void boundarycontrol() {
	//오른쪽 아래,왼쪽 위 순서로 돌아보자.
	loc first={0,0};
	for (int next : {0, 3, 1, 2}) {
		auto [dx, dy] = MOVE[next];
		if (next <= 1) {
			for (int i = 0; i < c - 1; i++) {
				loc next = { first.x+ dx,first.y + dy };
				if (arr[next.x][next.y].temper>=1)arr[next.x][next.y].temper--;
				first = next;
			}
		}
		else {
			for (int i = 0; i < r - 1; i++) {
				loc next = { first.x + dx,first.y + dy };
				if (arr[next.x][next.y].temper >= 1)arr[next.x][next.y].temper--;
				first = next;
			}
		}
	}
}
void solve() {
	int answer=0;
	do {
		windy();//바람이 나온다.
		control();//온도 조절
		boundarycontrol();//바깥부분 온도조절
		answer++;//초콜릿 먹기 yum
	} while (temperature() && answer < 101);
	cout << answer;
}
int main() {
	fast; cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j].num;
			if (arr[i][j].num == 5)view.push_back({ i,j });
			else if (arr[i][j].num)heaters.push_back({i,j,arr[i][j].num-1});
			arr[i][j].temper = 0;
		}
	}
	cin >> w;
	while (w--) {
		int r, c, t; cin >> r >> c >> t; r--, c--;
		arr[r][c].wall[t] = 1;//
		if (t) arr[r][c +1].wall[t + 2] = 1;
		else arr[r - 1][c].wall[t + 2] = 1;
	}
	solve();
	return 0;
}