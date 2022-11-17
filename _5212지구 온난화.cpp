#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
    https://www.acmicpc.net/problem/5212
    지구 온난화
    
*/
deque<pair<int, int>>earth;
int r, c;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int visited[11][11];
void globalWarming(vector<vector<char>>&graph) {
    vector<pair<int,int>>check;
    for(auto loc:earth){
        int x = loc.first, y = loc.second; // 어차피 뽑는 것들이 다 섬일 거임
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= r || nx < 0 || ny >= c || ny < 0) {
                visited[x][y]++;//지금 인덱스 넘어가는 곳도 물임.
                continue;
            }
            if (graph[nx][ny] == 'X')continue;//인접한 곳이 섬이면 continue
            visited[x][y]++;//물이고, 인덱스 범위 안 넘어가는 곳임 그곳이 .으로 돼있음
        }
        //3칸 이상 바다가 있었음 잠겨버림 땅 잠겨야함.
        if (visited[x][y] >= 3)check.push_back({ x,y });
    }
    for (auto loc : check) {//물로 바뀜
        int x = loc.first, y = loc.second;
        graph[x][y] = '.';
    }
    int min_x=11, max_x=-1, min_y=11, max_y=-1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (graph[i][j] == 'X') {
                //섬일 때
                max_x = max(max_x, i);
                max_y = max(max_y, j);
                min_x = min(min_x, i);
                min_y = min(min_y, j);
            }
        }
    }
    for (int i = min_x; i <= max_x; i++) {
        for (int j = min_y; j <= max_y; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
}
int main() {
    fast;
    cin >> r >> c;
    vector<vector<char>>graph(r,vector<char>(c,' '));
    for (int i = 0; i < r; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < c; j++) {
            if (temp[j] == 'X')earth.push_back({ i,j });
            graph[i][j]=temp[j];
        }
    }
    globalWarming(graph);
    return 0;
}