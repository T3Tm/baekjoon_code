#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/15736
	15736번 청기 백기
	
	각 학부에서 N명씩 있음.
	
	N개의 깃발이 청색이 위로 백색이 아래로 보이도록 놓여있다.
	
	N개의 청청청..
	1,2,3,4,~~,N

	21억
	1 (1)
	2 (1)
	3 (1)
	4 (2)
	5 (2)
	6 (2)
	7 (2)
	8 (2)
	9 (3)
	10 (3)
	11 (3)
	12 (3)
	13 (3)
	14 (3)
	15 (3)
	16 (4)
	17 (4)
	18 (4)
	19 (4)
	20 (4)
	21 (4)
	22 (4)
	23 (4)
	24 (4)
	25 (5)
*/
using namespace std;
int main() {
	fast;
	int answer = 1, end = 3,plus=5, n; cin >> n;
	while (end<n) {//n 30
		end += plus;
		plus += 2;
		answer++;
	}
	cout << answer;
	return 0;
}