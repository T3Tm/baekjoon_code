#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1052
	1052번 물병
	N개의 물병이 있고 물을 무한대로 부을 수 있다.
	모든 물병에는 물이 1L 있음.
	한 번에 K개의 물병을 옮길 수 있다.

	1. 같은 양의 물이 들어있는 물병 두 개를 고른다. 그 다음 한 개의 물병에
	다른 한 쪽에 있는 물을 모두 붓는다. (이 방법을 필요한 만큼 계속 한다.)

	n,k 있을 때
	n>k일때만 계속 하면 되는 거네?
	if n%2 이면 1개 빼고 n/=2 하면 된다. 그다음 +1 하면됨.
	아니면 n/=2;
	3 이면
	1  이 되겠다.
	남은
*/
using namespace std;
long long answer;
vector<long long>modwater;//남은 물들
int main() {
	fast;
	int n, k; cin >> n >> k;
	long long water = 1;//현재 물의 정보 담기.
	while (n) {
		if (n % 2) {
			modwater.push_back(water);//나머지 물은 그냥 빼놓기.
			n = (n - 1) / 2;//젤 작은 것이 1L 이다. 중간 중간 낙오자 물들이 몇인지 알아야 될듯.
		}
		else n /= 2;
		water <<= 1;//2배 돼야한다. 
	}
	// modwater[i]-modwater[i-1]개 필요함. 
	if (modwater.size() > k) {//그럼 mod에 있는 물들을 적당히 배치해서 k로 만들어줘야함.
		long long len = modwater.size();
		long long watercnt = len;
		for (int i = 1; i < len && watercnt>k; i++) {//i+1번째
			answer += modwater[i] - modwater[i - 1];//1의 갯수 더해주기
			modwater[i] <<= 1;//2배해주기.//3개에서 2개됐음.
			watercnt--;//한 번 시행되면 2개가 1개가 됨.
		}
	}
	cout << answer;
	return 0;
}