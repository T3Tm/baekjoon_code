#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/9663
	N - Queen

	퀸 N개를 서로 공격할 수 없다?
	1. 열에 하나씩 놓는다. 
	2. 중복되지 않게 놓는다. 
	3. check 한다.
	4. check 했을 때 서로 공격 못하면 count++ 한다. 
*/
long long N,answer;
int visited[16];
int arr[15];
void N_Queen(int depth) {
	if (depth == N) { 
		answer++;
		return;
	}
	for (int i = 0; i < N; i++) {//0~N-1
		if (!visited[i]) {
			bool flag = false;
			for (int j = 1; (depth - j) >= 0; j++) {//depth
				if (abs(arr[depth - j] - i) == j) {
					flag=true;
					break;
				}
			}
			if (flag)continue;
			visited[i] = 1;
			arr[depth] = i;
			N_Queen(depth + 1);
			arr[depth] = 0;
			visited[i] = 0;
		}
	}
}
int main(){
	cin >> N;
	N_Queen(0);
	cout << answer;
	return 0;
}