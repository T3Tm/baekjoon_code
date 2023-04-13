#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16235
	16235번 나무 재테크

	n*n 땅을 샀다.

	재테크란 : 작은 묘목을 구매해서 키우고 파는 것이다.
	M개의 나무를 구매해서 땅에 심는다.
	한 칸에 여러 개의 나무가 심어져 있을 수도 있다.
	1. 가장 처음에 양분은 모든 칸에 5만큼 들어있다.
	

	1. 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
	자신의 칸에 있는 양분만 먹을 수 있다. (여러 개의 나무가 있으면 나이가 어린 나무부터 양분을 먹음.)
	만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽음.

	2. 여름에는 봄에 죽은 나무가 양분으로 변함.
	죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. (소수점 아래 버림)
	
	3. 가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수여야 한다.(%5==0)
	인접한 8칸에 나이가 1인 나무가 생긴다. (무조건 생기는 것 같음.)

	4. 겨울에는 땅에 양분을 추가한다. 각 칸에 추가되는 양분의 양은 A[r][c] 입력으로 주어짐.

	K년이 지난 후에 상도의 땅에 살아있는 나무의 개수를 구하는 프로그램을 작성하시오.
*/
using namespace std;
struct myTree {
	int x, y, age;
};
struct New {
	int age, idx;//나이랑 전에 인덱스 저장해놓기.
};
struct newArr {
	int num,prenum;//영양소.
	deque<int>idxs;//큐로 구현해봐야겠네
};
int n, m, k;
newArr nutrient[12][12];
vector<myTree>trees;
vector<myTree>died;//죽은 나무들 넣기
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
void spring() {
	//자신의 나이만큼 양분을 먹고 나이가 1증가한다.
	//자기 나이만큼 양분을 못 먹으면 즉시 죽음
	// 양분을 먹고 남으면 다음 idx가 먹으면 됨.
	vector<myTree>tmpTrees;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!nutrient[i][j].idxs.empty()) {//누군가가 심어져 있다는 것이다.
				while(!nutrient[i][j].idxs.empty() && nutrient[i][j].num>0) {
					int id = nutrient[i][j].idxs.front(); nutrient[i][j].idxs.pop_front();
					if (trees[id].age <= nutrient[i][j].num) {
						//나이가 1 증가한다.
						tmpTrees.push_back({ i,j,trees[id].age + 1 });
						nutrient[i][j].num -= trees[id].age;//나의 나이만큼 영양분을 없애야 됨.
					}
					else {//내가 더 크면 죽었다고 판단해야됨.
						died.push_back({ i,j,trees[id].age });
					}
				}
				if (!nutrient[i][j].idxs.empty()) {//아직 남아있음.
					//다 안 못 돌았네? 그럼 뒤에 남은 것들은 이제 다 죽어야 됨~ 뒤져
					while (!nutrient[i][j].idxs.empty()) {//뒤져
						int id = nutrient[i][j].idxs.front(); nutrient[i][j].idxs.pop_front();
						died.push_back({ i,j,trees[id].age });
					}
				}
			}
			nutrient[i][j].idxs.clear();//일단 다 심어져 있는 거 없애주기.
		}
	}
	trees = tmpTrees;
	int i = 0;
	for (auto [x, y, age] : trees) {//다시 번호들 넣어주기.
		nutrient[x][y].idxs.push_back(i++);
	}
}
void summer() {
	//여름에는 죽은 나무들이 양분으로 변함
	while (!died.empty()) {
		auto [x,y,age] = died.back(); died.pop_back();
		nutrient[x][y].num += age / 2;
	}
}
void spreadtree(int x, int y) {
	int newidx = trees.size();//이 인덱스부터 넣으면 된다.
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;//좌표들 넘어감.
		nutrient[nx][ny].idxs.push_front(newidx++);//새로운 나무들은 나이가 1임.
		trees.push_back({ nx,ny,1 });//새로운 나무 심기 
	}
}
void autumn() {//가을에는 나무가 번식한다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!nutrient[i][j].idxs.empty()) {//누군가 있음.
				for (auto value : nutrient[i][j].idxs) {//값들 확이 
					if (trees[value].age%5==0) {//5의 배수인지 판별
						spreadtree(i,j);//사방으로 나무 심기.
					}
				}
				
			}
		}
	}
}
void winter() {
	//겨울에는 초기의 양분을 추가로 주면 된다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			nutrient[i][j].num += nutrient[i][j].prenum;//초기 양분 추가로 주기.
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
	cout << trees.size();//몇 마리 살아있는지만 확인하면 된다
}
int main() {
	fast;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> nutrient[i][j].prenum;//초기 상태 보존.
			nutrient[i][j].num= 5;//처음에 양분은 5이다.
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees.push_back({ x-1,y-1,z });
		nutrient[x-1][y-1].idxs.push_front(i);//누가 들어가 있는지 확인한다.
	}
	solve();
	return 0;
}