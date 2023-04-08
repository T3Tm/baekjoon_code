#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17081
	17081�� RPG Extreme
	n*m �׸����� RPG �����̴�.

	1. ��ĭ�� �����Ӱ� ������ �� �ִ� ĭ�̴�.(@ ���ΰ� ĭ)
	2. #�� ���̴�.
	3. ������ ����(B)
		1.��� �� �ϳ��� �������.
			1. ����(W), ����(A), ��ű�(O) 3������ ����
			2. ����/���� ���� ���� ��ü�ȴ�.(�� ���� �Ծ��� ���� �Ű� �� ��)
			2-1 ��ű��� ĭ�� �������鼭 ������ ȿ���� ��ű��� ����� �Ѵ�.
			(��ĭ ó��)
	4. ���� ����(^)
		1. ����� �� 5�� �������� ����, ��� ����
		2. ��Ƶ� �� �����(��ĭ ó�� �ϸ� �ȵ�.)
		3. ���� ���� ���� �ε����ų�, ���� ĭ���� �� ���� ������ ĭ�� ���߰� �Ǹ�
		������ �� ��� �ż� �Ǹ� �ٿ������.
	5. ����(&)
		1. ���ĺ� ��ҹ����� ���ڿ��� �� �̸� Atk,def,hp,exp ����
		2. ���� ĭ�� �����ϸ� ����,
			2-1 ���ΰ��� ������ �����Ѵ�.
			���ΰ�, ����, ���ΰ� < �̷� ����
			���� max(1,���ݷ� - ������ ����) ��ŭ�� �������� ���ο��� �� ������ ������.
			�� ���� ü���� 0���ϰ� �� ��� ������ ��� ����ȴ�. (while������ ó�����ָ� �ǳ�)
		3. ���� ��� �� ��ĭ ó�� , �¸��ϸ� ���� ĭ���� �̵� ó��
		4. �� ��� ������ �� �� ���� �̷�����.
	6. ���� ����(M)
		1. ���Ϳ� �����ϴ�. ������ ��ǥ�� ���� ���͸� óġ�ϴ� ���̴�. << �̰� ���� ��ǥ


	1. ó���� �� ĭ �ϳ����� �����Ѵ�.
	���ΰ�  hp : 20 , atk : 2 , def : 2�̴�.
	ó�� ���� 1 ���� ������ �Ƿ��� 5*���緹���� �ϸ�ȴ�.
		1. ���� ������ hp�� 5 ����, ��,�� +=2 hp�� Ǯ�� ȸ��
		2. ����ġ�� ��� ���� ������ �Ǹ� ���� ����ġ�� ���Ƶ� ������.
	2. ���� : ���� �ϳ��� ���� ���� (���ڿ��� ����� �� ������ �������� ������ �ɷ� �ؾߵ�.
		����� ���ݷ��� ���� ������ ���ΰ��� ���ݷ¿� ��������.
		1. ����� ���� ���ݷ� ������ �ٸ� ��� ���ݷ� ��� ȿ������ ���� ���� �ȴ�.
		�� -> ��� �ٸ� ���ݷ� ���ȿ���� ������ ���ݷ±��� ���� ��½�Ų��.
	3. �� : �� ���� ���� ����(���� �������� ���� ���� �������� �����ؾߵ�.)
		���ΰ� ���¿� �����ָ� �ȴ�.
	4. ��ű� : �ִ� 4������ ���� ���� (������ ȿ���� ��ñ��� �ִ� �ϳ������� ���� ����).
		1. ü�� : �������� �¸��ϸ� ü�� 3 ȸ���Ѵ�. ü���� �ִ� ü�� ��ġ������ ȸ������.
		2. RE : ���ΰ� ���, ���ΰ��� �ִ� ü������ ��Ȱ���� �� ��, ���ΰ��� ù ���� ��ġ�� ����������.
		3. co : ��� ��������, ù ���ݿ��� ���ΰ��� ������ �ι�� ����ȴ�.(�׳� ���� ���ݷ��� ���ΰ��� ���ݷ����� �߰��ϸ�ȴ�.)
			3-1. ù ���ݿ��� max(1, ���ݷ�*2 - ����) ������
		4. EX : ��� ����ġ�� 1.2�谡 �ȴ�. �Ҽ��� �Ʒ��� ������.
		5. DX : ���� ������ �ִ� �������� 1�� �����̴�., co��ű��� �Բ� �����ϸ�
			co�� ���ݷ� ȿ���� �ι�� ����Ǵ� ��� �� ��� ����ȴ�. �ó��� ȿ�� ����.
		6. HU : ���� ���Ϳ� ���� �����ϸ� ü���� Ǯ�� ä����. ���� ������ ù ���ݿ� 0 ������.
		7. CU : �ƹ� �ɷ��� ����.. �׳� �� �ڸ� ������

	1. �� ĭ �̵��Ѵ�. (���ڿ��� Ŀ�ǵ� �־���.) (���̰ų�, �׸��� ������ ������ ������ ���� ó��)
	2. ���� ���� óġ, ���ΰ��� HP�� 0 ���ϰ� �Ǿ� �װų�, Ŀ�ǵ带 ����ġ�� ���� ����.
	(���� ������ óġ�� �Ǹ� ����ġ, ������ ��ű� ȿ�� � ��� ������ �� ������ ���� ����.)
	(�����̴� Ŀ�ǵ尡 ������ �ʾҴµ�, hp 0 �ǰų� ������ ���� ������ ���� �Է� ����)
	3. �׸����� ���¸� ���
		1. ���ΰ� : @ (������ �� ��ġ�� ����)
			-1. ������ @�̰��� ����
		2. ��ĭ : .
		3. �� : #
		4. ������ �ƴ� ���� : &
		5. ���� ���� : M (������ ����)
		6. ���� ����: ^(������ ��Ƶ� �� ������.)
		7. ������ ���� : B(�� ��������)
		8. ����� �� �� T:
			passed Turns : T
		9. ���� ������ ���ΰ��� ������
			LV : N
			HP : REM/CUR
			ATT : N+W
			DEF : N+A
			EXP : CUR/MAX
		10. ������ ���
			1. ���� ���͸� óġ ���� ��� : YOU WIN!
			2. �׾����� : YOU HAVE BEEN KILLED BY ������ �̸�, ���� ������ SPIKE TRAP..
			3. �Է��� �������� Press any key to continue.

*/
using namespace std;
struct My {
	long long lv, hp, att, def, exp;
	//��ű� ����
	bool O[7];//HR,RE,CO,EX,DX,HU,CU
	int w, a, o, x, y;//�� �� �� ���� ���� �ִ� �� �˾Ƴ���. �׸��� ��ǥ�� ���� �ֱ�.
	int firstx, firsty;//ó�� ��ǥ�� ���� �־��?
	int prehp;
};
struct monster {//s ���� �̸����� w ���ݷ� , a ���� ,hü�� , e ����ġ
	string s;
	int w, a, h, e;
};
struct item {
	char t;//� ������ ������ 
	string n;//����� ���� ��ű��̵� �׳� ��������.
};
int n, m, k, l;//n*m �׸����� k���� l���� ����
map<string, int>rings = { {"HR",0},{"RE",1},{"CO",2},{"EX",3},{"DX",4},{"HU",5},{"CU",6} };
vector<vector<char>>board;//�� ����
monster minfo[102][102];
item iinfo[102][102];
My me;
string cmd;//Ŀ�ǵ�
string answer;
bool dead;
bool Gameover;
map<char, pair<int, int>>MOVE = { {'L',{0,-1}},{'R',{0,1}},{'U',{-1,0}},{'D',{1,0}} };
bool isBound(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}
void MONSTER(int& x, int& y, bool isboss) {//Ư�� ��ǥ ���� ���� map���� �����غ����
	auto [s, w, a, h, e] = minfo[x][y];
	int tmpattck = me.att + me.w;//ó���� �ڽ��� ���ݷ� + ���� ���ݷ�
	int tmpamor = me.def + me.a;//���� ���� + ����
	int mul = 1;
	if (me.O[2]) {//CO ���ݷ� 2��
		mul++;
		if (me.O[4])mul++;//CO + DX ���ݷ� 3��
	}
	tmpattck *= mul;//���ݷ� �����ش�.
	if (isboss && me.O[5]) {
		me.prehp = me.hp;//Ǯ �� �Ǳ�. �׸��� ù �Ͽ��� ���� ���� ������.
		h -= max(1, tmpattck - a);//������ ü�� ���
		tmpattck = me.att + me.w;
	}
	while (h > 0) {//������ ü���� ���� ��ų� ���� ü���� ��� ������.
		h -= max(1, tmpattck - a);//������ ü�� ���
		if (h <= 0) {//���� ����.
			break;
		}
		me.prehp -= max(1, w - tmpamor);
		if (me.prehp <= 0) {//���ΰ� �׾���
			me.prehp = 0;
			answer = "YOU HAVE BEEN KILLED BY " + s + "..";
			dead = true;
			break;
		}
		tmpattck = me.att + me.w;
	}
	if (!dead) {//���� �¸�����.
		board[x][y] = '.';
		if (me.O[0]) {//HR����
			me.prehp = min(me.prehp + 3, (int)me.hp);
		}
		if (me.O[3]) {//EX ����
			e = e * 12 / 10;// 
		}
		me.exp += e;
		if (isboss) {
			answer = "YOU WIN!";
			Gameover = true;//���������� ������.
		}
	}
}
void levelup() {
	if (me.exp >= me.lv * 5) {//�����Ǵ� ���.
		me.hp += 5;//�ִ� ü�� 5����
		me.att += 2;
		me.def += 2;
		me.prehp = me.hp;//Ǯ��
		me.exp = 0;//����ġ 0���� �����. (�������� ������ �����ߵ�.)
		me.lv++;//���� ����
	}
}
void items(int& x, int& y) {//������ ��� �� Ȯ��.
	board[x][y] = '.';//�ش� ��ǥ�� ������ ��������.
	auto [t, n] = iinfo[x][y];//t�� ������ n
	if (t == 'W') {//���ݷ±�ü
		me.w = stoi(n);
	}
	else if (t == 'A') {//���±�ü
		me.a = stoi(n);
	}
	else {//��ű�.
		if (me.o < 4 && !me.O[rings[n]]) {//0,1,2,3 �� ���� �׸��� �ߺ� �ȵ� ��
			me.O[rings[n]] = true;//����ƴ�.
			me.o++;
		}
	}
}
void thorn(int& x, int& y) {//���� ��ǥ ���� �۾� ����ߵ�.
	int minus = 5;
	if (me.O[4])minus = 1;//��ű��� ������ ������ 1�� �ž���.
	me.prehp -= minus;//minus��ŭ ����.
	if (me.prehp <= 0) {//�׾����ϴ�.
		me.prehp = 0;//�׾����ϱ� �ϴ� �Ǵ� 0���� ��������.
		answer = "YOU HAVE BEEN KILLED BY SPIKE TRAP..";
		dead = true;
	}
}
bool reincar() {//�׾��� �� ����
	if (me.O[1]) {//RE����
		me.O[1] = false;//���� ����
		me.o--;//���� ���� �ִ� ������ ������ �ٿ�����Ѵ�.
		me.x = me.firstx, me.y = me.firsty;//ù ��ġ
		me.prehp = me.hp;//ü�� ��Ȱ
		return true;
	}
	return false;
}
void solve() {
	int turn = 0;
	board[me.x][me.y] = '.';//�ʱ��� �ڽ��� ��ġ�� .���� ������.
	for (auto& value : cmd) {//Ŀ�ǵ忡 ���� ������ ������.
		auto [dx, dy] = MOVE[value];
		int nx = me.x + dx, ny = me.y + dy;
		if (isBound(nx, ny) || board[nx][ny] == '#') {//�� ������.
			nx = me.x, ny = me.y;
		}
		turn++;
		if (board[nx][ny] == '&') {//�����϶�
			MONSTER(nx, ny, false);//�Ϲ� ����
		}
		else if (board[nx][ny] == 'B') {//������
			items(nx, ny);
		}
		else if (board[nx][ny] == '^') {//����
			thorn(nx, ny);
		}
		else if (board[nx][ny] == 'M') {//���� ����
			MONSTER(nx, ny, true);
		}
		if (dead) {
			if (reincar()) {//��Ȱ
				dead = false;
				continue;
			}
			break;//�׾����� �Ǻ�.
		}
		me.x = nx, me.y = ny;
		levelup();
		if (Gameover)break;//���������� �̹� �¸�����.
	}
	if (!dead) {//�� �� �׾���.
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
	me.prehp = 20;//���� ��
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			if (tmp[j] == '@') {//���ΰ��� ��ǥ ����.
				me.x = i, me.y = j;
				me.firstx = i, me.firsty = j;//���߿� RE������ �ٽ� �¾�� �ʱ� ��ġ���� �¾�� �ϴϱ�.
			}
			else if (tmp[j] == '&' || tmp[j] == 'M')k++;//������ ���� �˾Ƴ���.
			else if (tmp[j] == 'B')l++;//������ ���� �˾Ƴ���
			board[i][j] = tmp[j];
		}
	}
	cin >> cmd;
	for (int i = 0; i < k; i++) {
		int r, c, w, a, h, e;
		string s;
		cin >> r >> c >> s >> w >> a >> h >> e;
		minfo[r - 1][c - 1] = { s,w,a,h,e };//������ �׸��忡 �ִ� ���͵� ������ �ֱ�.
	}
	for (int i = 0; i < l; i++) {
		int r, c;
		char t;
		string n;
		cin >> r >> c >> t >> n;//���� �Է� �ޱ�.
		iinfo[r - 1][c - 1] = { t,n };//�����ϱ�~
	}
	solve();
	return 0;
}