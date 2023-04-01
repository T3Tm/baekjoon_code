#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/23290
	23290�� ������ ���� ����

	�� �̻��� ����Ⱑ ���� ĭ�� ���� ���� ������
	������ ���� ����Ⱑ ���� ĭ�� ���� ���� �ִ�. << ����

	���� �����
	1. ��� ����Ⱑ �� ĭ �̵��Ѵ�. ���� �ش� ĭ���� �̵� ���ϸ� 45�� �ݽð�� ��� ���� �ٲ��ֱ� (���� ����� �ȵ�.)
	2. �� �����ؼ� 3ĭ �̵��Ѵ�. //���� �����¿�� ������ ĭ�� �̵��Ѵ�.
	2-1 ����⸦ ������ ����Ⱑ �������, ����� ������ �����.
	2-2 ������ �̵� ��� �߿��� ���ܵǴ� ������� ���� ���� ���� ������� �̵��ϸ� �ȴ�.
	2-3  �׷��� ����� ���������� ��� ���� ������ ���� �ռ��� ����� �̿��Ѵ�. ���� ���� ���� ������ �ϴ� ��Ʈ�� �ִ�.
	3. 2�� �� �������� ���� ������� ������ ���ڿ��� �������. << ���� ���� 2�� ������ ���� �ž��ϴϱ� ����� ������ �� ��°���� �ƴ��� Ȯ��.
	4. ����� ���� �Ϸ� 1������ ��ġ�� ������ �״�� ���� �ȴ�.
	111,112
	��, ��, ��, ��, ��, ��, ��, ��
	1  2   3  4  5   6  7  8
*/
using namespace std;
struct loc {
	int x, y;
};
struct FISH {
	int x, y, d;
};
struct comb {
	string com;
	int cnt;//����� �������� �� Ȯ��.
};
struct newArray {
	vector<int>idxvalues;//����� ����,�� �� �ε������� �ִ��� Ȯ��.
	int smell;//����� ���� �˾ƺ���.
};
map<int, loc>convert = { {1,{0,-1}},{2,{-1,-1}},{3,{-1,0}},{4,{-1,1}},{5,{0,1}},
	{6,{1,1}},{7,{1,0}},{8,{1,-1}} };//���ڸ� �������� �ٲٱ�
