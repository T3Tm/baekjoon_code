#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/12933
	12933�� ����
*/
using namespace std;
deque<char>quack;
int main() {//�ش��ϴ� �ּҿ� 
	fast;
	string temp;
	cin >> temp;
	int maxvalue = 0;
	int cnt = 0;
	for (auto& value : temp) {
		if (value == 'q') {
			cnt++;
		}
		else if (value == 'k') {//c -> a -> u -> q ������
			char compare[] = { 'c','a','u','q' };
			int idx = 0;
			int repeat = 0;
			int maxrepeat = quack.size();
			while (idx < 4 && !quack.empty() && repeat < maxrepeat) {
				if (compare[idx] == quack.back()) {
					idx++;
					quack.pop_back();
				}
				else {
					quack.push_front(quack.back());
					quack.pop_back();
				}
				repeat++;
			}
			if (idx != 4) {//����� ���� �� ������.
				cout << -1;
				exit(0);
			}
			while (repeat < maxrepeat) {
				quack.push_front(quack.back());
				quack.pop_back();
				repeat++;
			}
			cnt--;//�� �ϳ� �پ�ߵ�.
			continue;//���� �ϳ� �پ��⿡ max �� ���� ��.
		}
		quack.push_back(value);
		maxvalue = max(maxvalue, cnt);
	}
	if (!quack.empty()) {//������� �ʴ´ٴ� ����.
		cout << -1;
		exit(0);
	}
	cout << maxvalue;
	return 0;
}