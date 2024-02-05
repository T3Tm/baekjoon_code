#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/10811
    10811번 바구니 뒤집기
*/
using namespace std;
int n, m;
int arr[102];
void reversed(int x, int y) {
    for (int i = 0; i < (y-x+1)/2; i++) {
        swap(arr[x+i], arr[y - i]);
    }
}
int main() {
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) arr[i] = i;
    while (m--) {
        int i, j;
        cin >> i >> j;
        reversed(i, j);
    }
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    return 0;
}