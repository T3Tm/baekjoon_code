#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
    https://www.acmicpc.net/problem/13164
    행복 유치원
    유치원 N명을 K조로 나눈다.
    줄을 끊으면 됨.
    gap을 갖고 와서 최소가 되려면 최대가 되는 gap을 빼고
    다 더하면 된다.
    예를 들어) 1 10001 10002 이렇게면
    10000, 1 이기 때문에
    2개의 조로 나누면 10000 이 gap을 끊어야 최소가 될 수 있다.
    줄 i개를 끊으면 조는 i+1개씩 생김
    1개 -> 1+1
    2개 -> 2+1 
    n=5 k=3 이라면
    gap은 4개가 나올 것이고
    줄을 1개를 끊으면 2조
    2개 끊으면 3조
    3개 끊으면 4조가 생김
    

    이걸 반대로 그럼 다른 것들을 줄을 이어야하므로 이어야하는 것을 몇 번 반복해야 되냐면
    i가 0부터 n-i이 k가 될 때까지 반복하면 된다.
    그럼 자동으로 나머지 gap들은 끊기게 된다.
    그리고 이어준 줄은 result에 저장해서 출력한다.
*/
int main() {
    fast;
    int n, k;
    cin >> n >> k;
    vector<int>arr(n, 0);
    vector<int>gap;
    for (int i = 0; i < n; i++)cin >> arr[i];
    for (int i = 1; i < n; i++) {
        gap.push_back(arr[i]-arr[i-1]);
    }
    sort(gap.begin(), gap.end());
    int result = 0;
    for (int i = 0; (n-i) != k; i++) {
        result += gap[i];
    }
    cout << result;
    return 0;
}