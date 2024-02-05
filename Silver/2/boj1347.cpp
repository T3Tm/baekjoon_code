#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/1347
	미로 만들기
*/
int arr[200][200];
int v[200][200];
string word;
int n;
int minx=199, miny=199, maxx=0, maxy=0;
map<char, pair<int, int>>Move = { {'e',{0,1}} ,{'w',{0,-1}},{'s',{1,0}},{'n',{-1,0}} } ;
void convert(char& see,char next) {
	if (see == 'e') {//동
		if (next == 'R') {//오른쪽
			see = 's';
		}
		else {
			see = 'n';
		}
	}
	else if (see == 'w') {//서
		if (next == 'R') {//오른쪽
			see = 'n';
		}
		else {
			see = 's';
		}
	}
	else if (see == 's') {//남
		if (next == 'R') {//오른쪽
			see = 'w';
		}
		else {
			see = 'e';
		}
	}
	else if (see == 'n') {//북
		if (next == 'R') {//오른쪽
			see = 'e';
		}
		else {
			see = 'w';
		}
	}
}
int idx = 0;
void makeMaze(int x,int y,char see) {
	v[x][y] = 1;
	maxx = max(maxx, x);
	maxy = max(maxy, y);
	minx = min(minx, x);
	miny = min(miny, y);
	if (idx == n)return;
	char command = word[idx];
	if (command == 'F') {
		x = Move[see].first+x, y = Move[see].second+y;
	}
	else {
		convert(see, command);
	}
	idx++;
	makeMaze(x, y, see);
}
int main() {
	fast;
	cin >> n >> word;
	makeMaze(100, 100, 's');
	for (int row = minx; row <= maxx; row++) {
		for(int column=miny;column<=maxy;column++){
			if (v[row][column]) cout << '.';
			else cout << '#';
		}
		cout << endl;
	}
	return 0;
}