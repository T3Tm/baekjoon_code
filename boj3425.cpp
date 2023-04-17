#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/3425
	3425번 고스택

	NUM X: X를 스택의 가장 위에 저장한다. (0 ≤ X ≤ 109)
	POP: 스택 가장 위의 숫자를 제거한다.
	INV: 첫 번째 수의 부호를 바꾼다. (42 -> -42)
	DUP: 첫 번째 숫자를 하나 더 스택의 가장 위에 저장한다.
	SWP: 첫 번째 숫자와 두 번째 숫자의 위치를 서로 바꾼다.
	ADD: 첫 번째 숫자와 두 번째 숫자를 더한다.
	SUB: 첫 번째 숫자와 두 번째 숫자를 뺀다. (두 번째 - 첫 번째)
	MUL: 첫 번째 숫자와 두 번째 숫자를 곱한다.
	DIV: 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
	MOD: 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
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
			if (!Isempty(nums)) {//비었으면
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
					else {//나뉘는 거
						int mul = 1;
						if (v1 < 0)mul *= -1;//둘 중 하나가 음수이면 무조건 음수
						if (v < 0) mul *= -1;
						//둘을 지나치면 1을 곱해야되는지 -1을 곱해야되는지 나옴.
						nums.push(mul * (abs(v1) / abs(v)));//나누기
					}
				}
				else {
					cout << "ERROR" << endl;
					return;
				}
			}
		}
		else if (cmd[0] == 'S') {//SWP , SUB 둘다 있음.
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
				else {//SWP 위치 바꾸기.
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
				if (abs(v1) > DONT) {//에러 났음.
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
		else if (cmd[0] == 'M') {//곱한다.
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
			else {//mod 연산
				if (nums.size() >= 2) {
					auto v = nums.top(); nums.pop();
					auto v1 = nums.top(); nums.pop();
					if (v == 0) {
						cout << "ERROR" << endl;
						return;
					}
					else {
						int mul = 1;
						if (v1 < 0)mul *= -1;//둘 중 하나가 음수이면 무조건 음수
						//둘을 지나치면 1을 곱해야되는지 -1을 곱해야되는지 나옴.
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
		vector<string>query;//쿼리 저장.
		while (1) {//쿼리 저장하기.
			string cmd; getline(cin, cmd);
			if (cmd[0] == 'Q')goto EXIT;//QUIT 하면 나가야됨.
			else if (cmd[0] == 'E')break;//쿼리 저장끝.
			query.push_back(cmd);//
		}
		int n; cin >> n;//초기 값 입력
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