#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0) -> ios::sync_with_stdio(0);
	int n;cin >> n;
	int arr[100002]{};
	for(int i=0;i<n;i++)cin >> arr[i];
	int a{-1000000001},b{-1000000001};
	
	sort(arr,arr+n);

	//1이면 -1보다 크거나 같은 것 찾기
	for(int i=0;i<n-1;i++){//i+1부터 n까지 찾기
		auto iter = lower_bound(arr+i+1,arr+n, -arr[i]) - arr;//인덱스
		if(iter == n){//
			iter--;	
		}

		if(arr[i] + arr[iter] == 0){
			a = arr[i];
			b = arr[iter];
		}
		else {
			if (iter != i+1 && abs(a+b) > abs(arr[i] + arr[iter-1])){
				a = arr[i];
				b = arr[iter-1];
			}

			if(abs(a+b) > abs(arr[i] + arr[iter])){
				a = arr[i];
				b = arr[iter];
			}
		}
	}
	cout << a << ' ' << b;
	return 0;
}