#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
    https://www.acmicpc.net/problem/16139
    인간-컴퓨터 상호작용
*/

int main() {
	fast;
	string word;
	int t;
	cin >> word >> t;
	vector<vector<int>>save;
	vector<int>temp(26, 0);
	for (int idx = 0; idx < word.length(); idx++) {
		temp[word[idx] - 'a']++;
		save.push_back(temp);
	}

	while (t--) {
		char chr;
		int front, end;
		cin >> chr >> front >> end;
		if (front != 0) {
			cout << save[end][chr - 'a'] - save[front-1][chr - 'a'] << endl;
		}
		else {
			cout << save[end][chr - 'a'] << endl;
		}
	}
	return 0;
}