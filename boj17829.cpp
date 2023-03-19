#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/17829
   17829번 222-풀링
   1. 2*2 정사각형으로 나눈다.
   2. 각 정사각형에서 2번쨰로 큰 수만 남긴다.
*/
using namespace std;
int n;
vector<vector<int>>arr;
int divide(int depth, vector<vector<int>>& arr, int i, int j) {
    if (depth == 2) {
        vector<int>temp = { arr[i][j] ,arr[i][j - 1] ,arr[i - 1][j - 1] ,arr[i - 1][j] };
        sort(temp.begin(), temp.end());
        return temp[2];
    }

    int f1 = divide(depth / 2, arr, i - (depth / 4), j - (depth / 4));
    int f2 = divide(depth / 2, arr, i - (depth / 4), j + (depth / 4));
    int f3 = divide(depth / 2, arr, i + (depth / 4), j - (depth / 4));
    int f4 = divide(depth / 2, arr, i + (depth / 4), j + (depth / 4));
    vector<int>temp = { f1 ,f2 ,f3 ,f4 };
    sort(temp.begin(), temp.end());
    return temp[2];
}
int main() {
    fast;
    cin >> n;
    arr.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << divide(n, arr, n / 2, n / 2);
    return 0;
}
