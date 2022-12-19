#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16918
	봄버맨
	연쇄 반응 없다

	1.가장 처음에 봄버맨은 일부 칸에 폭탄을 설치
	2.1초 동안은 아무것도 안 함
	3.1초 동안 폭탄이 설치되어 있지 않은 모든 칸에 폭탄을 설치한다.
*/
using namespace std;
char graph[202][202];
int r, c, n;
queue<pair<int, int>>loc;
vector<vector<pair<int, int>>>bombloc(202);
int bombidx = 0; //삭제할 idx
int lastidx = 1; 
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int Time = 1;
void process1() { //폭탄 모든 곳에 설치
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (graph[i][j] != 'O') {
				bombloc[lastidx].push_back({ i,j });
				graph[i][j] = 'O';
			}
		}
	}
	lastidx++;
	Time++;
}
void process2(int alreadybomb[][202]) {//3초 전에 설치한 폭탄 삭제
	int nextbomb[202][202] = { 0 };
	for (auto precur : bombloc[bombidx]) {
		if (alreadybomb[precur.first][precur.second])continue;
		graph[precur.first][precur.second] = '.';
		for (int i = 0; i < 4; i++) {
			int nx = precur.first + dx[i];
			int ny = precur.second + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)continue;
			graph[nx][ny] = '.';
			nextbomb[nx][ny] = 1;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			alreadybomb[i][j] = nextbomb[i][j];
		}
	}
	bombidx++;
	Time++;
}
bool timecheck() {
	return Time == n;
}
void bombberman() {
	if (timecheck())return;
	int previousbomb[202][202] = { 0 };
	while (true) {
		process1();
		if (timecheck())return;
		process2(previousbomb);
		if (timecheck())return;
	}
}
int main(){
	fast;
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < c; j++) {
			graph[i][j] = temp[j];
			if (graph[i][j] == 'O') {//O
				bombloc[0].push_back({i,j});//좌표 i,j
			}
		}
		graph[i][temp.size()] = '\0';
	}
	bombberman();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << graph[i][j];
		}
		cout << endl;
	}
	return 0;
}