#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/21611
	21611�� ������ ���� ���ڵ�
	���� 1~3������ �ִ�.

	1. ���ڵ� ���� d�������� s�Ÿ����� �����Ѵ�. (���� �ı��ȴ�.)
	2. �� ĭ���� �Ű��ֱ�. (�� ĭ���� �� �� �����ֱ�.)
	3. �����Ѵ�.(�������� 4�� �̻� �Ȱ��� ����)
	4. �� ĭ���� �Ű��ֱ�. (2�� ����)
	5. �ٽ� 3�� ���� �Ѵ�.
	6.������ ���� ���� �� ������ ���Ѵ�.
	(���ϴ� ���� ���ο� �迭�� ����� ������ �Ѵ�.)
	(A,B) <= ����,������ ��ȣ (������ �ִ�׷� 3������ �� �� ����.) 4�̸� �Ұ��� �ֳĸ� �����ؾߵǴϱ�
	7. M���� ���� ������.
	���� ���� ���� �����ؾߵ�.

	����, ���ϱ�
*/
using namespace std;
struct dynamite {
	int one, two, three;
};
struct loc {//��ġ
	int x, y;
};
struct pointer {
	int x, y, d, plus, pluscnt;//x,y��ǥ, d ���� plus��ŭ �������ߵȴ�.
};
int n, m;
dynamite save;//���� ����.
int arr[52][52];
map<int, loc>MOVE = { {1,{-1,0}},{2,{1,0}},{3,{0,-1}},{4,{0,1}} };
map<int, int>Nextconvert = { {3,2},{2,4},{4,1},{1,3} };//���� �ٲ� ��
loc shark;
void destruction(int d, int s) {//���� �ı�
	auto value = MOVE[d];
	int xplus = value.x, yplus = value.y;
	while (s--) {//
		arr[shark.x + xplus][shark.y + yplus] = 0;//0���� �ٲٱ�
		xplus += value.x; yplus += value.y;
	}
}
void beadPulling() {
	pointer empty = { n / 2,n / 2 - 1,2,1,1 };//��� ���ʺ��� �����ؼ� �Ʒ��� ��������.
	//ù ��° 0�� �ƴ� �͵鸸 �ؼ� �迭�� �� �ִ´�. 2��° �� ������ �ϳ��� �� ���´�.
	int tmparr[5000] = { 0 }, tmpidx = 0;//�迭�� �� �� �ֱ�.
	bool exitpoint = false;
	while (!exitpoint) {//tmparr�� �� �� �׾��ֱ�.
		auto next_xy = MOVE[empty.d];//�ش� ��ǥ�� ������ Ȯ�� �� �����ش�.
		for (int i = 0; i < empty.plus; i++) {//plus��ŭ�� �̵��� ����
			if (empty.x == 0 && empty.y == -1) {//�����ߵ�.
				exitpoint = true;
				break;
			}
			if (arr[empty.x][empty.y]) {//���� ������� ������ �ش� �� tmparr�� �־��ֱ�
				tmparr[tmpidx++] = arr[empty.x][empty.y];
			}
			empty.x += next_xy.x;
			empty.y += next_xy.y;
		}
		empty.pluscnt++;
		if (empty.pluscnt == 2) {
			empty.pluscnt = 0;
			empty.plus++;//�ϳ� ����
		}
		empty.d = Nextconvert[empty.d];
	}
	empty = { n / 2,n / 2 - 1,2,1,1 };
	exitpoint = false;
	tmpidx = 0;
	while (!exitpoint) {
		auto next_xy = MOVE[empty.d];//�ش� ��ǥ�� ������ Ȯ�� �� �����ش�.
		for (int i = 0; i < empty.plus; i++) {//plus��ŭ�� �̵��� ����
			if (empty.x == 0 && empty.y == -1) {//�����ߵ�.
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
			empty.plus++;//�ϳ� ����
		}
		empty.d = Nextconvert[empty.d];
	}
}
bool bangbead() {//�����ؼ� ���� ���� �ִ��� Ȯ��.
	int number = -1;
	vector<loc>tmploc;//������ �Ǵ� ������ ��ǥ.
	pointer empty = { n / 2,n / 2 - 1,2,1,1 };
	bool exitpoint = false, returnvalue = false;
	while (!exitpoint) {
		auto next_xy = MOVE[empty.d];//�ش� ��ǥ�� ������ Ȯ�� �� �����ش�.
		for (int i = 0; i < empty.plus; i++) {//plus��ŭ�� �̵��� ����
			if (empty.x == 0 && empty.y == -1) {//�����ߵ�.
				exitpoint = true;
				break;
			}
			if (arr[empty.x][empty.y] != number) {//�׾ƿ� ���� ���� �ٸ��ٸ�?
				if ((int)tmploc.size() >= 4) {//�����ؼ� ���ڰ� ������ �� ���Գ�.
					returnvalue = true;//�� ���̶� ���� �� ����.
					if (number == 1) {//������ ���� �����ֱ�.
						save.one += tmploc.size();
					}
					else if (number == 2) {
						save.two += tmploc.size();
					}
					else if (number == 3) {
						save.three += tmploc.size();
					}
					while (!tmploc.empty()) {//��Ʈ���ֱ�.
						auto spot = tmploc.back(); tmploc.pop_back();
						arr[spot.x][spot.y] = 0;//���� ��
					}
				}
				number = arr[empty.x][empty.y];//�ٸ� ���ڴٽ� �׾��ֱ�.
				tmploc.clear();
				tmploc.push_back({ empty.x,empty.y });
			}
			else {//���ڰ� ���� ��
				tmploc.push_back({ empty.x,empty.y });//��ǥ�� �׾��ָ� ��.
			}
			empty.x += next_xy.x;
			empty.y += next_xy.y;
		}
		empty.pluscnt++;
		if (empty.pluscnt == 2) {
			empty.pluscnt = 0;
			empty.plus++;//�ϳ� ����
		}
		empty.d = Nextconvert[empty.d];
	}
	return returnvalue;//���� �� �ִ��� �˷��ֱ�.
}
void transbead() {//���� ��ȭ�ϱ�.
	int number = 0, cnt = 0;
	pointer empty = { n / 2,n / 2 - 1,2,1,1 };
	bool exitpoint = false;
	int tmparr[2404] = { 0 }, tmpidx = 0;//�迭�� �� �� �ֱ�.
	while (!exitpoint) {
		auto next_xy = MOVE[empty.d];//�ش� ��ǥ�� ������ Ȯ�� �� �����ش�.
		for (int i = 0; i < empty.plus; i++) {//plus��ŭ�� �̵��� ����
			if (empty.x == 0 && empty.y == -1 || !arr[empty.x][empty.y]) {//�迭�� �ʰ��ϰų�, 0�� ���̸� �׳� ������.
				exitpoint = true;
				break;
			}
			if (arr[empty.x][empty.y] != number) {//�׾ƿ� ���� ���� �ٸ��ٸ�?
				if (tmpidx >= n * n) {//0���� �ֱ� ������.
					exitpoint = true;
					break;
				}
				if (number != 0) {
					tmparr[tmpidx] = cnt;
					tmparr[tmpidx + 1] = number;
					tmpidx += 2;//idx�� 2�� Ŀ���� �ȴ�.
				}
				number = arr[empty.x][empty.y];//�ٸ� ���ڴٽ� �׾��ֱ�.
				cnt = 1;
			}
			else {//���ڰ� ���� ��
				cnt++;
			}
			empty.x += next_xy.x;
			empty.y += next_xy.y;
		}
		empty.pluscnt++;
		if (empty.pluscnt == 2) {
			empty.pluscnt = 0;
			empty.plus++;//�ϳ� ����
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
		auto next_xy = MOVE[empty.d];//�ش� ��ǥ�� ������ Ȯ�� �� �����ش�.
		for (int i = 0; i < empty.plus; i++) {//plus��ŭ�� �̵��� ����
			if (empty.x == 0 && empty.y == -1) {//�迭�� �ʰ��ϰų�, 0�� ���̸� �׳� ������.
				exitpoint = true;
				break;
			}
			arr[empty.x][empty.y] = tmparr[tmpidx++];//tmp�� �ű� �� arr�� �� �־��ֱ�.
			empty.x += next_xy.x;
			empty.y += next_xy.y;
		}
		empty.pluscnt++;
		if (empty.pluscnt == 2) {
			empty.pluscnt = 0;
			empty.plus++;//�ϳ� ����
		}
		empty.d = Nextconvert[empty.d];
	}
}
void solve() {
	while (m--) {
		int d, s;//d�������� s�Ÿ���ŭ �ı��ϸ鼭 ����.
		cin >> d >> s;
		destruction(d, s);//���� �ı��Ѵ�~
		beadPulling();//���� �� ������.
		bool next_bang = bangbead();//���� ������.
		while (next_bang) {//���� ���� ���� ������
			beadPulling();//����� �۾� �����ϱ�.
			next_bang = bangbead();
		}
		transbead();//���� ���� ��ȭ��Ű��.
	}
}
int main() {
	fast;
	cin >> n >> m;//�� ��, �������� ��
	shark = { n / 2,n / 2 };//�ʱ� ��� ��ġ.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	cout << 1 * save.one + 2 * save.two + 3 * save.three;
	return 0;
}