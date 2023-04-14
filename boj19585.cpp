#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/19585
	19585번 전설
*/
using namespace std;
int c, n, q;

const int ROOT = 1;
int unused1 = 2;
const int MX = 1000 * 4000 + 5; // 최대 등장 가능한 글자의 수
bool chk1[MX];
int nxt1[MX][26];//color

int unused2 = 2;
bool chk2[MX];
int nxt2[MX][26];//name

int c2i(char c) {
	return c - 'a';
}

void insert(string& s, int nxt[][26], int& unused, bool chk[]) {
	int cur = ROOT;
	for (auto c : s) {
		if (nxt[cur][c2i(c)] == 0)
			nxt[cur][c2i(c)] = unused++;
		cur = nxt[cur][c2i(c)];
	}
	chk[cur] = true;
}

vector<int> find(string& s, int nxt[][26], bool chk[],bool front) {//
	vector<int>ret;
	int cur = ROOT;
	for (int i = 0; i < 1100 && i < (int)s.size(); i++) {//
		int j = (front ? i : (int)s.size() - i - 1);
		auto c = s[j];
		if (chk[cur]) {//
			ret.push_back(i);
		}//blu , blue
		else if (nxt[cur][c2i(c)] == 0) {
			return ret;
		}
		cur = nxt[cur][c2i(c)];//0 -1
	}
	return ret;
}
void solve() {//
	cin >> q;
	while (q--) {//20000
		string tmp; cin >> tmp;
		auto i1 = find(tmp, nxt1, chk1,1);//idx 갖고 오기.
		//color 트라이
		if (i1.size()>=1) {
			auto i2 = find(tmp, nxt2, chk2,0);//idx갖고 오기.
			for (auto& value : i1) {
				for (auto& v2 : i2) {
					if (value + v2 == (int)tmp.size()) {
						cout << "Yes" << endl;
						goto EXIT;
					}
				}
			}
		}
		cout << "No" << endl;
	EXIT:;
	}
}
int main() {
	fast;
	cin >> c >> n;
	for (int i = 0; i < c; i++) {//c 4000
		string tmp; cin >> tmp;
		insert(tmp, nxt1, unused1, chk1);//|S| 1000
	}
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		reverse(tmp.begin(), tmp.end());
		insert(tmp, nxt2, unused2, chk2);
	}
	solve();
	return 0;
}