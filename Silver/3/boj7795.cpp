#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/7795
	먹을 것인가 먹힐 것인가

	A의 쌍과 B의 쌍이 주어진다.

	A가 B를 먹을 수 있는 쌍의 갯수는 7가지이다.

	A => 8,1,7,3,1 
	B => 3,6,1
	
	큰 순으로 다시 나열
	A=> 8,7,3,1,1
	B=> 6,3,1
	8,6 비교 그러면 8이 다 먹을 수 있다는 거

	A의 최대로 큰 것이
	B의 최대로 큰 것보다 작으면 더이상 비교할 이유가 없음..
*/
int a[20001], b[20001];
int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		int sizeA, sizeB;
		cin >> sizeA >> sizeB;
		for (int i = 0; i < sizeA; i++) cin >> a[i];
		for (int i = 0; i < sizeB; i++) cin >> b[i];
		sort(a, a + sizeA, [](int& a, int& b) {return a > b; });
		sort(b, b + sizeB, [](int& a, int& b) {return a > b; });
		int Count = 0;//A에서 B를 먹을 수 있는 것을 세줄 것
		int idxj = 0;//맨 처음 것과 비교 
		for (int i = 0; i < sizeA; i++) {
			if (a[i]>b[idxj]) {
				Count += (sizeB - idxj);
			}
			else {
				idxj++;
				if (idxj==sizeB)break;
				i--;
				continue;
			}
		}
		cout << Count << endl;
	}
	return 0;
}