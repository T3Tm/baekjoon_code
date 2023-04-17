#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/3425
	3425�� ����

	NUM X: X�� ������ ���� ���� �����Ѵ�. (0 �� X �� 109)
	POP: ���� ���� ���� ���ڸ� �����Ѵ�.
	INV: ù ��° ���� ��ȣ�� �ٲ۴�. (42 -> -42)
	DUP: ù ��° ���ڸ� �ϳ� �� ������ ���� ���� �����Ѵ�.
	SWP: ù ��° ���ڿ� �� ��° ������ ��ġ�� ���� �ٲ۴�.
	ADD: ù ��° ���ڿ� �� ��° ���ڸ� ���Ѵ�.
	SUB: ù ��° ���ڿ� �� ��° ���ڸ� ����. (�� ��° - ù ��°)
	MUL: ù ��° ���ڿ� �� ��° ���ڸ� ���Ѵ�.
	DIV: ù ��° ���ڷ� �� ��° ���ڸ� ���� ���� �����Ѵ�. �� ��° ���ڰ� ������, ù ��° ���ڰ� �����̴�.
	MOD: ù ��° ���ڷ� �� ��° ���ڸ� ���� �������� �����Ѵ�. �� ��° ���ڰ� ������, ù ��° ���ڰ� �����̴�.
*/
using namespace std;
#define DONT 1000000000
bool Isempty(stack<long long>& nums) {
	if (nums.empty()) {
		cout << "ERROR" << endl;
		return true;
	}
	return false;
}
void handling(stack<long long>& nums, vector<string>& query) {
	for (auto cmd : query) {
		if (cmd[0] == 'N')nums.push(stoi(cmd.substr(4)));
		else if (cmd[0] == 'I') {
			if (!Isempty(nums)) {//�������
				auto v = -nums.top(); nums.pop();
				nums.push(v);
			}
			else return;
		}
		else if (cmd[0] == 'P') {
			if (!Isempty(nums))nums.pop();
			else return;
		}
		else if (cmd[0] == 'D') {
			if (cmd[1] == 'U') {
				if (!Isempty(nums))nums.push(nums.top());
				else return;
			}
			else {//div
				if (nums.size() >= 2) {
					auto v = nums.top(); nums.pop();
					auto v1 = nums.top(); nums.pop();
					if (v == 0) {
						cout << "ERROR" << endl;
						return;
					}
					else {//������ ��
						int mul = 1;
						if (v1 < 0)mul *= -1;//�� �� �ϳ��� �����̸� ������ ����
						if (v < 0) mul *= -1;
						//���� ����ġ�� 1�� ���ؾߵǴ��� -1�� ���ؾߵǴ��� ����.
						nums.push(mul * (abs(v1) / abs(v)));//������
					}
				}
				else {
					cout << "ERROR" << endl;
					return;
				}
			}
		}
		else if (cmd[0] == 'S') {//SWP , SUB �Ѵ� ����.
			if (nums.size() >= 2) {
				if (cmd[1] == 'U') {
					auto v = nums.top(); nums.pop();
					auto v1 = nums.top() - v; nums.pop();
					if (abs(v1) > DONT) {
						cout << "ERROR" << endl;
						return;
					}
					nums.push(v1);
				}
				else {//SWP ��ġ �ٲٱ�.
					auto v = nums.top(); nums.pop();
					auto v1 = nums.top(); nums.pop();
					nums.push(v); nums.push(v1);
				}
			}
			else {
				cout << "ERROR" << endl;
				return;
			}
		}
		else if (cmd[0] == 'A') {
			if (nums.size() >= 2) {
				auto v = nums.top(); nums.pop();
				auto v1 = nums.top() + v; nums.pop();
				if (abs(v1) > DONT) {//���� ����.
					cout << "ERROR" << endl;
					return;
				}
				nums.push(v1);
			}
			else {
				cout << "ERROR" << endl;
				return;
			}
		}
		else if (cmd[0] == 'M') {//���Ѵ�.
			if (cmd[1] == 'U') {
				if (nums.size() >= 2) {
					auto v = nums.top(); nums.pop();
					auto v1 = nums.top() * v; nums.pop();
					if (abs(v1) > DONT) {
						cout << "ERROR" << endl;
						return;
					}
					nums.push(v1);
				}
				else {
					cout << "ERROR" << endl;
					return;
				}
			}
			else {//mod ����
				if (nums.size() >= 2) {
					auto v = nums.top(); nums.pop();
					auto v1 = nums.top(); nums.pop();
					if (v == 0) {
						cout << "ERROR" << endl;
						return;
					}
					else {
						int mul = 1;
						if (v1 < 0)mul *= -1;//�� �� �ϳ��� �����̸� ������ ����
						//���� ����ġ�� 1�� ���ؾߵǴ��� -1�� ���ؾߵǴ��� ����.
						nums.push(mul * (abs(v1) % abs(v)));
					}
				}
				else {
					cout << "ERROR" << endl;
					return;
				}
			}
		}
	}
	if (nums.size() == 1)cout << nums.top() << endl;
	else cout << "ERROR" << endl;
}
int main() {
	fast;
	while (1) {
		vector<string>query;//���� ����.
		while (1) {//���� �����ϱ�.
			string cmd; getline(cin, cmd);
			if (cmd[0] == 'Q')goto EXIT;//QUIT �ϸ� �����ߵ�.
			else if (cmd[0] == 'E')break;//���� ���峡.
			query.push_back(cmd);//
		}
		int n; cin >> n;//�ʱ� �� �Է�
		for (int i = 0; i < n; i++) {
			stack<long long>nums;
			int number; cin >> number;
			nums.push(number);
			handling(nums, query);
		}
		cout << endl;
	}
EXIT:
	return 0;
}