#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/9656
	9656번 돌 게임 2
	n==4
	상근 3, 창영 1
	n%3==1
*/
using namespace std;
int main() {
	fast; 
	int n; cin >> n;
	cout << (n & 1 ? "CY" : "SK");
	return 0;
}