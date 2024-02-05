#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
* https://www.acmicpc.net/problem/18115
* 18115�� ī�� ����
* ���� ���� ī�� 1���� �ٴڿ� ���� ���´�.
* �ι�° ī�� ���Ť����� (2�� �̻��϶���)
* ���� �ؿ� �ִ� ī�� �ٴڿ� ���� (2�� �̻��϶���)
* 
* 1~n �ߺ� ����
* ��� N�� ���
*/
using namespace std;
int n;
int arr[1000002];
vector<int>result;
int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int second = 1,end=n-1,first=0;
	result.resize(n);
	int insertNum = n;
	for (int i = 0; i <n; i++) {
		if (arr[i] == 1) {
			result[first++] = insertNum;
			if (first<n && result[first]) {//
				first = second++;
			}
			else if (first == second)second++;
		}
		else if (arr[i] == 2) {
			result[second++] = insertNum;
		}
		else {
			result[end--] = insertNum;
		}
		insertNum--;
	}
	for (auto it : result)cout << it << ' ';
	return 0;
}