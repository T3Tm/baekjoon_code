#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/19844
	단어 개수 세기
	
	기본적으로 띄어쓰기나 - 단위로 단어를 구분한다.

	ce,je,ne,me,te,se,le,la,de,que,si 이고 뒤 단어가 모음(a,e,i,o,u,h)으로 시작하는 경우, 단어의 마지막 모음이 사라지고 '가 붙음
	
	c,j,n,m,t,s,l,d,qu < 이거 일 때 ' 이게 나오면 단어 하나 증가 아니면 그냥 continue
*/
using namespace std;
int answer;
int main() {
	fast;
	string word;
	getline(cin, word);
	word.push_back(' ');
	string temp;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == '-' || word[i] == ' ') {
			answer++;
			temp.clear();
			continue;
		}
		else if (word[i] == '\'') { //
			bool f = true;
			for (auto vowel : { 'a','e','i','o','u','h' }) {
				if (word[i + 1] == vowel) {
					f = false;
					break;
				}
			}
			if (f)continue;
			if (temp.size() == 1) {
				bool flag = false;
				for (auto check : { 'c','j','n','m','t','s','l','d' }) {
					if (temp[0] == check) {
						flag = true;
						break;
					}
				}
				if (flag) {
					answer++;
					temp.clear();
					continue;
				}
			}
			else if (temp.size() == 2) {
				if (temp == "qu") {
					answer++;
					temp.clear();
					continue;
				}
			}
		}
		temp.push_back(word[i]);
	}
	cout << answer;
	return 0;
}