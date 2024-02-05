#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/27869
   27869�� aFan Event Planning

   1. ������ ���Ѵ�.
   2. �ʱ�ȭ��¥�� �����Ѵ�.
   3. s..e������ �ʱ�ȭ ��¥�� ������ e�� ���� ����� �ʱ�ȭ ��¥�� ���Ѵ�.
   s<=--lower_bound(e) //
   1..3

   start= max(start,s);
   s..e
   1..4 5 << �� ���Ͻÿ�
   cout <<prefix[e] - prefix[start-1] << endl;
   4. prefix[e] - 0 << endl �� �Ѵ�.

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
            auto lastDay = --deleteDay.lower_bound(e);//(lastday���� �ϳ� ���� ���� ���� �������� ���� �ֱ� �ʱ�ȭ ��¥)
            cout << prefix[e] - prefix[max(*lastDay, s - 1)] << endl;
        }
    }
    return 0;
}
