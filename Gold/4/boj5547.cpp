#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/5547
	일루미네이션

	육각형이기에 맞닿아 있는 곳을 생각해 보자면

	y-1,y+1,x-1,x+1,x-1 y+1,x+1 y+1
	y-1,y+1,x-1,x-1 y-1,x+1 y-1,x+1
*/
using namespace std;
vector<vector<int>>illumination;
int visited[102][102],w,h,visited1[102][102];
int dx[] = { 0,0,-1,-1,1,1 };
int dy[] = { -1,1,0,-1,-1,0 };
int dy1[] = { -1,1,0,+1,+1,0 };
bool borderCheck(int row, int column) {
	if (row < 0 || row >= w || column < 0 || column >= h)return true;
	return false;
}
void dfs(int x, int y) {
	visited1[x][y] = 1;
	for (int z = 0; z < 6; z++) {
		int nx = x + dx[z];
		int ny;
		if (x % 2)ny = y + dy[z];
		else ny = y + dy1[z];
		if (borderCheck(nx, ny) || visited1[nx][ny] || illumination[nx][ny])continue;
		dfs(nx, ny);
	}
}
void process() {//외벽인지 내벽인지 판단하기
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (illumination[i][j] || visited1[i][j])continue;
			for (int z = 0; z < 6; z++) {
				int nx = i + dx[z];
				int ny;
				if (i % 2) ny = j + dy[z];
				else ny = j + dy1[z];
				if (borderCheck(nx, ny))dfs(i, j);
			}
		}
	}
}
int process2(int row, int column) { //dfs로 넓이 구하기
	int sum = 0;
	visited[row][column] = 1;
	for (int i = 0; i < 6; i++) {
		int nx = row + dx[i];
		int ny;
		if (row % 2) ny = column + dy[i];
		else ny = column + dy1[i];
		if (borderCheck(nx,ny) || (!illumination[nx][ny] && visited1[nx][ny]))sum++;
		else if (illumination[nx][ny] && !visited[nx][ny]) sum += process2(nx, ny);
	}
	return sum;
}
int process1() {//총 넓이 구하기
	int result=0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (visited[i][j] || !illumination[i][j])continue;
			result += process2(i, j);
		}
	}
	return result;
}
int main() {
	fast;
	cin >> h >> w;
	illumination.resize(w, vector<int>(h, 0));
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cin >> illumination[i][j];
		}
	}
	process();
	cout << process1();
	return 0;
}