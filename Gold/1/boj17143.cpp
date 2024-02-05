#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17143
	17143�� ���ÿ�
*/
using namespace std;
struct SHARK {
	int r, c, s, d, z;//��ǥ, �ӵ�,����,ũ�� 
};
int main() {
	fast;
	int r, c, m;//�� �� ����� ��
	int arr[102][102] = { 0 };
	cin >> r >> c >> m;
	vector<SHARK>shark(m);//���� �Է¹ޱ�
	auto isBoundary = [&](int x, int y) {
		return x < 0 || x >= r || y < 0 || y >= c;
	};
	int convert[] = { 1,0,3,2 };
	auto locconvert = [&](int& x, int& y, int& d) {//�ش� ��ǥ�� �ǵ鿩�ֱ�.
		if (x < 0) {
			int value = (-x) % (r - 1);
			value = value ? value : r - 1;
			if (((-x - 1) / (r - 1)) % 2) {//Ȧ�� ���� �� �ٲ�.
				x = (r - 1) - value;
			}
			else {//���� �ٲ������.
				d = convert[d];
				x = value;//1,2,3,n-1���� ���;���.
			}
		}
		else if (x >= r) {
			int value = (x) % (r - 1);
			value = value ? value : r - 1;
			if (((x - 1) / (r - 1)) % 2) {//���� �ٲ����.
				d = convert[d];
				x = (r - 1) - value;

			}
			else {
				x = value;
			}
		}
		if (y < 0) {
			int value = (-y) % (c - 1);
			value = value ? value : c - 1;
			if (((-y - 1) / (c - 1)) % 2) {//Ȧ�� ���� �� �ٲ�.
				y = (c - 1) - value;
			}
			else {//���� �ٲ������.
				d = convert[d];
				y = value;//1,2,3,n-1���� ���;���.
			}
		}
		else if (y >= c) {
			int value = (y) % (c - 1);
			value = value ? value : c - 1;
			if (((y - 1) / (c - 1)) % 2) {//���� �ٲ����.
				d = convert[d];
				y = (c - 1) - value;
			}
			else {
				y = value;
			}
		}
	};

	for (int i = 1; i <= m; i++) {
		cin >> shark[i - 1].r >> shark[i - 1].c >> shark[i - 1].s >> shark[i - 1].d >> shark[i - 1].z;
		arr[--shark[i - 1].r][--shark[i - 1].c] = i;//i��° �� ���ִ�.
		shark[i - 1].d--;
	}
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,1,-1 };
	/*step 3*/
	auto arrcopy = [&](int newarr[102][102]) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				arr[i][j] = newarr[i][j];
			}
		}
	};
	/*step 2 */
	auto sharkmove = [&]() {
		int newarr[102][102] = { 0 };
		for (int i = 1; i <= m; i++) {
			auto [r, c, s, d, z] = shark[i - 1];//��ǥ ,�ӵ�,����,ũ��
			if (r == -1 && c == -1)continue;//���� ���� ó������ ����.
			r += (dx[d] * s);
			c += (dy[d] * s);
			if (isBoundary(r, c)) {//�Ѿ���� ������ �ݴ�� �����
				locconvert(r, c, d);
			}
			if (newarr[r][c] && shark[newarr[r][c] - 1].z > shark[i - 1].z) {
				//�������� ���̾�� �ϰ�. ���ڰ� �־�� �ϸ� ũ�Ⱑ �� ������ ����.
				shark[i - 1] = { -1,-1,s,d,z };
				continue;
			}
			else if (newarr[r][c] && shark[newarr[r][c] - 1].z < shark[i - 1].z) {//������ �� ũ�ϱ� �� �ڸ��� �ִ� �ִ� �׿�����.
				shark[newarr[r][c] - 1] = { -1,-1,s,d,z };//���� ������ �ߴ� �ڸ��� �� ���̱�.
			}
			shark[i - 1] = { r,c,s,d,z };
			newarr[r][c] = i;//���ο� ������ �Ҵ����ش�.
		}
		arrcopy(newarr);//���ο� �迭 �ٽ� ����
	};
	/*step 1 */

	int column = -1;
	long long answer = 0;
	auto fishman = [&]() {
		column++;
		for (int row = 0; row < r; row++) {
			if (arr[row][column]) {//��� ������.
				shark[arr[row][column] - 1].r = -1, shark[arr[row][column] - 1].c = -1;
				//��� ���� ��Ű��.
				answer += shark[arr[row][column] - 1].z;
				arr[row][column] = 0;//��� ����
				break;
			}
		}
		sharkmove();
	};
	for (; column + 1 != c; fishman());

	cout << answer;
	return 0;
}