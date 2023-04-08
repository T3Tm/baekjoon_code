#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17081
	17081번 RPG Extreme
	n*m 그리드의 RPG 게임이다.

	1. 빈칸은 자유롭게 입장할 수 있는 칸이다.(@ 주인공 칸)
	2. #은 벽이다.
	3. 아이템 상자(B)
		1.장비 중 하나가 들어있음.
			1. 무기(W), 갑옷(A), 장신구(O) 3가지로 구분
			2. 무기/방어구는 얻은 장비로 교체된다.(즉 전에 입었던 것을 신경 안 씀)
			2-1 장신구는 칸이 남았으면서 동일한 효과의 장신구가 없어야 한다.
			(빈칸 처리)
	4. 가시 함정(^)
		1. 밟았을 시 5의 데미지를 입음, 사망 가능
		2. 밟아도 안 사라짐(빈칸 처리 하면 안됨.)
		3. 만약 내가 벽에 부딪히거나, 다음 칸으로 못 가서 동일한 칸에 멈추게 되면
		함정을 또 밟게 돼서 피를 줄여줘야함.
	5. 몬스터(&)
		1. 알파벳 대소문자의 문자열로 된 이름 Atk,def,hp,exp 존재
		2. 몬스터 칸에 입장하면 전투,
			2-1 주인공이 무조건 선공한다.
			주인공, 몬스터, 주인공 < 이런 순서
			각자 max(1,공격력 - 상대방의 방어력) 만큼의 데미지를 서로에게 한 번씩만 입힌다.
			한 쪽의 체력이 0이하가 될 경우 전투는 즉시 종료된다. (while문으로 처리해주면 되네)
		3. 몬스터 사망 시 빈칸 처리 , 승리하면 몬스터 칸으로 이동 처리
		4. 이 모든 과정이 한 턴 내에 이뤄진다.
	6. 보스 몬스터(M)
		1. 몬스터와 동일하다. 게임의 목표는 보스 몬스터를 처치하는 것이다. << 이게 최종 목표


	1. 처음의 빈 칸 하나에서 시작한다.
	주인공  hp : 20 , atk : 2 , def : 2이다.
	처음 레벨 1 다음 레벨이 되려면 5*현재레벨을 하면된다.
		1. 레벨 오르면 hp가 5 증가, 공,방 +=2 hp는 풀로 회복
		2. 경험치를 얻어 다음 레벨이 되면 오를 경험치가 남아도 버린다.
	2. 무기 : 오직 하나만 착용 가능 (상자에서 얻었을 시 무조건 마지막에 착용한 걸로 해야됨.
		무기는 공격력을 갖고 있으며 주인공의 공격력에 더해진다.
		1. 무기로 인한 공격력 증가는 다른 모든 공격력 상승 효과보다 먼저 적용 된다.
		즉 -> 모든 다른 공격력 상승효과는 무기의 공격력까지 같이 상승시킨다.
	3. 방어구 : 한 개만 착용 가능(제일 마지막에 상자 열은 아이템을 착용해야됨.)
		주인공 방어력에 더해주면 된다.
	4. 장신구 : 최대 4개까지 착용 가능 (동일한 효과의 장시구는 최대 하나까지만 착용 가능).
		1. 체젠 : 전투에서 승리하면 체력 3 회복한다. 체력은 최대 체력 수치까지만 회복가능.
		2. RE : 주인공 사망, 주인공을 최대 체력으로 부활시켜 준 뒤, 주인공을 첫 시작 위치로 돌려보낸다.
		3. co : 모든 전투에서, 첫 공격에서 주인공의 공격이 두배로 적용된다.(그냥 무기 공격력을 주인공의 공격력으로 추가하면된다.)
			3-1. 첫 공격에서 max(1, 공격력*2 - 방어력) 데미지
		4. EX : 얻는 경험치가 1.2배가 된다. 소숫점 아래는 버린다.
		5. DX : 가시 함정에 있는 데미지가 1로 고정이다., co장신구와 함께 착용하면
			co의 공격력 효과가 두배로 적용되는 대신 세 배로 적용된다. 시너지 효과 있음.
		6. HU : 보스 몬스터와 전투 돌입하면 체력을 풀로 채워줌. 보스 몬스터의 첫 공격에 0 데미지.
		7. CU : 아무 능력이 없음.. 그냥 한 자리 차지용

	1. 한 칸 이동한다. (문자열로 커맨드 주어짐.) (벽이거나, 그리드 밖으로 나가면 나가지 않음 처리)
	2. 보스 몬스터 처치, 주인공이 HP가 0 이하가 되어 죽거나, 커맨드를 끝나치면 게임 끝임.
	(보스 몬스터의 처치가 되면 경험치, 레벨업 장신구 효과 등도 모두 진행한 뒤 게임이 끝이 난다.)
	(움직이는 커맨드가 끝나지 않았는데, hp 0 되거나 보스에 의해 죽으면 남은 입력 무시)
	3. 그리드의 상태를 출력
		1. 주인공 : @ (무조건 그 위치에 놓음)
			-1. 죽으면 @이것이 없음
		2. 빈칸 : .
		3. 벽 : #
		4. 보스가 아닌 몬스터 : &
		5. 보스 몬스터 : M (죽으면 없앰)
		6. 가시 함정: ^(어차피 밟아도 안 없어짐.)
		7. 아이템 상자 : B(안 열렸으면)
		8. 진행된 턴 수 T:
			passed Turns : T
		9. 종료 시점의 주인공의 정보들
			LV : N
			HP : REM/CUR
			ATT : N+W
			DEF : N+A
			EXP : CUR/MAX
		10. 게임의 결과
			1. 보스 몬스터를 처치 했을 경우 : YOU WIN!
			2. 죽었으면 : YOU HAVE BEEN KILLED BY 몬스터의 이름, 가시 함정은 SPIKE TRAP..
			3. 입력이 끝났으면 Press any key to continue.

*/
using namespace std;
struct My {
	long long lv, hp, att, def, exp;
	//장신구 착용
	bool O[7];//HR,RE,CO,EX,DX,HU,CU
	int w, a, o, x, y;//각 각 몇 개씩 갖고 있는 지 알아내기. 그리고 좌표들 갖고 있기.
	int firstx, firsty;//처음 좌표도 갖고 있어볼까?
	int prehp;
};
struct monster {//s 몬스터 이름으로 w 공격력 , a 방어력 ,h체력 , e 경험치
	string s;
	int w, a, h, e;
};
struct item {
	char t;//어떤 종류의 아이템 
	string n;//무기든 방어구든 장신구이든 그냥 통일하자.
};
int n, m, k, l;//n*m 그리드의 k마리 l개의 상자
map<string, int>rings = { {"HR",0},{"RE",1},{"CO",2},{"EX",3},{"DX",4},{"HU",5},{"CU",6} };
vector<vector<char>>board;//맵 모형
monster minfo[102][102];
item iinfo[102][102];
My me;
string cmd;//커맨드
string answer;
bool dead;
bool Gameover;
map<char, pair<int, int>>MOVE = { {'L',{0,-1}},{'R',{0,1}},{'U',{-1,0}},{'D',{1,0}} };
bool isBound(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}
void MONSTER(int& x, int& y, bool isboss) {//특정 좌표 몬스터 정보 map에서 참조해보면됨
	auto [s, w, a, h, e] = minfo[x][y];
	int tmpattck = me.att + me.w;//처음의 자신의 공격력 + 무기 공격력
	int tmpamor = me.def + me.a;//나의 방어력 + 갑옷
	int mul = 1;
	if (me.O[2]) {//CO 공격력 2배
		mul++;
		if (me.O[4])mul++;//CO + DX 공격력 3배
	}
	tmpattck *= mul;//공격력 배해준다.
	if (isboss && me.O[5]) {
		me.prehp = me.hp;//풀 피 되기. 그리고 첫 턴에는 나만 공격 입힌다.
		h -= max(1, tmpattck - a);//몬스터의 체력 닳기
		tmpattck = me.att + me.w;
	}
	while (h > 0) {//몬스터의 체력이 먼저 닳거나 나의 체력이 닳기 전까지.
		h -= max(1, tmpattck - a);//몬스터의 체력 닳기
		if (h <= 0) {//몬스터 뒤짐.
			break;
		}
		me.prehp -= max(1, w - tmpamor);
		if (me.prehp <= 0) {//주인공 죽었음
			me.prehp = 0;
			answer = "YOU HAVE BEEN KILLED BY " + s + "..";
			dead = true;
			break;
		}
		tmpattck = me.att + me.w;
	}
	if (!dead) {//내가 승리했음.
		board[x][y] = '.';
		if (me.O[0]) {//HR반지
			me.prehp = min(me.prehp + 3, (int)me.hp);
		}
		if (me.O[3]) {//EX 반지
			e = e * 12 / 10;// 
		}
		me.exp += e;
		if (isboss) {
			answer = "YOU WIN!";
			Gameover = true;//보스전에서 끝났음.
		}
	}
}
void levelup() {
	if (me.exp >= me.lv * 5) {//레벨되는 경우.
		me.hp += 5;//최대 체력 5증가
		me.att += 2;
		me.def += 2;
		me.prehp = me.hp;//풀피
		me.exp = 0;//경험치 0으로 만들기. (나머지는 어차피 버려야됨.)
		me.lv++;//레벨 증가
	}
}
void items(int& x, int& y) {//아이템 얻는 거 확인.
	board[x][y] = '.';//해당 좌표로 갔으니 없애주자.
	auto [t, n] = iinfo[x][y];//t의 무기의 n
	if (t == 'W') {//공격력교체
		me.w = stoi(n);
	}
	else if (t == 'A') {//방어력교체
		me.a = stoi(n);
	}
	else {//장신구.
		if (me.o < 4 && !me.O[rings[n]]) {//0,1,2,3 일 때만 그리고 중복 안될 때
			me.O[rings[n]] = true;//착용됐다.
			me.o++;
		}
	}
}
void thorn(int& x, int& y) {//현재 좌표 가시 작업 해줘야됨.
	int minus = 5;
	if (me.O[4])minus = 1;//장신구가 있으면 데미지 1이 돼야함.
	me.prehp -= minus;//minus만큼 뺀다.
	if (me.prehp <= 0) {//죽었습니다.
		me.prehp = 0;//죽었으니까 일단 피는 0으로 만들어놓자.
		answer = "YOU HAVE BEEN KILLED BY SPIKE TRAP..";
		dead = true;
	}
}
bool reincar() {//죽었을 때 들어옴
	if (me.O[1]) {//RE반지
		me.O[1] = false;//반지 삭제
		me.o--;//현재 갖고 있는 반지의 갯수도 줄여줘야한다.
		me.x = me.firstx, me.y = me.firsty;//첫 위치
		me.prehp = me.hp;//체력 부활
		return true;
	}
	return false;
}
void solve() {
	int turn = 0;
	board[me.x][me.y] = '.';//초기의 자신의 위치를 .으로 만들자.
	for (auto& value : cmd) {//커맨드에 따라서 유형에 나누자.
		auto [dx, dy] = MOVE[value];
		int nx = me.x + dx, ny = me.y + dy;
		if (isBound(nx, ny) || board[nx][ny] == '#') {//못 움직임.
			nx = me.x, ny = me.y;
		}
		turn++;
		if (board[nx][ny] == '&') {//몬스터일때
			MONSTER(nx, ny, false);//일반 몬스터
		}
		else if (board[nx][ny] == 'B') {//아이템
			items(nx, ny);
		}
		else if (board[nx][ny] == '^') {//가시
			thorn(nx, ny);
		}
		else if (board[nx][ny] == 'M') {//보스 몬스터
			MONSTER(nx, ny, true);
		}
		if (dead) {
			if (reincar()) {//부활
				dead = false;
				continue;
			}
			break;//죽었는지 판별.
		}
		me.x = nx, me.y = ny;
		levelup();
		if (Gameover)break;//보스전에서 이미 승리했음.
	}
	if (!dead) {//나 안 죽었음.
		board[me.x][me.y] = '@';
	}
	if (!dead && !Gameover)answer = "Press any key to continue.";
	for (auto& row : board) {
		for (auto& tvalue : row) {
			cout << tvalue;
		}
		cout << endl;
	}
	cout << "Passed Turns : " << turn << endl;
	cout << "LV : " << me.lv << endl;
	cout << "HP : " << me.prehp << '/' << me.hp << endl;
	cout << "ATT : " << me.att << '+' << me.w << endl;
	cout << "DEF : " << me.def << '+' << me.a << endl;
	cout << "EXP : " << me.exp << '/' << me.lv * 5 << endl;
	cout << answer;
}
int main() {
	fast;
	cin >> n >> m;
	board.resize(n, vector<char>(m + 1, ' '));
	me = { 1,20,2,2,0 };
	me.prehp = 20;//현재 피
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			if (tmp[j] == '@') {//주인공의 좌표 설정.
				me.x = i, me.y = j;
				me.firstx = i, me.firsty = j;//나중에 RE때문에 다시 태어나면 초기 위치에서 태어나야 하니까.
			}
			else if (tmp[j] == '&' || tmp[j] == 'M')k++;//몬스터의 갯수 알아내자.
			else if (tmp[j] == 'B')l++;//상자의 갯수 알아내기
			board[i][j] = tmp[j];
		}
	}
	cin >> cmd;
	for (int i = 0; i < k; i++) {
		int r, c, w, a, h, e;
		string s;
		cin >> r >> c >> s >> w >> a >> h >> e;
		minfo[r - 1][c - 1] = { s,w,a,h,e };//각각의 그리드에 있는 몬스터들 정보들 넣기.
	}
	for (int i = 0; i < l; i++) {
		int r, c;
		char t;
		string n;
		cin >> r >> c >> t >> n;//각각 입력 받기.
		iinfo[r - 1][c - 1] = { t,n };//저장하기~
	}
	solve();
	return 0;
}