#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/21611
	21611번 마법사 상어와 블리자드
	구슬 1~3번까지 있다.

	1. 블리자드 마법 d방향으로 s거리까지 시전한다. (구슬 파괴된다.)
	2. 빈 칸으로 옮겨주기. (빈 칸으로 값 다 땡겨주기.)
	3. 폭발한다.(연속으로 4개 이상 똑같은 구슬)
	4. 빈 칸으로 옮겨주기. (2번 동작)
	5. 다시 3번 동작 한다.
	6.폭발할 것이 없을 때 구슬이 변한다.
	(변하는 것은 새로운 배열을 만드는 것으로 한다.)
	(A,B) <= 갯수,구슬의 번호 (갯수는 최대그럼 3까지만 들어갈 수 있음.) 4이면 불가능 왜냐면 폭발해야되니까
	7. M번의 마법 시전함.
	터진 구슬 갯수 관리해야됨.

	방향, 더하기
*/
using namespace std;
struct dynamite {
	int one, two, three;
};
struct loc {//위치
	int x, y;
};
struct pointer {
	int x, y, d, plus, pluscnt;//x,y좌표, d 방향 plus만큼 움직여야된다.
};
int n, m;
dynamite save;//갯수 저장.
int arr[52][52];
map<int, loc>MOVE = { {1,{-1,0}},{2,{1,0}},{3,{0,-1}},{4,{0,1}} };
map<int, int>Nextconvert = { {3,2},{2,4},{4,1},{1,3} };//방향 바꿀 떄
loc shark;
void destruction(int d, int s) {//방향 파괴
	auto value = MOVE[d];
	int xplus = value.x, yplus = value.y;
	while (s--) {//
		arr[shark.x + xplus][shark.y + yplus] = 0;//0으로 바꾸기
		xplus += value.x; yplus += value.y;
	}
}
void beadPulling() {
	pointer empty = { n / 2,n / 2 - 1,2,1,1 };//상어 왼쪽부터 시작해서 아래로 내려간다.
	//첫 번째 0이 아닌 것들만 해서 배열에 다 넣는다. 2번째 그 값들을 하나씩 다 빼온다.
	int tmparr[5000] = { 0 }, tmpidx = 0;//배열에 값 다 넣기.
	bool exitpoint = false;
	while (!exitpoint) {//tmparr에 값 다 쌓아주기.
		auto next_xy = MOVE[empty.d];//해당 좌표의 방향을 확인 후 더해준다.
		for (int i = 0; i < empty.plus; i++) {//plus만큼만 이동할 거임
			if (empty.x == 0 && empty.y == -1) {//나가야됨.
				exitpoint = true;
				break;
			}
			if (arr[empty.x][empty.y]) {//값이 비어있지 않으면 해당 값 tmparr에 넣어주기
				tmparr[tmpidx++] = arr[empty.x][empty.y];
			}
			empty.x += next_xy.x;
			empty.y += next_xy.y;
		}
		empty.pluscnt++;
		if (empty.pluscnt == 2) {
			empty.pluscnt = 0;
			empty.plus++;//하나 증가
		}
		empty.d = Nextconvert[empty.d];
	}
	empty = { n / 2,n / 2 - 1,2,1,1 };
	exitpoint = false;
	tmpidx = 0;
	while (!exitpoint) {
		auto next_xy = MOVE[empty.d];//해당 좌표의 방향을 확인 후 더해준다.
		for (int i = 0; i < empty.plus; i++) {//plus만큼만 이동할 거임
			if (empty.x == 0 && empty.y == -1) {//나가야됨.
				exitpoint = true;
				break;
			}
			arr[empty.x][empty.y] = tmparr[tmpidx++];
			empty.x += next_xy.x;
			empty.y += next_xy.y;
		}
		empty.pluscnt++;
		if (empty.pluscnt == 2) {
			empty.pluscnt = 0;
			empty.plus++;//하나 증가
		}
		empty.d = Nextconvert[empty.d];
	}
}
bool bangbead() {//연속해서 같은 구슬 있는지 확인.
	int number = -1;
	vector<loc>tmploc;//터져야 되는 구슬들 좌표.
	pointer empty = { n / 2,n / 2 - 1,2,1,1 };
	bool exitpoint = false, returnvalue = false;
	while (!exitpoint) {
		auto next_xy = MOVE[empty.d];//해당 좌표의 방향을 확인 후 더해준다.
		for (int i = 0; i < empty.plus; i++) {//plus만큼만 이동할 거임
			if (empty.x == 0 && empty.y == -1) {//나가야됨.
				exitpoint = true;
				break;
			}
			if (arr[empty.x][empty.y] != number) {//쌓아온 구슬 숫자 다르다면?
				if ((int)tmploc.size() >= 4) {//연속해서 숫자가 동일한 게 나왔네.
					returnvalue = true;//한 번이라도 터진 적 있음.
					if (number == 1) {//폭발한 갯수 더해주기.
						save.one += tmploc.size();
					}
					else if (number == 2) {
						save.two += tmploc.size();
					}
					else if (number == 3) {
						save.three += tmploc.size();
					}
					while (!tmploc.empty()) {//터트려주기.
						auto spot = tmploc.back(); tmploc.pop_back();
						arr[spot.x][spot.y] = 0;//터진 것
					}
				}
				number = arr[empty.x][empty.y];//다른 숫자다시 쌓아주기.
				tmploc.clear();
				tmploc.push_back({ empty.x,empty.y });
			}
			else {//숫자가 같을 때
				tmploc.push_back({ empty.x,empty.y });//좌표만 쌓아주면 됨.
			}
			empty.x += next_xy.x;
			empty.y += next_xy.y;
		}
		empty.pluscnt++;
		if (empty.pluscnt == 2) {
			empty.pluscnt = 0;
			empty.plus++;//하나 증가
		}
		empty.d = Nextconvert[empty.d];
	}
	return returnvalue;//터진 적 있는지 알려주기.
}
void transbead() {//구슬 변화하기.
	int number = 0, cnt = 0;
	pointer empty = { n / 2,n / 2 - 1,2,1,1 };
	bool exitpoint = false;
	int tmparr[2404] = { 0 }, tmpidx = 0;//배열에 값 다 넣기.
	while (!exitpoint) {
		auto next_xy = MOVE[empty.d];//해당 좌표의 방향을 확인 후 더해준다.
		for (int i = 0; i < empty.plus; i++) {//plus만큼만 이동할 거임
			if (empty.x == 0 && empty.y == -1 || !arr[empty.x][empty.y]) {//배열을 초과하거나, 0인 값이면 그냥 나가기.
				exitpoint = true;
				break;
			}
			if (arr[empty.x][empty.y] != number) {//쌓아온 구슬 숫자 다르다면?
				if (tmpidx >= n * n) {//0부터 넣기 때문에.
					exitpoint = true;
					break;
				}
				if (number != 0) {
					tmparr[tmpidx] = cnt;
					tmparr[tmpidx + 1] = number;
					tmpidx += 2;//idx는 2개 커져야 된다.
				}
				number = arr[empty.x][empty.y];//다른 숫자다시 쌓아주기.
				cnt = 1;
			}
			else {//숫자가 같을 때
				cnt++;
			}
			empty.x += next_xy.x;
			empty.y += next_xy.y;
		}
		empty.pluscnt++;
		if (empty.pluscnt == 2) {
			empty.pluscnt = 0;
			empty.plus++;//하나 증가
		}
		empty.d = Nextconvert[empty.d];
	}
	if (tmpidx < n * n) {
		tmparr[tmpidx] = cnt;
		tmparr[tmpidx + 1] = number;
	}
	empty = { n / 2,n / 2 - 1,2,1,1 };
	exitpoint = false;
	tmpidx = 0;
	while (!exitpoint) {
		auto next_xy = MOVE[empty.d];//해당 좌표의 방향을 확인 후 더해준다.
		for (int i = 0; i < empty.plus; i++) {//plus만큼만 이동할 거임
			if (empty.x == 0 && empty.y == -1) {//배열을 초과하거나, 0인 값이면 그냥 나가기.
				exitpoint = true;
				break;
			}
			arr[empty.x][empty.y] = tmparr[tmpidx++];//tmp에 옮긴 거 arr에 다 넣어주기.
			empty.x += next_xy.x;
			empty.y += next_xy.y;
		}
		empty.pluscnt++;
		if (empty.pluscnt == 2) {
			empty.pluscnt = 0;
			empty.plus++;//하나 증가
		}
		empty.d = Nextconvert[empty.d];
	}
}
void solve() {
	while (m--) {
		int d, s;//d방향으로 s거리만큼 파괴하면서 시작.
		cin >> d >> s;
		destruction(d, s);//구슬 파괴한다~
		beadPulling();//구슬 다 땡겼음.
		bool next_bang = bangbead();//구슬 터지기.
		while (next_bang) {//터진 적이 없을 때까지
			beadPulling();//땡기는 작업 수행하기.
			next_bang = bangbead();
		}
		transbead();//구슬 이제 변화시키기.
	}
}
int main() {
	fast;
	cin >> n >> m;//행 열, 마법시전 수
	shark = { n / 2,n / 2 };//초기 상어 위치.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	cout << 1 * save.one + 2 * save.two + 3 * save.three;
	return 0;
}