map<int, int>sharkconvert = { {1,3},{2,1},{3,7},{4,5} };
newArray arr[6][6];//����� ���� ������.
int m, s;//m���� ����Ⱑ ����.
vector<FISH>fishes;//������
vector<FISH>temp;//���� ����� ������ �׾Ƴ���.
loc shark;
int getfish() {
	return fishes.size();
}
bool isboundary(int x, int y) {
	return (x >= 0 && x < 4) && (y >= 0 && y < 4);
}
void fishmove() {//����� �����̱�.
	int idx = 0;//�ش� �ε����� ���� �� �ֵ���
	for (auto& [x, y, d] : fishes) {
		temp.push_back({ x,y,d });//�̸� �� �־��ֱ�.
		int sit = 0;//�ڸ� ���� �Ǵ��� Ȯ��.
		while (sit != 8) {
			auto next = convert[d];
			int nx = x + next.x;
			int ny = y + next.y;
			sit++;
			if (!isboundary(nx, ny)) {
				d = ((d - 1) == 0 ? 8 : d - 1);//�ݽð�� ������ �ɶ�����.
				continue;
			}
			else if (shark.x == nx && shark.y == ny) {//��� �ִ� �ڸ�����.
				d = ((d - 1) == 0 ? 8 : d - 1);
				continue;
			}
			else if (arr[nx][ny].smell) {//����� ���� ������ Ȯ��
				d = ((d - 1) == 0 ? 8 : d - 1);
				continue;
			}
			//������ �ڸ��� ���� ��.
			x = nx;
			y = ny;
			break;
		}
		arr[x][y].idxvalues.push_back(idx++);//������ ��ȣ �˾ƾߵǱ� ����.
	}
}
void sharkmove(int depth) {//��� �����̱�
	comb maxcomb = { "",-1 };
	comb tmp = { "",0 };
	int visited[5][5] = { 0 };
	for (auto first : { 1,2,3,4 }) {//�����Ͽ� 1->3 , 2->1 3->7 4-> 5
		auto firstmove = convert[sharkconvert[first]];
		if (!isboundary(firstmove.x + shark.x, firstmove.y + shark.y))continue;
		bool firstplus = true;
		tmp.cnt += (int)arr[firstmove.x + shark.x][firstmove.y + shark.y].idxvalues.size();
		visited[firstmove.x + shark.x][firstmove.y + shark.y]++;
		for (auto second : { 1,2,3,4 }) {
			bool secondary = false;
			auto secondmove = convert[sharkconvert[second]];
			if (!isboundary(firstmove.x + shark.x + secondmove.x, firstmove.y + shark.y + secondmove.y))continue;
			if (!visited[firstmove.x + shark.x + secondmove.x][firstmove.y + shark.y + secondmove.y]) {
				//�̹� �湮������ �� ����.
				secondary = true;
				tmp.cnt += (int)arr[firstmove.x + shark.x + secondmove.x][firstmove.y + shark.y + secondmove.y].idxvalues.size();
				visited[firstmove.x + shark.x + secondmove.x][firstmove.y + shark.y + secondmove.y]++;
			}
			for (auto third : { 1,2,3,4 }) {//�� �� �� ��
				//�����̴� ���� ����� 1 -> 3, 2 -> 1,3 -> 7, 4 -> 5
				bool thirdary = false;
				auto thirdmove = convert[sharkconvert[third]];
				if (!isboundary(firstmove.x + shark.x + secondmove.x + thirdmove.x, firstmove.y + shark.y + secondmove.y + thirdmove.y))continue;
				//������ ������ �� �ִ� ��η� ����.
				if (!visited[firstmove.x + shark.x + secondmove.x + thirdmove.x][firstmove.y + shark.y + secondmove.y + thirdmove.y]) {
					//�̹� �湮������ �� ����.
					thirdary = true;
					tmp.cnt += (int)arr[firstmove.x + shark.x + secondmove.x + thirdmove.x][firstmove.y + shark.y + secondmove.y + thirdmove.y].idxvalues.size();
					visited[firstmove.x + shark.x + secondmove.x + thirdmove.x][firstmove.y + shark.y + secondmove.y + thirdmove.y]++;
				}
				string strtmp;
				strtmp.push_back(first + '0');
				strtmp.push_back(second + '0');
				strtmp.push_back(third + '0');
				if (tmp.cnt > maxcomb.cnt) {//���� �԰� �� ���� �ٲ���
					maxcomb.cnt = tmp.cnt;
					maxcomb.com = strtmp;
				}
				else if (tmp.cnt == maxcomb.cnt) {//������
					if (strtmp < maxcomb.com) {
						maxcomb.com = strtmp;
					}
				}
				if (thirdary) {
					tmp.cnt -= (int)arr[firstmove.x + shark.x + secondmove.x + thirdmove.x][firstmove.y + shark.y + secondmove.y + thirdmove.y].idxvalues.size();
					visited[firstmove.x + shark.x + secondmove.x + thirdmove.x][firstmove.y + shark.y + secondmove.y + thirdmove.y]--;
				}
			}
			if (secondary) {
				tmp.cnt -= (int)arr[firstmove.x + shark.x + secondmove.x][firstmove.y + shark.y + secondmove.y].idxvalues.size();
				visited[firstmove.x + shark.x + secondmove.x][firstmove.y + shark.y + secondmove.y]--;
			}

		}
		tmp.cnt -= (int)arr[firstmove.x + shark.x][firstmove.y + shark.y].idxvalues.size();
		visited[firstmove.x + shark.x][firstmove.y + shark.y]--;
	}
	set<int>minusidx;
	vector<FISH>fishtmp;//����� ��ǥ �Ű� ����.
	for (auto& value : maxcomb.com) {//�����̸鼭 �����ֱ�.
		auto nextloc = convert[sharkconvert[value - '0']];
		auto& sharkloc = shark;
		sharkloc.x += nextloc.x;
		sharkloc.y += nextloc.y;
		for (auto& vales : arr[sharkloc.x][sharkloc.y].idxvalues) {//�ش��ϴ� ���� �ִ� ������.
			minusidx.insert(vales);
			arr[sharkloc.x][sharkloc.y].smell = depth;//s�� ��
			arr[sharkloc.x][sharkloc.y].idxvalues.clear();//�� ����
		}
	}
	for (int i = 0; i < (int)fishes.size(); i++) {
		if (minusidx.find(i) == minusidx.end()) {//������ ����� �ƴ� ��
			fishtmp.push_back(fishes[i]);
		}
	}
	fishes = fishtmp;//�� �����.
}
void deletefish(int depth) {//����� ���� ���ֱ�
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j].smell - depth >= 2) {//������ ������� �ؿ�.
				arr[i][j].smell = 0;//���� ����� 
			}
		}
	}
}
void copyfish() {
	while (!temp.empty()) {
		auto& value = temp.back(); temp.pop_back();
		fishes.push_back(value);//�� �ϳ��� �� �־��ֱ�.
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j].idxvalues.clear();//�ε��� �� ���ְ� �ٽ� ����.
		}
	}
}
void solve() {
	int cnt = 0;
	while (s--) {//���� Ƚ����ŭ ����
		fishmove();//��� ����� �����̱�.
		sharkmove(s + 1);//��� �̵��ϱ�.
		if (cnt >= 2) {
			deletefish(s + 1);//���� ���� 2�� �� ���� ������ ���� �����ϱ�.
		}
		copyfish();
		cnt++;
	}
	cout << getfish();
}
int main() {
	fast;
	cin >> m >> s;
	while (m--) {
		int x, y, d;//��ǥ�� �������
		cin >> x >> y >> d;
		fishes.push_back({ x - 1,y - 1,d });
	}
	cin >> shark.x >> shark.y;
	shark.x--;
	shark.y--;
	solve();
	return 0;
}