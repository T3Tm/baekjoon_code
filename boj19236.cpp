#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/19236
	19236�� û�ҳ� ���

	1. �� (0,0) �ڸ��� ���鼭 ������� ������ ���´�.
	2. ������� ��ȣ�� ���� ������� �̵��ϱ� �����Ѵ�.
	3. ���� ���⿡ �ִ� ĭ���� 1,2,3ĭ ��� �� �� �ִ�.
	4. �� �̵��� �� �ִ� ĭ�� ������ �������� ��� ������ ����.(�̷��� ��)
*/
using namespace std;
struct loc {
	int num, s;//���ڶ� ��ȣ
};
struct SHARK {
	int x, y, s;//��ǥ�� ����
};
struct LOC {
	int x, y;
};
map<int, LOC>MOVE = { {1,{-1,0}},{2,{-1,-1}},{3,{0,-1}},{4,{1,-1}},
	{5,{1,0}},{6,{1,1}},{7,{0,1}},{8,{-1,1}} };
loc arr[6][6];
SHARK shark;
long long answer;//��� �� ���� ����~
bool isBoundary(int x, int y) {
	return (x >= 0 && x < 4) && (y >= 0 && y < 4);
}
void arrcpy(loc src[6][6], loc dst[6][6]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dst[i][j] = src[i][j];
		}
	}
}
void fishmove(loc tmp[6][6]) {//ó���� 0,0���� ����.
	vector<LOC>save(18, { -1,-1 });//�ش� ��ȣ�� ��ǥ �����س���
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			save[tmp[i][j].num] = { i,j };//��ǥ �����ϱ�.
		}
	}
	for (int i = 1; i <= 16; i++) {//��ε� ���� �ٲٱ� ����.
		auto temp = save[i];
		if (temp.x == -1 && temp.y == -1)continue;
		for (int i = 0; i < 8; i++) {
			auto next = MOVE[tmp[temp.x][temp.y].s];//�ش� ��ǥ�� ���� �˾Ƴ���.
			int nx = temp.x + next.x;
			int ny = temp.y + next.y;
			if (!isBoundary(nx, ny)) {//���� �Ѿ���� �ش��ϴ� ������ ������ �ٲ۴�.
				tmp[temp.x][temp.y].s = (tmp[temp.x][temp.y].s + 1 == 9 ? 1 : tmp[temp.x][temp.y].s + 1);
				continue;
			}
			if (arr[nx][ny].num == 17) {//��� ������ 17
				tmp[temp.x][temp.y].s = (tmp[temp.x][temp.y].s + 1 == 9 ? 1 : tmp[temp.x][temp.y].s + 1);
				continue;
			}
			swap(arr[temp.x][temp.y], arr[nx][ny]);
			save[arr[temp.x][temp.y].num] = { temp.x,temp.y };
			save[arr[nx][ny].num] = { nx,ny };
			break;
		}
	}
}
void solve(loc tmp[6][6], SHARK srk, long long result) {//�ش� ��� ����
	answer = max(answer, result);
	tmp[srk.x][srk.y] = { 17,srk.s };//�ش� ��ǥ ��� ����
	fishmove(arr);
	loc cache[6][6];//�ش� depth�� �����ϱ�.
	arrcpy(tmp, cache);//�迭 �ϴ� �����ϱ�.
	auto [dx, dy] = MOVE[srk.s];//dx,dy, 
	for (int i = 1; i <= 4; i++) {//��� �׸� ��..
		SHARK new_srk = { srk.x + (dx * i) ,srk.y + (dy * i) };
		new_srk.s = tmp[new_srk.x][new_srk.y].s;
		int num = tmp[new_srk.x][new_srk.y].num;
		if (isBoundary(new_srk.x, new_srk.y) && num > 0) {//���� �ȵ�
			tmp[srk.x][srk.y] = { 0,0 };//���� �� ��� ��ǥ�� ����
			solve(tmp, new_srk, result + num);
			arrcpy(cache, tmp);//�ٽ� ����
		}
	}
}
int main() {
	fast;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j].num >> arr[i][j].s;
		}
	}
	answer = arr[0][0].num;
	shark = { 0,0,arr[0][0].s };
	solve(arr, shark, answer);
	cout << answer;
	return 0;
}