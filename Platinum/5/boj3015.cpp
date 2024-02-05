#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/3015
	3015�� ���ƽý� �����

	0,1,2,3,4,5,6

	5������ ���� ��
	4���� 5���� �׳� �� �� ����
	3���� 5���� 4���� ũ�� �ʾҴٸ� �� �� ����.
	�׷� �� ū �ָ�?
*/
using namespace std;
long long n, answer;
int arr[500002];
int save[500002];//���ʿ��� ���� �� ���� ū �༮�� ���������.
int cnt[500002];
void rightbig() {
	stack<pair<int, int>>tmp;
	for (int i = n - 1; i >= 0; i--) {
		while (!tmp.empty() && tmp.top().first < arr[i]) {
			auto [v, idx] = tmp.top(); tmp.pop();
			save[idx] = i;
		}
		tmp.push({ arr[i],i });
	}
}
void solve() {//
	rightbig();//�ڽ��� ���ʿ� ū ���� ����
	stack<pair<int, int>>tmp;//������ ���� ���� ���� ��
	for (int i = 0; i < n; i++) {
		while (!tmp.empty() && tmp.top().first < arr[i]) {//�� ���� ������ ū ���� ������ ������ ���� �����ָ� ��.
			auto [v, idx] = tmp.top(); tmp.pop();
			answer++;//arr[i]�� �� �� �ִ� ����.
			answer += (int)tmp.size() - cnt[save[idx]];
		}
		cnt[i] = tmp.size();
		tmp.push({ arr[i],i });
	}
	while (!tmp.empty()) {
		auto [v, idx] = tmp.top(); tmp.pop();
		answer += (int)tmp.size() - cnt[save[idx]];
	}
	cout << answer;
}
int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	solve();
	return 0;
}