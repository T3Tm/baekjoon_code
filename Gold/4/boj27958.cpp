#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/27958
	27958�� ��� ����
*/
using namespace std;
struct newArr {
	int num, preNum;//���� ����, �ʱ� ����.
};
int n, k;
newArr arr[10][10];
int bullet[6];
int answer;
void arrcpy(newArr src[][10], newArr dst[][10]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dst[i][j] = src[i][j];
		}
	}
}
void spread(newArr tmp[][10], int x, int y) {
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
		if (tmp[nx][ny].num == 0) {//�ش��ϴ� ���� 0�̶�� ���� ������ ���������ų� �ʿ������ ����.
			tmp[nx][ny].num = tmp[x][y].preNum / 4;
			tmp[nx][ny].preNum = tmp[x][y].preNum / 4;
		}
	}
}
void tang(int depth, newArr tmp[][10], int result) {
	if (depth == k) {
		answer = max(answer, result);
		return;
	}
	newArr cache[10][10];
	arrcpy(tmp, cache);
	for (int i = 0; i < n; i++) {//�� ����
		int idx = -1;
		for (int j = 0; j < n; j++) {
			if (tmp[i][j].num) {//������ �ִ��� Ȯ��.
				idx = j;
				break;
			}
		}
		if (idx != -1) {
			if (bullet[depth] >= tmp[i][idx].num || tmp[i][idx].num >= 10) {//���ʽ� ��
				int value = tmp[i][idx].preNum;//�ʱ� ü�¸�ŭ ���ؾߵ�.
				if (value >= 4 && value < 10)spread(tmp, i, idx);
				tmp[i][idx].num = 0;
				tang(depth + 1, tmp, result + value);
				arrcpy(cache, tmp);
			}
			else {//�� �ν�.
				tmp[i][idx].num -= bullet[depth];
				tang(depth + 1, tmp, result);
				tmp[i][idx].num += bullet[depth];
			}
		}
	}
}
void solve() {
	tang(0, arr, 0);
	cout << answer;
}
int main() {
	fast;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j].num;
			arr[i][j].preNum = arr[i][j].num;
		}
	}
	for (int i = 0; i < k; i++)cin >> bullet[i];
	solve();
	return 0;
}