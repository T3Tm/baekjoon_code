#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17300
	17300번 패턴
	1. 다음 next를 본다.
	2. 방문했던 아이인지 확인한다.
	3. 방문 안 했던 아이이면 간다.
	4. 방문체크 하고 2번으로 돌아간다.
*/
using namespace std;
struct loc {
	int x, y;
};//1,2 -> 2,0
map<int, loc>convert = { {1,{0,0}},{2,{0,1}},{3,{0,2}},
	{4,{1,0}},{5,{1,1}},{6,{1,2}},
	{7,{2,0}},{8,{2,1}},{9,{2,2}} };
int n;
int arr[12];
bool visited[5][5];
bool pattern(int start, int depth) {
	bool true_false = true;
	if (n == depth) {//
		return true_false;
	}
	auto pre = convert[start];
	visited[pre.x][pre.y] = true;//이미 방문했음.
	auto next = convert[arr[depth]];
	if (!visited[next.x][next.y]) {//방문 안 했을 때
		if (pre.x == next.x) {//가로로 움직일 떄
			if (abs(next.y - pre.y) == 1) {//1칸이네용
				true_false = pattern(arr[depth], depth + 1);//그냥 들어가도 됨.
			}
			else if (abs(next.y - pre.y) == 2) {//2칸 띄어서 가야됨. 중간 애 처리 해줘야됨. //중간에 갔었는지 확인
				if (visited[next.x][max(pre.y - 1, next.y - 1)]) {//중간에는 이미 방문했었던 애니까 괜찮음.
					true_false = pattern(arr[depth], depth + 1);
				}
				else {//중간 애가 방문 안 됐으면 
					return false;
				}
			}
		}
		else if (pre.y == next.y) {//세로로 움직일 때
			if (abs(next.x - pre.x) == 1) {//1칸이네용
				true_false = pattern(arr[depth], depth + 1);//그냥 들어가도 됨.
			}
			else if (abs(next.x - pre.x) == 2) {//2칸 띄어서 가야됨. 중간 애 처리 해줘야됨. //중간에 갔었는지 확인
				if (visited[max(next.x - 1, pre.x - 1)][next.y]) {//중간에는 이미 방문했었던 애니까 괜찮음.
					true_false = pattern(arr[depth], depth + 1);
				}
				else {//중간 애가 방문 안 됐으면 
					return false;
				}
			}
		}
		else {//대각선으로 움직일 때
			if (abs(pre.x - next.x) + abs(pre.y - next.y) == 4) {//중간 처리
				if (visited[max(next.x - 1, pre.x - 1)][max(pre.y - 1, next.y - 1)]) {
					true_false = pattern(arr[depth], depth + 1);
				}
				else {//중간 애를 안 갔으면.
					return false;
				}
			}
			else {//2나 ,3 은 그냥 가도 됨. 중간 처리 안 해줘도 됨.
				true_false = pattern(arr[depth], depth + 1);
			}
		}
	}
	else {//이미 갔던 곳.
		return false;
	}
	return true_false;
}
int main() {//해당하는 최소에 
	fast;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	cout << (pattern(arr[0], 1) ? "YES" : "NO");
	return 0;
}