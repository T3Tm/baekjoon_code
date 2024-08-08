#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    set<int> up;
    set<int, greater<int>> down; //

    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int nums;
        cin >> nums;

        auto it = down.lower_bound(nums - m);
        if (it != down.end())
            result.push_back(nums - *it);

        auto iter = up.lower_bound(nums + m);
        if (iter != up.end())
            result.push_back(*iter - nums);
        
        down.insert(nums);
        up.insert(nums);
    }

    sort(result.begin(),result.end());

    cout << result[0];
    return 0;
}