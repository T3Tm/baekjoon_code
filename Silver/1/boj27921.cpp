#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/27921
	27921�� ���� ����
	
*/
using namespace std;
int h1, w1;
int h2, w2;
int arr[32][32];
struct loc {
	int x, y;
};
vector<loc>Loc;
int answer = 0;
int maxvalue = 0;

int main() {
	fast;
	cin >> h1 >> w1;
	for (int i = 0; i < h1; i++) {//ù����
		string temp;
		cin >> temp;
		for (int j = 0; j < w1; j++) {
			if (temp[j] == 'O') {
				arr[i][j] = 1;
				Loc.push_back({ i,j });
			}
		}
	}
	cin >> h2 >> w2;
	for (int i = 10; i < h2+10; i++) {//�ι�°
		string temp;
		cin >> temp;
		for (int j = 0; j < w2; j++) {
			if (temp[j] == 'O') {
				arr[i][j+10] = 1;
				answer++;
			}
		}
	}

	//h1,w1 �ִµ�, w1�� 30�� �����ߴٸ�?
	int column = 1;
	while(!Loc.empty()){//���ʿ� Loc�� �ƹ��͵� �� ������� ���� �ִ�.
		bool down = false;
		bool isexit = false;
		for (auto& value : Loc) {//��� ��ǥ���ֱ�
			arr[value.x][value.y]--;
		}
		int cnt = 0;
		for (auto& value : Loc) {//��ǥ �� ���� ��������
			arr[value.x][value.y + column]++;//column ��ŭ ���ؼ� 
			if (arr[value.x][value.y + column] == 2)cnt++;//���� ĭ�� ���� 2�̸� check
 			value = { value.x,value.y + column };//���� column��ŭ �����༭ �����
			if (value.y == 30)down = true;//���� �����ʿ� �ִ� ���� 30�� �����ߴٸ�?
			if (value.y == 0)down = true;//���� ���ʿ� �ִ� ���� 0�� �����ߴٸ�?
		}
		if (down) {
			for (auto& value : Loc) {//������ �� �� 
				arr[value.x][value.y]--;//���� �� ����
				value = { value.x + 1,value.y };//�� ĭ ������ �����ֱ�.
				arr[value.x][value.y]++;
				if (value.x == 30)isexit = true;//������ ����
			}
			column *= -1;//������ ����.
		}
		maxvalue = max(maxvalue, cnt);
		if (isexit)break;
	}
	cout << answer - maxvalue;
	return 0;
}