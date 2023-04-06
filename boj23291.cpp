#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/23291
	23291번 어항 정리
	어항은 정육면체이다.
	1. 물고기 수가 가장 적은 어항에 물고기를 한 마리 넣는다. O(n) 최소에 넣는 함수
	2. 가장 왼쪽에 있는 어항을 그 오른쪽에 있는 어항 위에 쌓는다. 쌓는 함수
	3. 2개 이상 쌓여 있는 어항을 모두 공중 부양시킨 다음, 시계 방향으로 90도 회전한다.
	3-1(여기서 종료 조건은 행의 높이가 열의 길이보다 작을 때까지만 도는 것.)
	4. 인접한 어항의 물고기 수 조절
	4-1( 인접한 두 어항에서 물고기 수의 차이를 5로 나눈 몫을 d라고 한다.
	d>0 두 어항 중 물고기의 수가 많은 곳에서 d마리를 적은 곳에 있는 곳으로 보낸다.
	모든 인접한 칸에 대해서 동시에 발생한다. 동시이기 때문에 되는 것들 stack에 넣고
	stack 에서 하나씩 빼면서 진행해야됨.
	5. 어항을 왼쪽부터 차례대로 바닥에 놓아야함.
	6. 가운데를 중심으로 n/2개를 공중 부양해서 180도 회전 시킨다.
	(무조건 2번 진행한다)
	7.4번을 실행
	8. 5번 실행 << 이것을 실행할 때 많은 것 적은 것을 알아내자.
	9. 가장 많이 들어있는 어항, 적게 들어있는 물고기 수 차이가 k 이하가 되려면
	몇 번 정리해야 되냐 라는 것.

*/
using namespace std;
int n, k;
struct my {
	int idx, v;//인덱스랑 value를 쌍으로
};
struct loc {
	int x, y;
	bool operator()(const loc& a, const loc& b)const {
		return a.x < b.x;
	}
};
struct xy {
	int a, b, c, d, e;//a,b 좌표에 c,d 좌표로 e만큼
};

vector<deque<int>>arr(12, deque<int>(0));
vector<my>small;
vector<my>big;
void init() {//small 작은 것에 인덱스에 값 더하기.
	for (auto [idx, v] : small) {
		arr[0][idx]++;//값 증가하기.
	}
}
void setup() {
	auto fv = arr[0].front(); arr[0].pop_front();
	arr[1].push_back(fv);
}
void rightrotate() {//값을 이제 돌려서 올려주면 된다.
	int height = 1;
	while (1) {
		auto width = arr[1].size();//
		if (arr[0].size() - width < height) {//바닥 
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
		height = idx;//높이 구하기.
	}
}
void control() {//물고기 개체수 조절하기.
	vector<xy>vari;
	int dx[] = { 0,1 };
	int dy[] = { 1,0 };
	for (int i = 0; !arr[i].empty(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			for (int z = 0; z < 2; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx < 0 || arr[nx].empty() || ny < 0 || ny >= arr[nx].size())continue;//좌표 넘어 갈 때
				int d = abs(arr[i][j] - arr[nx][ny]) / 5;
				if (d > 0) {
					if (arr[i][j] < arr[nx][ny]) {//i,j 좌표에 d만큼 더 줘야함.
						vari.push_back({ i,j,nx,ny,d });
					}
					else {
						vari.push_back({ nx,ny,i,j,d });//nx,ny 좌표에 d만큼 넣는다.
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
	small.push_back({ -1,10001 });//가장 적게 들어있는 걸 알기 위해
	big.push_back({ -1,0 });//가장 많은 것은 알기 위해
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
		init();//초기에 작은 곳에 한 마리 넣기.
		setup();//블럭을 쌓는 함수
		rightrotate();//공중부양 시켜서 90도 꺾어주기.
		control();//물고기 수 조절하기.
		layblock();//어항을 바닥에 내려놓기.
		divideright();//절반을 나눠서 180도 꺾기
		control();//다시 조절하고	
		layblock();//어항을 바닥에 내려놓기. 
		bigsmall();//크고 작은 거 알아내기.
	}
	cout << answer;
}
int main() {
	fast;
	cin >> n >> k;//입력
	small.push_back({ -1,10001 });//가장 적게 들어있는 걸 알기 위해
	big.push_back({ -1,0 });//가장 많은 것은 알기 위해
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