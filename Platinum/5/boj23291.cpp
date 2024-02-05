#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/23291
	23291�� ���� ����
	������ ������ü�̴�.
	1. ����� ���� ���� ���� ���׿� ����⸦ �� ���� �ִ´�. O(n) �ּҿ� �ִ� �Լ�
	2. ���� ���ʿ� �ִ� ������ �� �����ʿ� �ִ� ���� ���� �״´�. �״� �Լ�
	3. 2�� �̻� �׿� �ִ� ������ ��� ���� �ξ��Ų ����, �ð� �������� 90�� ȸ���Ѵ�.
	3-1(���⼭ ���� ������ ���� ���̰� ���� ���̺��� ���� �������� ���� ��.)
	4. ������ ������ ����� �� ����
	4-1( ������ �� ���׿��� ����� ���� ���̸� 5�� ���� ���� d��� �Ѵ�.
	d>0 �� ���� �� ������� ���� ���� ������ d������ ���� ���� �ִ� ������ ������.
	��� ������ ĭ�� ���ؼ� ���ÿ� �߻��Ѵ�. �����̱� ������ �Ǵ� �͵� stack�� �ְ�
	stack ���� �ϳ��� ���鼭 �����ؾߵ�.
	5. ������ ���ʺ��� ���ʴ�� �ٴڿ� ���ƾ���.
	6. ����� �߽����� n/2���� ���� �ξ��ؼ� 180�� ȸ�� ��Ų��.
	(������ 2�� �����Ѵ�)
	7.4���� ����
	8. 5�� ���� << �̰��� ������ �� ���� �� ���� ���� �˾Ƴ���.
	9. ���� ���� ����ִ� ����, ���� ����ִ� ����� �� ���̰� k ���ϰ� �Ƿ���
	�� �� �����ؾ� �ǳ� ��� ��.

*/
using namespace std;
int n, k;
struct my {
	int idx, v;//�ε����� value�� ������
};
struct loc {
	int x, y;
	bool operator()(const loc& a, const loc& b)const {
		return a.x < b.x;
	}
};
struct xy {
	int a, b, c, d, e;//a,b ��ǥ�� c,d ��ǥ�� e��ŭ
};

vector<deque<int>>arr(12, deque<int>(0));
vector<my>small;
vector<my>big;
void init() {//small ���� �Ϳ� �ε����� �� ���ϱ�.
	for (auto [idx, v] : small) {
		arr[0][idx]++;//�� �����ϱ�.
	}
}
void setup() {
	auto fv = arr[0].front(); arr[0].pop_front();
	arr[1].push_back(fv);
}
void rightrotate() {//���� ���� ������ �÷��ָ� �ȴ�.
	int height = 1;
	while (1) {
		auto width = arr[1].size();//
		if (arr[0].size() - width < height) {//�ٴ� 
			break;
		}
		deque<deque<int>>tmp;
		for (int j = 0; j < width; j++) {
			deque<int>ttmp;
			for (int i = 0; !arr[i].empty(); i++) {
				ttmp.push_back(arr[i].front());
				arr[i].pop_front();
			}
			tmp.push_front(ttmp);
		}
		int idx = 1;
		while (!tmp.empty()) {
			auto value = tmp[0]; tmp.pop_front();
			while (!value.empty()) {
				arr[idx].push_back(value.front()); value.pop_front();
			}
			idx++;
		}
		height = idx;//���� ���ϱ�.
	}
}
void control() {//����� ��ü�� �����ϱ�.
	vector<xy>vari;
	int dx[] = { 0,1 };
	int dy[] = { 1,0 };
	for (int i = 0; !arr[i].empty(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			for (int z = 0; z < 2; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx < 0 || arr[nx].empty() || ny < 0 || ny >= arr[nx].size())continue;//��ǥ �Ѿ� �� ��
				int d = abs(arr[i][j] - arr[nx][ny]) / 5;
				if (d > 0) {
					if (arr[i][j] < arr[nx][ny]) {//i,j ��ǥ�� d��ŭ �� �����.
						vari.push_back({ i,j,nx,ny,d });
					}
					else {
						vari.push_back({ nx,ny,i,j,d });//nx,ny ��ǥ�� d��ŭ �ִ´�.
					}
				}
			}
		}
	}
	while (!vari.empty()) {
		auto [x, y, nx, ny, d] = vari.back(); vari.pop_back();
		arr[x][y] += d;
		arr[nx][ny] -= d;
	}
}
void layblock() {
	int width = arr[1].size();
	deque<int>tmp;
	for (int j = 0; j < width; j++) {
		for (int i = 0; !arr[i].empty(); i++) {
			tmp.push_back(arr[i].front()); arr[i].pop_front();
		}
	}
	while (!tmp.empty()) {
		arr[0].push_front(tmp.back()); tmp.pop_back();
	}
}
void divideright() {
	deque<deque<int>>tmp;
	for (int j = 1; j < 3; j++) {//1,3
		int cnt = arr[0].size() / 2;
		int x = 0;
		for (int z = 0; !arr[z].empty(); z++) {
			deque<int>ttmp;
			for (int i = 0; i < cnt; i++) {
				ttmp.push_front(arr[x].front()); arr[x].pop_front();
			}
			tmp.push_front(ttmp);
			x++;
		}
		int idx = j;
		while (!tmp.empty()) {
			auto value = tmp[0]; tmp.pop_front();
			while (!value.empty()) {
				arr[idx].push_front(value.back()); value.pop_back();
			}
			idx++;
		}
	}

}
void bigsmall() {
	small.clear(); big.clear();
	small.push_back({ -1,10001 });//���� ���� ����ִ� �� �˱� ����
	big.push_back({ -1,0 });//���� ���� ���� �˱� ����
	for (int i = 0; i < n; i++) {
		if (arr[0][i] > big[0].v) {
			big.clear();
			big.push_back({ i,arr[0][i] });
		}
		else if (arr[0][i] == big[0].v) {
			big.push_back({ i,arr[0][i] });
		}
		if (arr[0][i] < small[0].v) {
			small.clear();
			small.push_back({ i,arr[0][i] });
		}
		else if (arr[0][i] == small[0].v) {
			small.push_back({ i,arr[0][i] });
		}
	}
}
void solve() {
	long long answer;
	for (answer = 0; big[0].v - small[0].v > k; answer++) {
		init();//�ʱ⿡ ���� ���� �� ���� �ֱ�.
		setup();//���� �״� �Լ�
		rightrotate();//���ߺξ� ���Ѽ� 90�� �����ֱ�.
		control();//����� �� �����ϱ�.
		layblock();//������ �ٴڿ� ��������.
		divideright();//������ ������ 180�� ����
		control();//�ٽ� �����ϰ�	
		layblock();//������ �ٴڿ� ��������. 
		bigsmall();//ũ�� ���� �� �˾Ƴ���.
	}
	cout << answer;
}
int main() {
	fast;
	cin >> n >> k;//�Է�
	small.push_back({ -1,10001 });//���� ���� ����ִ� �� �˱� ����
	big.push_back({ -1,0 });//���� ���� ���� �˱� ����
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[0].push_back(num);
		if (num > big[0].v) {
			big.clear();
			big.push_back({ i,num });
		}
		else if (num == big[0].v) {
			big.push_back({ i,num });
		}
		if (num < small[0].v) {
			small.clear();
			small.push_back({ i,num });
		}
		else if (num == small[0].v) {
			small.push_back({ i,num });
		}
	}
	solve();
	return 0;
}