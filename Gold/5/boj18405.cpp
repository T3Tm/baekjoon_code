#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int arr[202][202]{};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int s, X, Y;
    cin >> s >> X >> Y;

    queue<pair<int, int>> q;
    pair<int, int> visited[202][202];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            visited[i][j] = {0x3f3f3f3f, -1};
            if (arr[i][j])
            {
                q.push({i, j});
                visited[i][j] = {0, arr[i][j]};
            }
        }
    }

    int dx[]{0, 0, 1, -1};
    int dy[]{1, -1, 0, 0};
    for (int i = 0; i < s; i++)
    {
        queue<pair<int, int>> nextq;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int i{}; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > n)
                    continue;
                if (visited[nx][ny].second == -1)
                {
                    visited[nx][ny] = {visited[x][y].first + 1, visited[x][y].second};
                    nextq.push({nx, ny});
                }
                else if (visited[nx][ny].first == visited[x][y].first + 1)
                {
                    visited[nx][ny].second = min(visited[nx][ny].second, visited[x][y].second);
                }
            }
        }
        q = nextq;
    }

    cout << (visited[X][Y].first == 0x3f3f3f3f ? 0 : visited[X][Y].second);
    return 0;
}