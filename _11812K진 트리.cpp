#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	logkn = logn/logk
*/
unsigned long long n;
int k, q;
int main() {
	fast;
	cin >> n >> k >> q;
	while (q--) {//10만
		unsigned long long x, y;
		cin >> x >> y;
		//x와 y의 높이를 일단 구해보자.
		if (x > y)swap(x, y);
		int high_x =0;//50
		int high_y = 0;//50
		unsigned long long count = 0;
		if (k != 1) {
			unsigned long long nx = x, ny = y;
			while (nx != 1) {//50번
				nx = (nx + k - 2) / k;
				high_x++;
			}
			while (ny != 1) {//50번
				ny = (ny + k - 2) / k;
				high_y++;
			}
		
			// 높이를 바꾸자. 둘이 높이를 일단 맞춰주자.
			//y가 무조건 더 깊은 걸로 해보자.
			while (high_x!=high_y) {//0번
				high_y--;
				count++;
				y = (y + k - 2) / k;
			}
			//높이 맞춰줬음
			// 같은 부모 만나보자.
			while (x != y) {
				x = (x + k - 2) / k;
				y = (y + k - 2) / k;
				count+=2;
			}
		}
		else {
			count = y - x;
		}
		cout << count << endl;
		//같은 부모를 만날 때까지 만남.
	}
}