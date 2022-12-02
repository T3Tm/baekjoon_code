#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/21756
	지우개
	N개의 칸에 1부터N가지의 수들이 왼쪽부터 순서대로 저장된다.
	(A) 홀수번 칸의 수들을 모두 지운다.
	(B) 남은 수들을 왼쪽으로 모은다.
	1,3,5,7
	2,4,6,8 < 만 남음 
	그럼
	2번이 1번 4번은 2번 6번은 3번 8번은4 번이니까 즉 2로 나눈 것이다.
	거기에서 다시 1,3,5,7 지우면
	1번 -> 2 -> 4 -> 8 -> 16 -> 32 -> 64
	64,32,16,8,4,2,1 이 숫자들만 가능함
	그랬을 때 젤 큰 숫자가 가능
*/
using namespace std;
int main() {
	fast;
	int n;
	cin >> n;
	int number[8] = { 64,32,16,8,4,2,1 };
	for (auto value : number) {
		if (n >= value) {
			cout << value;
			break;
		}
	}
	return 0;
}