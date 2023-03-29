#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/21608
	21608�� ��� �ʵ��б�


	1. ����ִ� ĭ �� �����ϴ� �л��� ������ ĭ�� ���� ���� ĭ���� �ڸ��� ���Ѵ�.
	-> �� �ڸ��� �����ϴ� �ְ� �� �� �������ִ��� Ȯ���ϸ鼭 �ִ� ĭ Ȯ��.
	2. 1�� ���� ����� ������ ĭ �߿��� ����ִ� ĭ�� ���� ���� ĭ���� �ڸ��� ���Ѵ�.
	-> �ش��ϴ� �ڸ����� ������ ĭ�� ���� ���� ĭ.
	3. 2�� ���ٸ�, ���� ��ȣ�� ���� ���� ��
	4. 3�� ���ٸ� ���� ��ȣ�� ���� ���� ��.

	1.�迭�� Ȯ���ؼ� ����ִ� �ڸ����ٰ� ������ ĭ�� ����, �ش��ϴ� �����ϴ� ��ȣ�� ���� �ֵ��� ���� ����
	2. ���� ū ���� ���� ���µ�, �� ���� �迭 ���� ���� ū �ε��� ���� ����.
	3. 2�� ���� ���� ���� �� ���� ���� ���� �� ���� ����.
	4. 3�� ������ ���� ��ȣ�� ���� ���� �� ���� ����
	5. �ڸ� ���� �� �Ϳ� nuber�� ���� �־��ش�.

	6. ��� ��ġ�� �����ٸ� ��� �¼����� ������ ���� Ȯ���ϸ鼭 ���� �����Ѵ�.
	7. ����Ѵ�.
*/
using namespace std;
struct loc {
	int adjNumber, lovenumber;//������ ����ִ� ĭ,�����ϴ� �� ������, �� ���ɾҴ�?
};
int n;
int row;
int arr[22][22];//���� ������ Ȯ���ϱ�.
vector<vector<bool>>Wholove;//�ش��ϴ� �ε����� ���� �����ϴ��� �����س��� ��.
long long answer;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
inline int Intpow(int n) {
	return n * n;
}
inline long long mypow(long long n) {
	long long temp = 1;
	for (int i = 0; i < n - 1; i++)temp *= 10;
	return temp;
}
void wheresit(int num) {
	int minrow = 21, mincolumn = 21;
	loc minvalue = { 0 };
	//1,2,3
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!arr[i][j]) {//������� ��
				long long lovecnt = 0, emptycnt = 0;//������ �ֵ� �߿� �����ϴ� �� �˾Ƴ���
				for (int z = 0; z < 4; z++) {
					int nx = i + dx[z];
					int ny = j + dy[z];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
					if (Wholove[num][arr[nx][ny]]) {//�ش��ϴ� ĭ ������ ĭ�� �����ϴ� �л� ��.
						lovecnt++;
					}
					if (arr[nx][ny] == 0)emptycnt++;
				}
				if (lovecnt > minvalue.lovenumber) {
					minvalue.lovenumber = lovecnt;
					minvalue.adjNumber = emptycnt;
					minrow = i;
					mincolumn = j;
				}
				else if (lovecnt == minvalue.lovenumber) {
					if (minvalue.adjNumber < emptycnt) {
						minvalue.lovenumber = lovecnt;
						minvalue.adjNumber = emptycnt;
						minrow = i;
						mincolumn = j;
					}
				}
				if (minrow == 21 && mincolumn == 21) {//�ϴ��� ����ִٴ� ���̴ϱ�.
					minvalue.lovenumber = lovecnt;
					minvalue.adjNumber = emptycnt;
					minrow = i;
					mincolumn = j;
				}
			}
		}
	}
	arr[minrow][mincolumn] = num;//�ڸ� ������.
}
void getHuman() {//�л����� ������ ���ϱ�/
	for (int i = 0; i < n; i++) {//���� ���鼭 �� ���ϱ�.
		for (int j = 0; j < n; j++) {
			long long cnt = 0;
			for (int z = 0; z < 4; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
				if (Wholove[arr[i][j]][arr[nx][ny]]) {//�ش��ϴ� ĭ ������ ĭ�� �����ϴ� �л� ��.
					cnt++;
				}
			}
			if (cnt != 0)answer += mypow(cnt);
		}
	}
}
void solve() {
	for (int i = 0; i < row; i++) {
		int number, t1, t2, t3, t4;
		cin >> number >> t1 >> t2 >> t3 >> t4;
		for (auto& value : { t1,t2,t3,t4 }) {
			Wholove[number][value] = true;//�ش��ϴ� idx�� �����ϴ��� �Ĵ� O(1)�̸� �Ǵܰ���.
		}
		wheresit(number);//��� ������ üũ���ְ� �ɱ����.
	}
	getHuman();
}
int main() {
	fast;
	cin >> n;
	row = Intpow(n);
	Wholove.resize(row + 1, vector<bool>(row + 1, 0));//n^2 ũ��� ����� ����.
	solve();
	cout << answer;//�� ��� ��
	return 0;
}