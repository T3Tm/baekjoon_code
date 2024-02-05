#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define MAXVALUE 1000001
using namespace std;
/*
        https://www.acmicpc.net/problem/9489
        사촌

        첫 번째 정수는 트리의 루트 노드이다.
        다음에 등장하는 연속된 수의 집합은 루트의 자식들인데
        집합에 첫 번째 수는 항상 루트 노드+1 보다 크다.
        arr[0]+1 > 이거여야함. (같다 아님)

        그 다음 부터는 모든 연속된 수의 집합은 아직 자식이 없는
        노드의 자식이 된다.
        집합은 수가 연속하지 않는 곳에서 구분된다. << 이거

        두 노드의 부모는 다르지만 < 부모가 다르다 즉 형제 노드는 안됨
        형제 노드가 아니면서  < 트리의 층수가 같으면 안됨.
        두 부모가 형제 일때 <<

        형제노드라는 것은== 부모가 같다는 거임

*/
// 트리에서 문제 해독해서 풀은 코드(690ms)
vector<int> graph;  // 앞에는 부모, 뒤에는 자식 갯수 세기
vector<int> visited;
int n, k, answer;
int main() {
    fast;
    while (1) {
        cin >> n >> k;
        answer = 0;
        if (n == 0 && k == 0) break;
        graph.assign(MAXVALUE, 0);  // 부모나 자식이 없으면 -1
        int front = 1, end = 2;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        arr.push_back(arr[n - 1]);  // 마지막에서 무조건 끊기 위해
        int parent = 0;
        for (int i = 1; i < n; i++) {
            graph[arr[i]] = arr[parent];  // 부모 노드 설정
            if (arr[i] + 1 < arr[i + 1]) {
                parent++;
            }
        }
        arr.pop_back();
        if (graph[graph[k]]) {  // 부모의 부모가 존재할 때
            for (auto node : arr) {
                if (graph[graph[node]] == graph[graph[k]] && graph[k] != graph[node]) {
                    answer++;
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}

// 재귀식으로 코드 자식 노드 갯수 세주기 (2960ms)
int n, k;
int count(int cur) {  // 부모가 들어왔을 때 -1이면 말도 안됨.
    if (cur == -1) return 0;
    visited[cur] = 0;
    int child = 0;
    for (auto next : {cur - 1, cur + 1}) {           //-1이랑 +1 중에서 가기
        if (next < 1 || next >= MAXVALUE) continue;  // 인덱스 범위 넘어가면 안됨.
        if (visited[next]) child += count(next);
    }
    if (cur != graph[k].first) child += graph[cur].second;
    return child;
}
int main() {
    fast;
    while (1) {
        cin >> n >> k;
        if (n == 0 && k == 0) break;
        graph.assign(MAXVALUE, pair<int, int>(-1, 0));  // 부모나 자식이 없으면 -1
        visited.assign(MAXVALUE, 0);
        int front = 1, end = 2;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            visited[arr[i]] = 1;  // 이 숫자가 있다는 것을 확인하기 위해
        }
        arr.push_back(MAXVALUE + 1);  // 마지막에서 무조건 끊기 위해
        int parent = arr[0];          // 부모님 0번 노드
        int parentidx = 1;
        int prev = -1;
        if (end < n) prev = arr[front];
        while (end <= n) {
            if (prev + 1 != arr[end]) {                  // 여기서 숫자 끊어주기.
                while (front != end) {                   // front에서 end까지 오면서 부모노드 설정해주기
                    graph[arr[front++]].first = parent;  // 자식의 부모를 설정
                    graph[parent].second++;              // 부모의 자식을 세기
                }
                parent = arr[parentidx++];  // 부모 노드 바꿔주기.
            }
            prev = arr[end];
            end++;
        }
        cout << count(graph[k].first) << endl;
        // 그래프 결성 완료
    }
    return 0;
}