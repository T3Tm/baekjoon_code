#include<bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
  https://www.acmicpc.net/problem/1449
  1449번 수리공 항승
*/
using namespace std;
int n, l;
int arr[1002];
int main() {
    fast;
    cin >> n >> l;
    for (int i = 0; i < n; i++)cin >> arr[i];
    sort(arr, arr + n);
    int start = arr[0], answer = 1;
    for (int i = 1; i < n; i++) {
        if (start + l <= arr[i]) {
            answer++;
            start = arr[i];
        }
    }
    cout << answer;
    return 0;
}