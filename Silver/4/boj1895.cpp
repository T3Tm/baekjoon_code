#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/1895
   1895번 필터

   무조건 5번째
*/
using namespace std;
int r, c, t, cnt;
int arr[42][42];
int main() {
    fast;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> t;
    for (int i = 0; i + 3 <= r; i++) {//3*4 = 12번 분할 
        for (int j = 0; j + 3 <= c; j++) {//4
            int bit[256] = { 0 };//count sort
            for (int z = 0; z < 3; z++) {
                for (int w = 0; w < 3; w++) {
                    bit[arr[i + z][j + w]]++;
                }
            }
            int order = 0;
            int value = -1;
            for (int p = 0; p < 256; p++) {
                order += bit[p];
                if (order >= 5) {
                    value = p;
                    break;
                }
            }
            if (t <= value)cnt++;
        }
    }
    cout << cnt;
    return 0;
}