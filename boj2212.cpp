#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2212
	2212번 센서
	N개의 센서를 설치하였다.
	최대 k개의 집중국을 세울 수 있다.

	만약 2의 좌표에 집중국이 있다면?
	1,3,6,6,7,9
	2 (2,3) , (3,0) , (0,1) (1,2) 2


	3 6 7 8 10 12 14 15 18 20
	(3,3),(3,15),(2,10),(2,18),(2,12),(2,8),(1,6),(1,7)
	gap 
*/
using namespace std;
int n,k;
set<int>arr;
vector<int>gap;
int main() {
	fast; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int num; cin >> num; arr.insert(num);
	}
	auto it = arr.begin();
	while (it != prev(arr.end())) {
		auto fir = *it,sec=*next(it);
		gap.push_back(sec - fir);
		it++;
	}
	n = arr.size();
	k = n - k;
	sort(gap.begin(), gap.end());
	long long answer = 0;
	for (int i = 0; i < k; i++)answer += gap[i];
	cout << answer;
	return 0;
}