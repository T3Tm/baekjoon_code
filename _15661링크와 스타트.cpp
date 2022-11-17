#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
    https://www.acmicpc.net/problem/15661
    링크와 스타트
    N명이 모였다.
    팀에 속한 애들끼리 능력치를 더하면된다.
    {1,2,3},{4,5}
    12 ,23 ,13
    한 조를 고르게 되면 다른 한 조는 무조건 정해져 있게 된다.
    그럼 한 조를 무조건 고르게 해보자.
*/
int n;
vector<vector<int>>graph;
int SUM(vector<int>&arr){
    int result = 0;
    if (arr.size() >= 2) {
        vector<int>pick(arr.size() - 2, 0);
        for (int i = 0; i < 2; i++)pick.push_back(1);
        do {
            int flag=1;
            int i, j;
            for (int idx = 0; idx < arr.size(); idx++) {
                if (pick[idx]) {
                    if (flag) {
                        i = arr[idx];
                        flag = 0;
                    }
                    else j = arr[idx];
                }
            }
            result += graph[i][j] + graph[j][i];
        } while (next_permutation(pick.begin(), pick.end()));
    }
    return result;
}
int main() {
    fast;
    cin >> n;
    graph.resize(n,vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    int result = INT_MAX;
    for (int j = 1; j <= n / 2; j++) {
        vector<int>pick(n - j, 0);
        for (int i = 0; i < j; i++)pick.push_back(1);
        do {
            int startpoint, linkpoint;
            vector<int>start;
            vector<int>link;
            for (int idx = 0; idx < n; idx++) {
                if (pick[idx])start.push_back(idx);
                else link.push_back(idx);
            }//조가 결성됐음.
            startpoint = SUM(start);
            linkpoint = SUM(link);
            result = min(result, abs(startpoint - linkpoint));
        } while (next_permutation(pick.begin(), pick.end()));
    }
    cout << result;
    return 0;
}