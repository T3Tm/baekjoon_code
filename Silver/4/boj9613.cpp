#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
/*
  https://www.acmicpc.net	/problem/9613
  9613�� GCD ��
*/
using namespace std;
int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        long long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += gcd(arr[i], arr[j]);
            }
        }
        cout << sum << endl;
    }
    return 0;
}