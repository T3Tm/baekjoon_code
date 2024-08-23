#include <bits/stdc++.h>
using namespace std;
int distance(const pair<int, int> &a, const pair<int, int> &b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n; n += 2;
        vector<pair<int, int>> arr(n);
        for (auto &[x, y] : arr)
            cin >> x >> y;

        
        queue<int>q;
        bool visited[103]{1};

        q.push(0);//정점, 갯수
        bool flag{};
        while(!q.empty()){
            auto cur = q.front();q.pop();
            if(cur == n-1){
                flag = 1;break;
            }
            for(int i=1;i<n;i++){//n개
                if(visited[i])continue;
                int dist = distance(arr[cur], arr[i]);
                int cnt = dist/50;
                if(dist %50)cnt++;

                if(cnt > 20)continue;//못 감
                visited[i] = 1;
                q.push(i);
            }
        }
        if(flag){
            cout << "happy\n";
        }else{
            cout << "sad\n";
        }
    }
    return 0;
}