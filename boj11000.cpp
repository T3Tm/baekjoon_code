#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/11000
	11000�� ���ǽ� ����
	s�� �����ؼ� t�� ������ ������ N���� �ִ�.
	�ּ��� ���ǽ��� ����ؼ� ��� ������ �����ϰ� �ض�.
	�׷� ���ǽ� ���� �� �� ���� ���� �Ŵϱ�
	�� �����ٸ��ؼ� ���ǽ��� �������� ���� ���� �ų�?
	������ ���� ���� �ٷ� ���� ���� ���� T<=S �̸� �ٷ� �ȴٴ� ��.


	������ �ð��� �������� �������� ������ �����Ѵ�.
	�� ���� 
	
	
	
*/
using namespace std;
struct Time{
	int s, t;
	static bool cmp(const Time& a, const Time& b) {
		return a.t < b.t;
	}
	bool operator()(const Time& a, const Time& b) {
		return a.t > b.t;
	}
};

int n;
long long answer=1;
Time arr[200002];
int main() {
	fast; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].s >> arr[i].t;
	}
	sort(arr, arr + n, Time::cmp);//������ �ð� ��������
	priority_queue<Time, vector<Time>, Time>lecture;
	for (int i = 0; i < n; i++) {//������ �ð��� ���� ������ �ð����� ũ�� �׳� ������
		while(!lecture.empty()&&lecture.top().t<=arr[i].s) {
			lecture.pop();
		}
		lecture.push(arr[i]);
		answer = max(answer, (long long)lecture.size());
	}
	cout << answer;
	return 0;
}