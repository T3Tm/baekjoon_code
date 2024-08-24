#include <bits/stdc++.h>
using namespace std;
/*
    이번 문제 : 2458번


*/
const int INF = 0x3f3f3f3f;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    int arr[502][502];
    memset(arr, 0x3f, sizeof arr);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;

                if (arr[i][k] + arr[k][j] < arr[i][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        arr[i][i] = 0;
    }

    int shorts[502]{};
    int longs[502]{};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || arr[i][j] == INF)
                continue;
            shorts[j]++;
            longs[i]++;
        }
    }

    int ans{};
    for (int i = 1; i <= n; i++)
    {
        if (shorts[i] + longs[i] == n - 1)
        {
            ans++;
        }
    }

    cout << ans;
    return 0;
}