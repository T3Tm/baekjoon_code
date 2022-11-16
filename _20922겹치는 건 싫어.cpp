#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
    https://www.acmicpc.net/problem/20922
    이전 인덱스를 갖고 왔을 떄 지금idx 사이에 만약 2개가 있는 수가 있을 때
    다음에 값을 어떻게 조정해야되지?
*/

int main(){
    int n, k;
    cin >> n >> k;
    vector<int>arr = vector<int>(n, 0);//40만
    for (int i = 0; i < n; i++) cin >> arr[i];
    int result = 0 ,front, end = front = 0;
    vector<int>save = vector<int>(100001, 0);
    while (end < n) {
        save[arr[end]]++;
        if (save[arr[end]]>k) {//k개 이상 나왔으면 front 땡겨주기
            while (save[arr[end]] > k) {
                save[arr[front++]]--;
            }
        }
        end++;
        result = max(result, end - front);
    }
    cout << result;
    return 0;
}