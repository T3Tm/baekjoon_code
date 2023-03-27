#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/27921
	27921번 동전 퍼즐
	
*/
using namespace std;
int h1, w1;
int h2, w2;
int arr[32][32];
struct loc {
	int x, y;
};
vector<loc>Loc;
int answer = 0;
int maxvalue = 0;

int main() {
	fast;
	cin >> h1 >> w1;
	for (int i = 0; i < h1; i++) {//첫번쨰
		string temp;
		cin >> temp;
		for (int j = 0; j < w1; j++) {
			if (temp[j] == 'O') {
				arr[i][j] = 1;
				Loc.push_back({ i,j });
			}
		}
	}
	cin >> h2 >> w2;
	for (int i = 10; i < h2+10; i++) {//두번째
		string temp;
		cin >> temp;
		for (int j = 0; j < w2; j++) {
			if (temp[j] == 'O') {
				arr[i][j+10] = 1;
				answer++;
			}
		}
	}

	//h1,w1 있는데, w1가 30에 도달했다면?
	int column = 1;
	while(!Loc.empty()){//애초에 Loc에 아무것도 안 들어있을 수도 있다.
		bool down = false;
		bool isexit = false;
		for (auto& value : Loc) {//모든 좌표빼주기
			arr[value.x][value.y]--;
		}
		int cnt = 0;
		for (auto& value : Loc) {//좌표 뺀 것을 기준으로
			arr[value.x][value.y + column]++;//column 만큼 더해서 
			if (arr[value.x][value.y + column] == 2)cnt++;//더한 칸에 값이 2이면 check
 			value = { value.x,value.y + column };//값을 column만큼 더해줘서 덮어쓰기
			if (value.y == 30)down = true;//제일 오른쪽에 있는 것이 30에 도달했다면?
			if (value.y == 0)down = true;//제일 왼쪽에 있는 것이 0에 도달했다면?
		}
		if (down) {
			for (auto& value : Loc) {//내려야 할 때 
				arr[value.x][value.y]--;//더한 값 빼고
				value = { value.x + 1,value.y };//한 칸 내려서 더해주기.
				arr[value.x][value.y]++;
				if (value.x == 30)isexit = true;//끝나는 조건
			}
			column *= -1;//음수로 간다.
		}
		maxvalue = max(maxvalue, cnt);
		if (isexit)break;
	}
	cout << answer - maxvalue;
	return 0;
}