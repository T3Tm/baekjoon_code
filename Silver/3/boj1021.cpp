#include<bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
  https://www.acmicpc.net/problem/1021
  1021번 회전하는 큐
  1. pop_front 가능
  2. left_rotate
  3. right_rotate
  2번 뽑고 9번 뽑고 5번 뽑는다?
  left_rotate 1번
  1,2,3,4,5,6,7,8,9,10
  2,3,4,5,6,7,8,9,10,1
  3,4,5,6,7,8,9,10,1
  오른쪽 3번, 왼쪽
*/
using namespace std;
int n, k;
long long answer;
deque<int>values;
int left_rotateCnt(int number) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (values[i] == number)break;
        cnt++;
    }
    return cnt;
}
int right_rotateCnt(int number) {
    int cnt = 0;
    int backsize = (int)values.size();
    for (int i = 0; i < backsize; i++) {
        cnt++;
        if (values[backsize - i - 1] == number)break;
    }
    return cnt;
}
int main() {
    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)values.push_back(i);

    for (int i = 0; i < k; i++) {
        int number;
        cin >> number;
        int Left = left_rotateCnt(number);
        int Right = right_rotateCnt(number);
        if (Left >= Right) {
            answer += Right;
            for (int i = 0; i < Right; i++) {
                auto backvalue = values.back(); values.pop_back();
                values.push_front(backvalue);
            }
            values.pop_front();
        }
        else {
            answer += Left;
            for (int i = 0; i < Left; i++) {
                auto frontvalue = values.front(); values.pop_front();
                values.push_back(frontvalue);
            }
            values.pop_front();
        }
    }
    cout << answer;
    return 0;
}