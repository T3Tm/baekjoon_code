#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/14003
	14003번 가장 긴 증가하는 부분 수열 5 

	10 10000 11 12 13 14 15 16 17 18 19 10001 이렇게 있다면
	          1번 인덱스로 들어가야된다. 2번으로 들어가야된다?
	10001 보다 작은 아이들 중 가장 큰 값을 바로 알아낼 수 있을까?
	현재 있던 값들 중에서 가장 큰 값이라는 것은 max_value에서 +1 해서 넣어주면 되지 않나

	이러면 max_value를 같이 갖고 가야됨. 맞네

	지금 마지막에 넣는다는 것은 최대로 갖고 온 값에다가 +1 해서 dp에 저장해갖고 하면됨..

	그러면 마지막으로 젤 큰 값에 저장된 v 값도 있어야함. 그래야 prev를 설정할 수 있음
	

	1번에 넣어야 되는데 1번에 넣어야 되면
	upper_bound해서 보면 되는데


*/
using namespace std;
int n;
vector<int>arr{  -1000000001 };
unordered_map<int, pair<int, int>>prevalue{ {-1000000001,{0,-1}} };//0과 idx
vector<pair<int, int>>idxs;//해당 하는 숫자들의 v과 idx를 저장.
int main() {
	fast; cin >> n;
	idxs.resize(n);
	int max_value = 0;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		auto it = lower_bound(arr.begin(), arr.end(), num);
		if (it == arr.end()) {
			it--;
			auto [v, idx] = prevalue[*it];
			prevalue[num] = { v + 1,i };
			idxs[i] = { arr.back(),prevalue[arr.back()].second };//이전 값 저장.
			arr.push_back(num);
		}
		else if ((*it) >= num) {//수가 갱신되는지만 확인
			auto& inner =  *it;
			it--;//이전 수에서 갖고 오자
			if (prevalue[(*it)].first > prevalue[inner].first|| (prevalue[(*it)].first + 1 == prevalue[inner].first && inner > num)) {//수가 갱신될 수 있으므로 변경
				inner = num;
				prevalue[num] = { prevalue[(*it)].first+ 1 ,i };
				idxs[i] = {*it,prevalue[*it].second};
			}
		}
	}
	cout << prevalue[arr.back()].first << endl;
	vector<int>result{arr.back()};
	auto last = idxs[prevalue[arr.back()].second];
	while (last.first != -1000000001) {
		result.push_back(last.first);
		last = idxs[last.second];
	}
	for (auto it = result.rbegin(); it != result.rend(); it++) {
		cout << (*it) << ' ';
	}
	return 0;
}