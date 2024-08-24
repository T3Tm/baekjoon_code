#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> arr(n);

    for (auto &v : arr)
        cin >> v;

    sort(arr.begin(), arr.end());

    int start = 0;
    int i{};
    for (; i < n; i++)
    {
        // 각 나올 수 있는 모든 지점들
        // 1, 1, 2, 3, 6, 7, 30
        // start [start+1 <= x <= end]
        int end = arr[i] + start; // 1
        if (start + 1 < arr[i])
        {
            // 불가능
            start = start + 1;
            break;
        }

        start = end;
    }
    if (i == n) start++;
    cout << start;
    return 0;
}