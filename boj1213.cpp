#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1213
	1213�� �Ӹ���� �����

	S�� �Ӹ�������� �ٲ��
	���� |S| %2 == 0�̸� �� ���ڵ��� ������ ¦����������.
	������ |S|%2 �̸� �ϳ��� ���ڰ� Ȧ���� �ٸ� ���� �� ¦���� �����Ѵ�.
*/
using namespace std;
map<char, int>alpha;
string answer;
int main() {
	fast;
	string tmp; cin >> tmp;
	for (auto& value : tmp) {
		if (!alpha.count(value)) alpha[value] = 0;
		alpha[value]++;
	}
	bool flag = (tmp.size() % 2 ? 1 : 0);//���̰� ¦�� ���� Ȧ������ �Ǵ�
	char one;//�ϳ��� ���ڸ� ���� ������.
	for (auto [key, value] : alpha) {//Ȧ�� �ι� �������� �Ǵ�.
		if (tmp.size() % 2 && value % 2) {//¦���� flag 0�̶�� ���ִµ� �̰ų����� ����
			if (flag) {//������ ������
				flag = false;
				one = key;
			}
			else {
				answer = "I'm Sorry Hansoo";
				break;
			}
		}
		else if (tmp.size() % 2 == 0 && value % 2) {
			answer = "I'm Sorry Hansoo";
			break;
		}
		for (int i = 0; i < value / 2; i++) {
			answer.push_back(key);
		}
	}
	string ttmp = answer; reverse(ttmp.begin(), ttmp.end());
	if (answer.back() != 'o' && tmp.size() % 2) {
		answer = answer + one + ttmp;
	}
	else if (answer.back() != 'o') {
		answer = answer + ttmp;
	}
	cout << answer;
	return 0;
}