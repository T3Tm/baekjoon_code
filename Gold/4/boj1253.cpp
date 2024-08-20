#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v : a)
    {
        cin >> v;
    }

    // 1 2 3 4 5 6 7 8 9 10
    sort(a.begin(), a.end());
    int result{};
    for (int i = 0; i < n; i++)
    {
        // arr[i]를 만들 것임.
        int left{}, right = n - 1;
        if (left == i)
            left++;
        else if (right == i)
            right--;

        while (left < right)
        {
            int now = a[left] + a[right];
            if (now == a[i])
            {
                result++;
                break;
            }
            if (now < a[i])
            {
                left++;
            }
            else
            {
                right--;
            }

            if (left == i)
                left++;
            else if (right == i)
                right--;
        }
    }

    cout << result;

    return 0;
}