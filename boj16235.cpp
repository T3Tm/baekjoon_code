#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16235
	16235�� ���� ����ũ

	n*n ���� ���.

	����ũ�� : ���� ������ �����ؼ� Ű��� �Ĵ� ���̴�.
	M���� ������ �����ؼ� ���� �ɴ´�.
	�� ĭ�� ���� ���� ������ �ɾ��� ���� ���� �ִ�.
	1. ���� ó���� ����� ��� ĭ�� 5��ŭ ����ִ�.
	

	1. ������ ������ �ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 �����Ѵ�.
	�ڽ��� ĭ�� �ִ� ��и� ���� �� �ִ�. (���� ���� ������ ������ ���̰� � �������� ����� ����.)
	����, ���� ����� ������ �ڽ��� ���̸�ŭ ����� ���� �� ���� ������ ����� ���� ���ϰ� ��� ����.

	2. �������� ���� ���� ������ ������� ����.
	���� �������� ���̸� 2�� ���� ���� ������ �ִ� ĭ�� ������� �߰��ȴ�. (�Ҽ��� �Ʒ� ����)
	
	3. �������� ������ �����Ѵ�. �����ϴ� ������ ���̰� 5�� ������� �Ѵ�.(%5==0)
	������ 8ĭ�� ���̰� 1�� ������ �����. (������ ����� �� ����.)

	4. �ܿ￡�� ���� ����� �߰��Ѵ�. �� ĭ�� �߰��Ǵ� ����� ���� A[r][c] �Է����� �־���.

	K���� ���� �Ŀ� ���� ���� ����ִ� ������ ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
using namespace std;
struct myTree {
	int x, y, age;
};
struct New {
	int age, idx;//���̶� ���� �ε��� �����س���.
};
struct newArr {
	int num,prenum;//�����.
	deque<int>idxs;//ť�� �����غ��߰ڳ�
};
int n, m, k;
newArr nutrient[12][12];
vector<myTree>trees;
vector<myTree>died;//���� ������ �ֱ�
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
void spring() {
	//�ڽ��� ���̸�ŭ ����� �԰� ���̰� 1�����Ѵ�.
	//�ڱ� ���̸�ŭ ����� �� ������ ��� ����
	// ����� �԰� ������ ���� idx�� ������ ��.
	vector<myTree>tmpTrees;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!nutrient[i][j].idxs.empty()) {//�������� �ɾ��� �ִٴ� ���̴�.
				while(!nutrient[i][j].idxs.empty() && nutrient[i][j].num>0) {
					int id = nutrient[i][j].idxs.front(); nutrient[i][j].idxs.pop_front();
					if (trees[id].age <= nutrient[i][j].num) {
						//���̰� 1 �����Ѵ�.
						tmpTrees.push_back({ i,j,trees[id].age + 1 });
						nutrient[i][j].num -= trees[id].age;//���� ���̸�ŭ ������� ���־� ��.
					}
					else {//���� �� ũ�� �׾��ٰ� �Ǵ��ؾߵ�.
						died.push_back({ i,j,trees[id].age });
					}
				}
				if (!nutrient[i][j].idxs.empty()) {//���� ��������.
					//�� �� �� ���ҳ�? �׷� �ڿ� ���� �͵��� ���� �� �׾�� ��~ ����
					while (!nutrient[i][j].idxs.empty()) {//����
						int id = nutrient[i][j].idxs.front(); nutrient[i][j].idxs.pop_front();
						died.push_back({ i,j,trees[id].age });
					}
				}
			}
			nutrient[i][j].idxs.clear();//�ϴ� �� �ɾ��� �ִ� �� �����ֱ�.
		}
	}
	trees = tmpTrees;
	int i = 0;
	for (auto [x, y, age] : trees) {//�ٽ� ��ȣ�� �־��ֱ�.
		nutrient[x][y].idxs.push_back(i++);
	}
}
void summer() {
	//�������� ���� �������� ������� ����
	while (!died.empty()) {
		auto [x,y,age] = died.back(); died.pop_back();
		nutrient[x][y].num += age / 2;
	}
}
void spreadtree(int x, int y) {
	int newidx = trees.size();//�� �ε������� ������ �ȴ�.
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;//��ǥ�� �Ѿ.
		nutrient[nx][ny].idxs.push_front(newidx++);//���ο� �������� ���̰� 1��.
		trees.push_back({ nx,ny,1 });//���ο� ���� �ɱ� 
	}
}
void autumn() {//�������� ������ �����Ѵ�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!nutrient[i][j].idxs.empty()) {//������ ����.
				for (auto value : nutrient[i][j].idxs) {//���� Ȯ�� 
					if (trees[value].age%5==0) {//5�� ������� �Ǻ�
						spreadtree(i,j);//������� ���� �ɱ�.
					}
				}
				
			}
		}
	}
}
void winter() {
	//�ܿ￡�� �ʱ��� ����� �߰��� �ָ� �ȴ�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			nutrient[i][j].num += nutrient[i][j].prenum;//�ʱ� ��� �߰��� �ֱ�.
		}
	}
}
void solve() {
	while (k--) {
		spring();
		summer();
		autumn();
		winter();
	}
	cout << trees.size();//�� ���� ����ִ����� Ȯ���ϸ� �ȴ�
}
int main() {
	fast;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> nutrient[i][j].prenum;//�ʱ� ���� ����.
			nutrient[i][j].num= 5;//ó���� ����� 5�̴�.
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees.push_back({ x-1,y-1,z });
		nutrient[x-1][y-1].idxs.push_front(i);//���� �� �ִ��� Ȯ���Ѵ�.
	}
	solve();
	return 0;
}