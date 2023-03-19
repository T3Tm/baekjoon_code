#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/27869
   27869번 aFan Event Planning

   1. 구간합 구한다.
   2. 초기화날짜를 저장한다.
   3. s..e구간에 초기화 날짜가 있으면 e에 가장 가까운 초기화 날짜를 구한다.
   s<=--lower_bound(e) //
   1..3

   start= max(start,s);
   s..e
   1..4 5 << 합 구하시오
   cout <<prefix[e] - prefix[start-1] << endl;
   4. prefix[e] - 0 << endl 를 한다.

*/
using namespace std;
set<int>deleteDay = { 0 };
int n, q;
long long prefix[200003];
int main() {
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int d;
            cin >> d;
            deleteDay.insert(d);
        }
        else {
            int s, e;
            cin >> s >> e;
            auto lastDay = --deleteDay.lower_bound(e);//(lastday보다 하나 작은 값을 통해 구간에서 제일 최근 초기화 날짜)
            cout << prefix[e] - prefix[max(*lastDay, s - 1)] << endl;
        }
    }
    return 0;
}
