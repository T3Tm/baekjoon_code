#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cout.tie(nullptr),cin.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1730
	1730번 판화
*/
using namespace std;
int n;
string t;
vector<vector<char>>arr;
map<char, pair<int, int>>convert = { {'R',{0,1}},{'D',{1,0}},{'L',{0,-1}},{'U',{-1,0} } };
map<char, char>word = { {'D','|'},{'U', '|'},{'L','-'},{'R','-'} };
void mapconvert(char value, int x, int y) {
	if (arr[x][y] == '.') {
		arr[x][y] = value;
	}
	else if (arr[x][y] == '|' && value == '-') {
		arr[x][y] = '+';
	}
	else if (arr[x][y] == '-' && value == '|') {
		arr[x][y] = '+';
	}
}
int main() {
	fast;
	cin >> n >> t;
	arr.resize(n, vector<char>(n, '.'));
	int x = 0, y = 0;
	for (auto& value : t) {
		auto [dx, dy] = convert[value];
		auto w = word[value];
		int nx = x + dx;
		int ny = y + dy;
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;//벗어남
		mapconvert(w, x, y);
		mapconvert(w, nx, ny);
		x = nx, y = ny;
	}
	for (auto row : arr) {
		for (auto value : row) {
			cout << value;
		}
		cout << endl;
	}
	return 0;
}