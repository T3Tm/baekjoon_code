#include <bits/stdc++.h>
using namespace std;
/*
    A ~ Z
    1 ~ 26
    a ~ z
    27 ~ 52

    10920
*/
int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string s, result = "";
    cin >> s;
    vector<vector<int>> v(10);
    for (int i = 0; i < n; i++)
    {
        v[s[i] - '0'].push_back(i);
    }
    int K = k;
    int now = -1;
    while (k > 0 && result.size() != n - K)
    {
        for (int i = 9; i >= 0; i--)
        {
            auto iter = upper_bound(v[i].begin(), v[i].end(), now);

            if (iter == v[i].end())
                continue;
            if (*iter - now - 1 <= k)
            {
                k -= *iter - now - 1;
                result.push_back(i + '0');
                now = *iter;
                break;
            }
        }
    }
    now++;
    while (now < n && result.size() != n - K)
    {
        result.push_back(s[now++]);
    }
    cout << result;
    return 0;
}