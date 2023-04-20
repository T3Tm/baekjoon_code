#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1789
	1789번 수들의 합
	서로 다른 N개의 자연수의 합이 S라고 한다
	sum(N..) =S일때
	자연수 N의 최댓값은 얼마일까?
	서로 다른 자연수 n개를 더한다.

	N의 최댓값이라함은
	
	N개를 최대한으로 만들고 싶으면 작은 수부터 더해서 S를 만들면 되지 않나 싶음.
*/
using namespace std;
long long s,answer,tmp;
int main() {
	fast; cin >> s;
	for (long long i = 1;tmp!=s && s-tmp>=i ; i++) {
		tmp += i,answer++;
	}
	cout << answer;
	return 0;
}