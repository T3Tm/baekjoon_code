#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/9536
	9536�� ����� ��� ����?
*/
using namespace std;
set<string>weeping;
int main() {
	int t; cin >> t;
	while (t--) {
		string weep;
		cin.ignore();
		getline(cin, weep);//�� �� �Է� �ޱ�.
		weep.push_back(' ');
		while (1) {
			string a, b, c;
			cin >> a >> b >> c;
			if (b == "does") {//the������ �Է� �޾����Ƿ� fox say���� �޾ƾߵ�.
				cin >> a >> b;
				break;
			}
			weeping.insert(c);
		}
		string tmp;
		for (auto& value : weep) {
			if (value == ' ') {
				if (weeping.find(tmp) == weeping.end()) {
					cout << tmp << ' ';
				}
				tmp.clear();
				continue;
			}
			tmp.push_back(value);
		}
	}
	return 0;
}