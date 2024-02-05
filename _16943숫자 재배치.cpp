#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16943
	숫자 재배치
	-	c는 0으로 시작 안 된다.
	-	b보다 작으면서 가장 큰 값을 찾자.
	10^9 => 10억
*/
using namespace std;
int a, b,result=-1;
vector<int>Numb;
int main() {
	fast;
	cin >> a >> b;
	while (a) {
		Numb.push_back(a % 10);
		a /= 10;
	}
	sort(Numb.begin(),Numb.end());
	do {
		if (Numb[0] == 0)continue;
		int c = 0;
		for (auto value : Numb) {//숫자 뽑아내기
			c = c * 10 + value;
		}
		if (b > c) {
			result = max(c, result);
		}
	} while (next_permutation(Numb.begin(), Numb.end()));
	cout << result;
	return 0;
}