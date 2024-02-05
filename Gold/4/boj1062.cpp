#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1062
	1062�� ����ħ
	k�� 0 �Ǵ� 26���� �۰ų� ����
	antic
	acnti
*/
using namespace std;
int n, k, result;
bool avail[26];
vector<string>words;
bool available(string& temp) {
	for (int i = 4; i < (int)temp.size() - 4; i++) {//7
		if (avail[temp[i] - 'a'] == false)return false;
	}
	return true;
}
void teach(int depth, int idx) {//21������
	if (depth == k - 5) {
		int cnt = 0;
		for (auto& word : words) {//50��
			cnt += available(word);
		}
		result = max(result, cnt);
		return;
	}
	for (int i = idx; i < 26; i++) {//26��
		if (!avail[i]) {
			avail[i] = true;
			teach(depth + 1, i + 1);
			avail[i] = false;
		}
	}
}
int main() {
	fast;
	cin >> n >> k;
	while (n--) {
		string temp;
		cin >> temp;
		words.push_back(temp);
	}
	if (k >= 5) {
		avail['a' - 'a'] = true;
		avail['c' - 'a'] = true;
		avail['n' - 'a'] = true;
		avail['t' - 'a'] = true;
		avail['i' - 'a'] = true;
		teach(0, 0);
	}
	cout << result;

	return 0;
}