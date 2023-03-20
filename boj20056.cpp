#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
	https://www.acmicpc.net/problem/20056
	20056번 마법사 상어와 파이어볼
	m개의 파이어볼

	1번 행은 N번 행과 연결
	1번 열은 N번 열과 연결


	1. 모든 파이어볼이 자신의 방향 di로 si 만큼 이동
		- 같은 칸에 여러 개의 파이어볼이 있을 수도 있음.
	2. 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸
		1. 파이어볼은 모두 하나로 합친다
		2. 파이어볼은 4개의 파이어볼로 나누어진다.
			질량은 (질량의 합 /5)  즉  일 때는 5라고 체크 해야됨.
			속력 (속력 합 / 파이어볼 갯수)
			합쳐지는 파이어볼의 방향이 모두 홀수이거나, 모두 짝수이면 0,2,4,6
			아니면 1,3,5,7
		3. 질량이 0인 파이어볼은 소멸되어 없어진다.
*/
using namespace std;
int n, m, k;
typedef struct fireball {
	int r, c, m, s, d;
}fireball;
vector<fireball>fireballs;//파이어볼 좌표들
vector<fireball>temp;
map<int, pair<int, int>>MOVE = { {0,{-1,0}},{1,{-1,1}},{2,{0,1}},{3,{1,1}},{4,{1,0}},
	{5,{1,-1}},{6,{0,-1}},{7,{-1,-1}} };
void boundary(int& x) {
	if (x >= n) {
		x %= n;
	}
	else if (x < 0) {//오른쪽으로 돌아와야함.
		int value = ((-x) % n);
		value = value ? value : n;
		x = n - value;//나머지가 0이 나오는 경우가 생김.
	}
}
void move(vector<vector<vector<int>>>& M_S) {//파이어볼들 이동할 때 배열에 저장하자.
	int idx = 0;
	for (auto& loc : fireballs) {
		auto next = MOVE[loc.d];
		loc.r += (next.first * loc.s);
		loc.c += (next.second * loc.s);
		boundary(loc.r);
		boundary(loc.c);
		M_S[loc.r][loc.c].push_back(idx++);
		temp.push_back({ loc.r,loc.c,loc.m,loc.s,loc.d });
	}
}
void NewFireball(vector<vector<vector<int>>>& M_S) {
	fireballs.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (M_S[i][j].size() >= 2) {//2개 이상 있다는 거임.
				long long mess = 0, vel = 0;
				bool odd = false, even = false, direct = false;//direct true는 1,3,5,7
				for (auto& loc : M_S[i][j]) {
					mess += temp[loc].m;
					vel += temp[loc].s;
					if (temp[loc].d % 2 == 0) {
						even = true;
					}
					else {
						odd = true;
					}
				}
				int insertmess = mess / 5;
				int insertvel = vel / (int)M_S[i][j].size();
				if (even && odd) {
					if (insertmess) {
						fireballs.push_back({ i,j,insertmess,insertvel,1 });
						fireballs.push_back({ i,j,insertmess,insertvel, 3 });
						fireballs.push_back({ i,j,insertmess,insertvel, 5 });
						fireballs.push_back({ i,j,insertmess,insertvel, 7 });
					}
				}
				else {
					if (insertmess) {
						fireballs.push_back({ i,j,insertmess,insertvel,0 });
						fireballs.push_back({ i,j,insertmess,insertvel, 2 });
						fireballs.push_back({ i,j,insertmess,insertvel, 4 });
						fireballs.push_back({ i,j,insertmess,insertvel, 6 });
					}
				}
			}
			else if (M_S[i][j].size() == 1) {//파이어볼이 있긴 함. 전에 방향,
				int idx = M_S[i][j][0];
				fireballs.push_back({ i,j,temp[idx].m,temp[idx].s,temp[idx].d });
			}
		}
	}
	temp.clear();
}
void solve() {
	while (k--) {//k의 명령을 보냄.
		vector<vector<vector<int>>>M_S(52, vector<vector<int>>(52));
		//first같은 경우 질량 , second같은 경우 속력이다.
		move(M_S);//d의 방향으로 s만큼 움직이기.
		NewFireball(M_S);
	}
	long long temp = 0;
	for (auto& value : fireballs) {
		temp += value.m;
	}
	cout << temp;
}
int main() {
	fast;
	cin >> n >> m >> k;
	while (m--) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireballs.push_back({ r - 1,c - 1,m,s,d });
	}
	solve();
	return 0;
}

