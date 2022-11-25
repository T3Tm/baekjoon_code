#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/2900
	프로그램
	즉 2까지 더한값
	N-1더한 값 , N까지 더한 값을 갖고 있을 거임.
	그랬을 때 1씩 뛴다는 것은 
	1 , 2, N-1,N
	void something(int jump){
		int i=0;
		while (i<N){//0번 칸 부터 jump칸 씩 띄어서 더하기 1 하기.
			a[i]+=1;
			i+=jump;
		}
	}
*/
vector<int>callValue;
vector<long long>arr;
int n, k;
void something(int jump,int cnt) {//같이 구해주면 큰일남.
	int i = 0;
	while (i < n) {
		arr[i]+=cnt;
		i += jump;
	}
}
int main() {
	fast;
	//배열 크기, 호출 횟수;
	cin >> n >> k;
	arr.resize(n);
	callValue.resize(n);
	 // 이게 구간합 arr이라고 생각해보자.
	for (int i = 0; i < k; i++) {// 10^6
		int idx;
		cin >>idx;
		callValue[idx]++;
	}
	for (int i = 1; i < n; i++) {
		if (callValue[i]) {
			something(i, callValue[i]);
		}
	}
	for (int i = 1; i < n; i++) {
		arr[i] += arr[i - 1];
	}
	//여기서 구간합 다 구하기 10^6
	int q;
	//확인할 횟수
	cin >> q;
	while (q--) {
		int l, r;//L,R 구간합 O(1) 가능
		cin >> l >> r;
		l = l - 1;
		if (l == -1)cout << arr[r] << endl;
		else cout << arr[r] - arr[l] << endl;//O(1)으로 출력 가능.
	}
	return 0;
}