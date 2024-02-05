#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/14248
	점프 점프

*/
using namespace std;
int n, s,answer;
int arr[100002];
int visited[100002];
void jumpjump(int cur) {
	visited[cur] = 1;
	int next = arr[cur];
	for (auto nextcur : { cur + next,cur - next }) {
		if (nextcur < 0 || nextcur >= n)continue;
		if (!visited[nextcur])jumpjump(nextcur);
	}
}
int main(){
	fast;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	cin >> s;
	jumpjump(s - 1);
	for (int i = 0; i < n; i++) {
		if (visited[i])answer++;
	}
	cout << answer;
	return 0;
}