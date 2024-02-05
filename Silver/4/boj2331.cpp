#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2331
	2331번 반복수열


*/
using namespace std;
long long a, p;
map<int, int>numbers;
inline long long Intpow(long long src, int repeat) {
	long long temp = 1;
	for (int i = 0; i < repeat; i++)temp *= src;
	return temp;
}
long long nextnumber(long long a) {
	long long temp = 0;
	while (a) {
		temp += Intpow(a % 10, p);
		a /= 10;
	}
	return temp;
}
int main() {
	fast;
	cin >> a >> p;
	for (int i = 0;; i++) {
		if (numbers.find(a) != numbers.end()) {//이미 있었음.
			cout << numbers[a];
			break;
		}
		numbers[a] = i;
		a = nextnumber(a);
	}
	return 0;
}