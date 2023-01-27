#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1969
	DNA
*/
using namespace std;
int n, m,cnt=0;
int alphabet[52][28];
int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) { //알파벳 갯수세기
			alphabet[j][temp[j] - 'A']++;
		}
	}
	for (int i = 0; i < m; i++) {
		int maxidx, maxvalue = 0;
		for (int j = 0; j <=25; j++) { //누가 제일 많은지 idx 확인
			if (maxvalue < alphabet[i][j]) { // 같다를 넣지 않아야 같을 때 사전순으로 앞에 것이 나옴.
				maxvalue = alphabet[i][j];
				maxidx = j;
			}
		}
		cout << (char)(maxidx + 'A');
		for (int j = 0; j <= 25; j++) { // Hamming Distance 구하기
			if (maxidx!=j && alphabet[i][j]) cnt+=alphabet[i][j];
		}
	}
	cout << endl << cnt;
	return 0;
}