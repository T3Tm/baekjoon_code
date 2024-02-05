#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1850
	1850번 최대공약수
*/
using namespace std;
using lld = long long;
lld a, b;
lld gcd(lld t1, lld t2) {
	return (t1 % t2 == 0 ? t2 : gcd(t2, t1 % t2));
}
int main() {
	fast;
	cin >> a >> b;//a의 갯수 만큼 1이 있는 것이고 b의 갯수 만큼 1이 있는 것이다.
	//최대 공약수라고 함은 둘이 
	if (a < b)swap(a, b);
	string temp(gcd(a, b), '1');
	cout << temp;
	return 0;
}