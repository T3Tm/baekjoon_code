#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/2003
   2003번 수들의 합 2

   투포인터 문제.
*/
using namespace std;
int n, m;
int arr[10002];
int main() {
	fast;
	cin >> n >> m;
	int left = 0, right = 0;
	for (int i = 0; i < n; i++)cin >> arr[i];
	long long my_m = arr[0];//초깃값 설정
	long long cnt = 0;
	while (left <= right) {
		if (my_m >= m) {//크거나 같으면 빼줘서 다른 쌍들이 나올 수 있도록
			if (my_m == m)cnt++;
			my_m -= arr[left++];//left를 늘리기 전에 값을 빼준다
		}
		else {//m보다 작기 때문에 right를 하나씩 늘리면서 sum에 누적
			right++;//더이상 right를 늘리지 못하면 그냥 끝을 내야함. 안 그래도 작은데 right를 못 늘리니 끝이지.
			if (right >= n)break;
			my_m += arr[right];
		}
		if (left > right) {
			swap(left, right);
			left++;
			if (right >= n)break;
			my_m += arr[right];
		}
	}
	cout << cnt;
	return 0;
}

