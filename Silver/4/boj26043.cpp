#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/26043
	26043�� �Ĵ� �޴�
	2���� �޴��� �����ȴ�.
	�Ļ� �غ�Ǵ� n���� ������ ����� S�� �־���.
	S�� ����� ù ��° �������� N��° �������� ������� ó�� ��,
	������ �����ϴ� �޴��� ���� �л� ��� A
	������ �������� �ʴ� �޴��� ���� �л� ��� B
	�Ĵ翡 �Դµ� �� ���� �� �л��� C�� �������.

	1. 1 a b => a��� �ְ� b�� ������ �����Ѵ�.
	2. 2 b => b�� �Ļ� 1�κ��� �غ�ż� �����Ͻÿ�.
*/
using namespace std;
int n;
deque<pair<int, int>>stand;
vector<int>Nomatch;
vector<int>match;
int main() {//�ش��ϴ� �ּҿ� 
	fast;
	cin >> n;
	while (n--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int a, b;
			cin >> a >> b;
			stand.push_back({ a,b });//a��� �л��� b������ �԰� �;���.
		}
		else {
			int b;
			cin >> b;
			auto value = stand.front(); stand.pop_front();
			if (b != value.second) {
				Nomatch.push_back(value.first);
			}
			else {
				match.push_back(value.first);
			}
		}
	}
	if (match.empty()) {//��������� None ���
		cout << "None" << endl;
	}
	else {
		sort(match.begin(), match.end());
		for (auto& value : match) {
			cout << value << " ";
		}
		cout << endl;
	}
	if (Nomatch.empty()) {//��������� None ���
		cout << "None" << endl;
	}
	else {
		sort(Nomatch.begin(), Nomatch.end());
		for (auto& value : Nomatch) {
			cout << value << " ";
		}
		cout << endl;
	}
	if (stand.empty()) {//��������� None ���
		cout << "None" << endl;
	}
	else {
		sort(stand.begin(), stand.end());
		for (auto& value : stand) {
			cout << value.first << " ";
		}
		cout << endl;
	}
	return 0;
}