#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/20057
   20057�� ������ ���� ����̵�
   499 * 499 = 249001
   y * 5 / 100

	1. �̵��Ѵ�.
	2. �ٶ󺸴� ���⿡ ���� �𷡸� �𳯸���.
	2-1 �𳯸� �� ������ �Ѿ���� Ȯ��!
	3. �𳯸��� ���� ����  ���� ĭ�� �ѷ��ش�.


	1 : ��
	2 : ��
	3 : ��
	4 : ��
	1%,2%,5%,7%,10% ����ؾ� �Ѵ�.
*/
using namespace std;
int n;
int arr[502][502];
long long sand = 0;//�������� �𷡵� ������.
map<int, pair<int, int>>MOVE = { {1,{0,1}},{2,{0,-1}},{4,{-1,0}},{3,{1,0}} };//
bool isBoundary(int x, int y) {//���� üũ
	return (x < n && x >= 0) && (y < n && y >= 0);
}
void spreadSand(int x, int y, int see, long long& sand) {
	int percent1 = arr[x][y] / 100;
	int percent2 = arr[x][y] / 50;
	int percent5 = arr[x][y] / 20;
	int percent7 = (arr[x][y] * 7) / 100;
	int percent10 = arr[x][y] / 10;
	if (see == 1) {//��
		if (isBoundary(x - 1, y - 1)) {//���� �ȿ� ����
			arr[x - 1][y - 1] += percent1;
		}
		else {//���.
			sand += percent1;
		}
		if (isBoundary(x + 1, y - 1)) {
			arr[x + 1][y - 1] += percent1;
		}
		else {
			sand += percent1;
		}

		if (isBoundary(x - 1, y)) {
			arr[x - 1][y] += percent7;
		}
		else {
			sand += percent7;
		}
		if (isBoundary(x + 1, y)) {
			arr[x + 1][y] += percent7;
		}
		else {
			sand += percent7;
		}

		if (isBoundary(x - 2, y)) {
			arr[x - 2][y] += percent2;
		}
		else {
			sand += percent2;
		}
		if (isBoundary(x + 2, y)) {
			arr[x + 2][y] += percent2;
		}
		else {
			sand += percent2;
		}

		if (isBoundary(x - 1, y + 1)) {
			arr[x - 1][y + 1] += percent10;
		}
		else {
			sand += percent10;
		}
		if (isBoundary(x + 1, y + 1)) {
			arr[x + 1][y + 1] += percent10;
		}
		else {
			sand += percent10;
		}

		if (isBoundary(x, y + 2)) {
			arr[x][y + 2] += percent5;
		}
		else {
			sand += percent5;
		}

		if (isBoundary(x, y + 1)) {
			arr[x][y + 1] += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
		else {
			sand += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
	}
	else if (see == 2) {//��
		if (isBoundary(x - 1, y + 1)) {//���� �ȿ� ����
			arr[x - 1][y + 1] += percent1;
		}
		else {//���.
			sand += percent1;
		}
		if (isBoundary(x + 1, y + 1)) {
			arr[x + 1][y + 1] += percent1;
		}
		else {
			sand += percent1;
		}

		if (isBoundary(x - 1, y)) {
			arr[x - 1][y] += percent7;
		}
		else {
			sand += percent7;
		}
		if (isBoundary(x + 1, y)) {
			arr[x + 1][y] += percent7;
		}
		else {
			sand += percent7;
		}

		if (isBoundary(x - 2, y)) {
			arr[x - 2][y] += percent2;
		}
		else {
			sand += percent2;
		}
		if (isBoundary(x + 2, y)) {
			arr[x + 2][y] += percent2;
		}
		else {
			sand += percent2;
		}

		if (isBoundary(x - 1, y - 1)) {
			arr[x - 1][y - 1] += percent10;
		}
		else {
			sand += percent10;
		}
		if (isBoundary(x + 1, y - 1)) {
			arr[x + 1][y - 1] += percent10;
		}
		else {
			sand += percent10;
		}

		if (isBoundary(x, y - 2)) {
			arr[x][y - 2] += percent5;
		}
		else {
			sand += percent5;
		}

		if (isBoundary(x, y - 1)) {
			arr[x][y - 1] += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
		else {
			sand += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
	}
	else if (see == 3) {//��
		if (isBoundary(x - 1, y - 1)) {//���� �ȿ� ����
			arr[x - 1][y - 1] += percent1;
		}
		else {//���.
			sand += percent1;
		}
		if (isBoundary(x - 1, y + 1)) {
			arr[x - 1][y + 1] += percent1;
		}
		else {
			sand += percent1;
		}

		if (isBoundary(x, y - 1)) {
			arr[x][y - 1] += percent7;
		}
		else {
			sand += percent7;
		}
		if (isBoundary(x, y + 1)) {
			arr[x][y + 1] += percent7;
		}
		else {
			sand += percent7;
		}

		if (isBoundary(x, y - 2)) {
			arr[x][y - 2] += percent2;
		}
		else {
			sand += percent2;
		}
		if (isBoundary(x, y + 2)) {
			arr[x][y + 2] += percent2;
		}
		else {
			sand += percent2;
		}

		if (isBoundary(x + 1, y - 1)) {
			arr[x + 1][y - 1] += percent10;
		}
		else {
			sand += percent10;
		}
		if (isBoundary(x + 1, y + 1)) {
			arr[x + 1][y + 1] += percent10;
		}
		else {
			sand += percent10;
		}

		if (isBoundary(x + 2, y)) {
			arr[x + 2][y] += percent5;
		}
		else {
			sand += percent5;
		}

		if (isBoundary(x + 1, y)) {
			arr[x + 1][y] += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
		else {
			sand += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
	}
	else {//��
		if (isBoundary(x + 1, y - 1)) {//���� �ȿ� ����
			arr[x + 1][y - 1] += percent1;
		}
		else {//���.
			sand += percent1;
		}
		if (isBoundary(x + 1, y + 1)) {
			arr[x + 1][y + 1] += percent1;
		}
		else {
			sand += percent1;
		}

		if (isBoundary(x, y - 1)) {
			arr[x][y - 1] += percent7;
		}
		else {
			sand += percent7;
		}
		if (isBoundary(x, y + 1)) {
			arr[x][y + 1] += percent7;
		}
		else {
			sand += percent7;
		}

		if (isBoundary(x, y - 2)) {
			arr[x][y - 2] += percent2;
		}
		else {
			sand += percent2;
		}
		if (isBoundary(x, y + 2)) {
			arr[x][y + 2] += percent2;
		}
		else {
			sand += percent2;
		}

		if (isBoundary(x - 1, y + 1)) {
			arr[x - 1][y + 1] += percent10;
		}
		else {
			sand += percent10;
		}
		if (isBoundary(x - 1, y - 1)) {
			arr[x - 1][y - 1] += percent10;
		}
		else {
			sand += percent10;
		}

		if (isBoundary(x - 2, y)) {
			arr[x - 2][y] += percent5;
		}
		else {
			sand += percent5;
		}

		if (isBoundary(x - 1, y)) {
			arr[x - 1][y] += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
		else {
			sand += (arr[x][y] - 2 * (percent1 + percent10 + percent2 + percent7) - percent5);
		}
	}
	arr[x][y] = 0;//����̵� �������� 0���� ��.
}
void ChangeSee(int& see) {
	if (see == 1) {
		see = 4;
	}
	else if (see == 2) {
		see = 3;
	}
	else if (see == 3) {
		see = 1;
	}
	else {
		see = 2;
	}
}
void solve() {
	int cnt = 0, move = 1;
	int see = 2;//ó�� ���� �� ����
	int x = (n - 1) / 2;
	int y = x; //�ʱ� ���� ��ǥ��
	while (1) {
		for (int i = 0; i < move; i++) {//move��ŭ �ٶ󺸴� ���� ����������.
			auto next = MOVE[see];
			//��ǥ �����̱�.
			x += next.first;
			y += next.second;
			//�� �𳯸���.
			spreadSand(x, y, see, sand);
			if (x == 0 && y == 0) {//961 - 908 53���̳�. 
				cout << sand;
				exit(0);
			}
		}
		cnt++;
		ChangeSee(see);//���� �ٲٱ�
		if (cnt == 2) {
			cnt = 0;
			move++;
		}
	}
}
int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	return 0;
}

