#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/13413
	오셀로 재배치

	앞면이 검정
	뒷면이 흰색

	1. 배치된 말 중에 임의로 2개의 말을 골라 서로의 위치를 바꿀 수 있따.
	2. 말 1개를 들어 뒤집어 놓아 색상을 변경할 수 있다.
	B의 갯수 세고 틀린 곳의 인덱스 알아내기.

	갯수 같으므로 위치만 바꾸는 횟수 1번

	갯수 다르고 위치 다름 
	갯수 3개, 3개
	3번

	갯수 1개, 다른 것은 3개
	갯수 1 + 다른 것 1개 한개의 쌍임 > cnt ++ 1번
*/
using namespace std;
int main() {
	fast;
	int T;
	cin >> T;
	while (T--) {
		int a;
		int cnt = 0;
		string src, dest;
		cin >> a >> src >> dest;
		int srcB = 0,destB=0;
		int differ = 0;
		for (int idx = 0; idx < a; idx++) {
			if (src[idx] == 'B')srcB++;
			if (dest[idx] == 'B')destB++;
			if (dest[idx] != src[idx])differ++;
		}
		int gap = abs(destB - srcB);
		while(differ!=0 &&gap!=0){
			differ--;
			gap--;
			cnt++;
		}
		if (differ)cnt += differ/2;
		else cnt += gap;
		cout << cnt << endl;
	}
	return 0;
}