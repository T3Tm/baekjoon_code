#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
	https://www.acmicpc.net/problem/20056
	20056�� ������ ���� ���̾
	m���� ���̾

	1�� ���� N�� ��� ����
	1�� ���� N�� ���� ����


	1. ��� ���̾�� �ڽ��� ���� di�� si ��ŭ �̵�
		- ���� ĭ�� ���� ���� ���̾�� ���� ���� ����.
	2. �̵��� ��� ���� ��, 2�� �̻��� ���̾�� �ִ� ĭ
		1. ���̾�� ��� �ϳ��� ��ģ��
		2. ���̾�� 4���� ���̾�� ����������.
			������ (������ �� /5)  ��  �� ���� 5��� üũ �ؾߵ�.
			�ӷ� (�ӷ� �� / ���̾ ����)
			�������� ���̾�� ������ ��� Ȧ���̰ų�, ��� ¦���̸� 0,2,4,6
			�ƴϸ� 1,3,5,7
		3. ������ 0�� ���̾�� �Ҹ�Ǿ� ��������.
*/
using namespace std;
int n, m, k;
typedef struct fireball {
	int r, c, m, s, d;
}fireball;
vector<fireball>fireballs;//���̾ ��ǥ��
vector<fireball>temp;
map<int, pair<int, int>>MOVE = { {0,{-1,0}},{1,{-1,1}},{2,{0,1}},{3,{1,1}},{4,{1,0}},
	{5,{1,-1}},{6,{0,-1}},{7,{-1,-1}} };
void boundary(int& x) {
	if (x >= n) {
		x %= n;
	}
	else if (x < 0) {//���������� ���ƿ;���.
		int value = ((-x) % n);
		value = value ? value : n;
		x = n - value;//�������� 0�� ������ ��찡 ����.
	}
}
void move(vector<vector<vector<int>>>& M_S) {//���̾�� �̵��� �� �迭�� ��������.
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
			if (M_S[i][j].size() >= 2) {//2�� �̻� �ִٴ� ����.
				long long mess = 0, vel = 0;
				bool odd = false, even = false, direct = false;//direct true�� 1,3,5,7
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
			else if (M_S[i][j].size() == 1) {//���̾�� �ֱ� ��. ���� ����,
				int idx = M_S[i][j][0];
				fireballs.push_back({ i,j,temp[idx].m,temp[idx].s,temp[idx].d });
			}
		}
	}
	temp.clear();
}
void solve() {
	while (k--) {//k�� ����� ����.
		vector<vector<vector<int>>>M_S(52, vector<vector<int>>(52));
		//first���� ��� ���� , second���� ��� �ӷ��̴�.
		move(M_S);//d�� �������� s��ŭ �����̱�.
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

