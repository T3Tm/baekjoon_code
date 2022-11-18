#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
    https://www.acmicpc.net/problem/22869
    징검다리 건너기 (small)
    N개의 돌이 일렬로 나열 되어 있다. N개의 돌에는 A1,A2,An으로 부여돼있다.
    가장 왼쪽 돌에서 시작해서 가장 오른쪽 돌으로 가려고 한다.
    

    1. 항상 오른쪽으로만 갈 수 있음

    2. i번째 돌에서 j번째 돌로 이동할 떄 (j-i) * (1+|Ai-Aj|)만큼 힘이 든다.

    3. 돌을 한 번 건너갈 때마다 쓸 수 있는 힘은 최대 K이다.

    i자리에서 j까지 갈 수 있으면 무조건 가는 것이 좋겠네
    그러면 이건 내가 봤을 때 dfs로 짜는 것이 좋을 것 같음
    result에 쌓아놓고 result는 1인지 0인지 확인하고 
    result 1이면 yes 출력하고
    0이면 no출력하면 되겠네 
    dfs로 갈 수 있는 경로 다 검색하고
*/
int result;
int n, k;
int visited[5001];
vector<int>strength;
void dfs(int cur) {//cur는 idx이다.
    if (cur == n - 1) {
        result = 1;
        return;
    }
    visited[cur] = 1;
    for (int idx = cur + 1; idx < n; idx++) {
        if (!visited[idx] && k>=((idx - cur)*(1+abs(strength[cur]-strength[idx])))) {
            dfs(idx);
        }
    }
}
int main() {
    fast;
    cin >> n >> k;
    strength.resize(n);
    for (int i = 0; i < n; i++)cin >> strength[i];
    dfs(0);
    if (result)cout << "YES";
    else cout << "NO";
    return 0;
}