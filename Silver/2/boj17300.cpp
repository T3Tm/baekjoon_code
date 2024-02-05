#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17300
	17300�� ����
	1. ���� next�� ����.
	2. �湮�ߴ� �������� Ȯ���Ѵ�.
	3. �湮 �� �ߴ� �����̸� ����.
	4. �湮üũ �ϰ� 2������ ���ư���.
*/
using namespace std;
struct loc {
	int x, y;
};//1,2 -> 2,0
map<int, loc>convert = { {1,{0,0}},{2,{0,1}},{3,{0,2}},
	{4,{1,0}},{5,{1,1}},{6,{1,2}},
	{7,{2,0}},{8,{2,1}},{9,{2,2}} };
int n;
int arr[12];
bool visited[5][5];
bool pattern(int start, int depth) {
	bool true_false = true;
	if (n == depth) {//
		return true_false;
	}
	auto pre = convert[start];
	visited[pre.x][pre.y] = true;//�̹� �湮����.
	auto next = convert[arr[depth]];
	if (!visited[next.x][next.y]) {//�湮 �� ���� ��
		if (pre.x == next.x) {//���η� ������ ��
			if (abs(next.y - pre.y) == 1) {//1ĭ�̳׿�
				true_false = pattern(arr[depth], depth + 1);//�׳� ���� ��.
			}
			else if (abs(next.y - pre.y) == 2) {//2ĭ �� ���ߵ�. �߰� �� ó�� ����ߵ�. //�߰��� �������� Ȯ��
				if (visited[next.x][max(pre.y - 1, next.y - 1)]) {//�߰����� �̹� �湮�߾��� �ִϱ� ������.
					true_false = pattern(arr[depth], depth + 1);
				}
				else {//�߰� �ְ� �湮 �� ������ 
					return false;
				}
			}
		}
		else if (pre.y == next.y) {//���η� ������ ��
			if (abs(next.x - pre.x) == 1) {//1ĭ�̳׿�
				true_false = pattern(arr[depth], depth + 1);//�׳� ���� ��.
			}
			else if (abs(next.x - pre.x) == 2) {//2ĭ �� ���ߵ�. �߰� �� ó�� ����ߵ�. //�߰��� �������� Ȯ��
				if (visited[max(next.x - 1, pre.x - 1)][next.y]) {//�߰����� �̹� �湮�߾��� �ִϱ� ������.
					true_false = pattern(arr[depth], depth + 1);
				}
				else {//�߰� �ְ� �湮 �� ������ 
					return false;
				}
			}
		}
		else {//�밢������ ������ ��
			if (abs(pre.x - next.x) + abs(pre.y - next.y) == 4) {//�߰� ó��
				if (visited[max(next.x - 1, pre.x - 1)][max(pre.y - 1, next.y - 1)]) {
					true_false = pattern(arr[depth], depth + 1);
				}
				else {//�߰� �ָ� �� ������.
					return false;
				}
			}
			else {//2�� ,3 �� �׳� ���� ��. �߰� ó�� �� ���൵ ��.
				true_false = pattern(arr[depth], depth + 1);
			}
		}
	}
	else {//�̹� ���� ��.
		return false;
	}
	return true_false;
}
int main() {//�ش��ϴ� �ּҿ� 
	fast;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	cout << (pattern(arr[0], 1) ? "YES" : "NO");
	return 0;
}