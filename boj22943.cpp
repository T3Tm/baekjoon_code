#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
	https://www.acmicpc.net/problem/22943
	22943번 수

	0~9까지 k가지의 숫자를 한 번씩만 사용하여 만들 수 있는 수 중 아래의 조건을 모두 만족하는 수의 갯수 세기
	1가지의 숫자


	맨 앞에는 0이 올 수 없다.
	1. 서로 다른 두 개의 소수의 합으로 나타낼 수 있는 경우
		서로 다른
	2. M으로 나누어 떨어지지 않을 때까지 나눈 수가 두개의 소수의 곱인 경우
	9라는 수는 3*3 이라는 소수의 곱이다.

	예를 들어) k가 1이고 M이 11인 경우
	0~9
	1<=k<=5
	2<=M<=10^9 10억

	0부터 9까지 5가지의 숫자를 한 번씩 사용하여 만들 수 있는 숫자.

	백트래킹으로

	[] [] [] [] []
	9  9  8  7  6

	9*9*8*7*6 의 경우의 수에서
	그럼 9*9*8*7*6 이라는 백트래킹 경우의 수에서
	해당하는 숫자인 n이 if(TwoAddPrime[n] && TwoMulPrime[n])cnt++;
	둘 다 전처리를 통해 O(1)에 알아낼 수 있음.
	O(1)
	O(1)

	서로 다른 두개의 소수의 합을 구하기.
	o(n^2) => 4천만번 연산하면 서로다른 두개의 소수의 합을 다 구할 수 있음.
	44,930,460

	98765 라는 숫자가 들어올 수 있는데 해당하는 숫자가 서로 다른 두개의 소수의 합으로 나타나는지 알려면

*/
using namespace std;
bool TwoAddPrime[100000];//최대 언제인지 모름.
bool TwoMulPrime[100000];
int n, k;
long long cnt;
vector<int>primes;//소수들 넣어놓기
bool prime[100000] = { true,true };//소수인지 확인
pair<int, int>startend[5] = { {1,9},{0,9},{0,9},{0,9},{0,9} };
bool avail[10];
void GetNumber(int number, int depth) {
	if (depth == n) {
		if (TwoAddPrime[number]) {
			while (number % k == 0) {
				number /= k;
			}
			if (TwoMulPrime[number])cnt++;
		}
		return;
	}
	for (int i = startend[depth].first; i <= startend[depth].second; i++) {
		if (!avail[i]) {
			avail[i] = true;
			GetNumber(number * 10 + i, depth + 1);
			avail[i] = false;
		}

	}
}
int main() {
	fast;
	cin >> n >> k;
	for (int i = 2; i * i <= 100000; i++) {
		if (!prime[i])
			for (int j = i * i; j <= 100000; j += i) {
				prime[j] = true;
			}
	}
	for (int i = 2; i <= 98765; i++) {//소수들 넣어놓기
		if (!prime[i])primes.push_back(i);
	}
	for (int i = 0; i < 9480; i++) {
		for (int j = 0; j < 9480; j++) {
			if (i != j) {//합은 넣으면 안됨.
				long long add = primes[i] + primes[j];
				if (add < 100000) {
					TwoAddPrime[add] = true;
				}
			}
			long long value = primes[i] * (long long)primes[j];
			if (value < 100000) {
				TwoMulPrime[value] = true;
			}
		}
	}
	GetNumber(0, 0);
	cout << cnt;
	return 0;
}

