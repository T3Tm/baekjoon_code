#include<bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/5430
	5430�� AC
*/
using namespace std;
int main() {
	fast;
	int t; cin >> t;
	while (t--) {
		string cmd; cin >> cmd;
		int n; cin >> n;
		char tmp; cin >> tmp;//���� [��ȣ
		deque<int>array;
		for (int i = 0; i < n; i++) {//���� ��ŭ ���� �ޱ�
			int number;
			cin >> number;
			if (i != n - 1)cin >> tmp;
			array.push_back(number);
		}
		cin >> tmp;//������ ��ȣ
		bool r = true, err = false;


		for (auto& command : cmd) {
			if (command == 'R') {
				r = !r;//�ڱ� �ڽ��� �Ųٷ� �ٲ۴�.
			}
			else {//D�϶�
				if (array.empty()) {
					cout << "error" << endl;
					err = !err;
					break;
				}
				if (r) {
					array.pop_front();
				}
				else {
					array.pop_back();
				}
			}
		}
		if (err)continue;
		cout << '[';
		int idx = array.size();
		for (int i = 0; i < idx; i++) {
			if (r) {//�պ��� ���
				cout << array.front();
				array.pop_front();
			}
			else {
				cout << array.back();
				array.pop_back();
			}
			if (i != idx - 1) {
				cout << ',';
			}
		}
		cout << ']' << endl;
	}
}