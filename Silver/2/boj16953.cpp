#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16953
	16953번 A -> B

	A에서 B를 만들려고 하는 데
	연산은 2를 곱하는 연산
	1을 수의 오른쪽에 추가하는 연산이 있다.
	B에서 2로 나눈다. 안 나뉘면 1을 넣는 연산을 했을 것이다.

	왜냐면 연산이 가능한 것이 2곱하기 or 1빼기 이니까.
*/
using namespace std;
long long a, b, answer;
int main() {
	fast; cin >> a >> b;
	while (b != a && b) {
		if (b % 2 && b % 10 == 1)b /= 10;//제일 오른쪽 10 빼주기
		else if (b % 2) {
			cout << -1; exit(0);
		}
		else b /= 2; //2로 나누기
		answer++;
	}
	answer++;
	if (!b)answer = -1;
	cout << answer;
	return 0;
}