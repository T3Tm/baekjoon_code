#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
/*
    https://www.acmicpc.net/problem/12906
    12906번 새로운 하노이 탑
*/
unordered_map<string, int> visited;
int a, b, c;
string q="", w="", e="";
void inputs() {
    cin >> a;
    if(a) cin >> q;
    cin >> b;
    if(b)cin >> w;
    cin >> c;
    if(c)cin >> e;
}
struct hanoi {
    string a, b, c;
};
int bfs() {
    int cnt[]{0, 0, 0};
    for (auto c : q + w + e) {
        cnt[c - 'A']++;
    }
    hanoi temp{q, w, e};
    visited[q + " " + w + " " + e] = 0;
    queue<hanoi> q;
    q.push(temp);
    while (!q.empty()) {
        auto [a, b, c] = q.front();
        q.pop();
        // a 위에 막대 옮기기
        // b 위에 막대 옮기기
        // c 위에 막대 옮기기
        string prev = a + " " + b + " " + c;
        if (!a.empty()) {
            string copa(a);
            char back = copa.back();
            copa.pop_back();
            hanoi next = {copa, b + back, c};
            if (visited.find(next.a + " " + next.b + " " + next.c) == visited.end()) {
                visited[next.a + " " + next.b + " " + next.c] = visited[prev] + 1;
                q.push(next);
            }
            next.b = b;
            next.c += back;
            if (visited.find(next.a + " " + next.b + " " + next.c) == visited.end()) {
                visited[next.a + " " + next.b + " " + next.c] = visited[prev] + 1;
                q.push(next);
            }
        }
        if (!b.empty()) {
            string copa(b);
            char back = copa.back();
            copa.pop_back();
            hanoi next = {a + back, copa, c};
            if (visited.find(next.a + " " + next.b + " " + next.c) == visited.end()) {
                visited[next.a + " " + next.b + " " + next.c] = visited[prev] + 1;
                q.push(next);
            }
            next.a = a;
            next.c += back;
            if (visited.find(next.a + " " + next.b + " " + next.c) == visited.end()) {
                visited[next.a + " " + next.b + " " + next.c] = visited[prev] + 1;
                q.push(next);
            }
        }
        if (!c.empty()) {
            string copa(c);
            char back = copa.back();
            copa.pop_back();
            hanoi next = {a + back, b, copa};
            if (visited.find(next.a + " " + next.b + " " + next.c) == visited.end()) {
                visited[next.a + " " + next.b + " " + next.c] = visited[prev] + 1;
                q.push(next);
            }
            next.a = a;
            next.b += back;
            if (visited.find(next.a + " " + next.b + " " + next.c) == visited.end()) {
                visited[next.a + " " + next.b + " " + next.c] = visited[prev] + 1;
                q.push(next);
            }
        }
    }
    string end = "";
    end.append(cnt[0],'A');
    end.append(" ");
    end.append(cnt[1],'B' );
    end.append(" ");
    end.append(cnt[2],'C');
    return visited[end];
}
void solve() {
    cout << bfs();
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    inputs();
    solve();
    return 0;
}