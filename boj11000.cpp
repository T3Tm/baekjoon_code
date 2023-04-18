#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/11000
	11000번 강의실 배정
	s에 시작해서 t에 끝나는 수업이 N개가 있다.
	최소의 강의실을 사용해서 모든 수업을 가능하게 해라.
	그럼 강의실 여러 개 안 쓰면 좋은 거니까
	잘 스케줄링해서 강의실을 연속으로 쓰면 좋은 거네?
	수업이 끝난 직후 바로 다음 수업 가능 T<=S 이면 바로 된다는 것.


	끝나는 시간을 기준으로 오름차순 정렬을 진행한다.
	그 다음 
	
	
	
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
	sort(arr, arr + n, Time::cmp);//끝나는 시간 오름차순
	priority_queue<Time, vector<Time>, Time>lecture;
	for (int i = 0; i < n; i++) {//끝나는 시간이 지금 시작할 시간보다 크면 그냥 괜찮음
		while(!lecture.empty()&&lecture.top().t<=arr[i].s) {
			lecture.pop();
		}
		lecture.push(arr[i]);
		answer = max(answer, (long long)lecture.size());
	}
	cout << answer;
	return 0;
}