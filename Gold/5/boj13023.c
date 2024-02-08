#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -a)
typedef long long ll;
/*
    https://www.acmicpc.net/problem/13023
    13023번 ABCDE
    0 -> 1 -> 2 -> 3
    0    1    2    3
         1 -> 4
    0 -> 3 -> 2 -> 1 -> 4
*/
int n, m;
typedef struct vector {
    int* arr;
    int size;
    int capacity;
} vector;
void resize(vector* src) {
    int newCapacity = src->capacity + 8;
    src->arr = (int*)realloc(src->arr, sizeof(int) * newCapacity);
    src->capacity = newCapacity;
}
void push_back(vector* src, int item) {
    if (src->size == src->capacity) resize(src);
    src->arr[src->size++] = item;
}
void init(vector* src) {
    src->arr = (int*)malloc(sizeof(int));
    src->size = 0;
    src->capacity = 1;
}
vector* graph;
void inputs() {
    scanf("%d %d", &n, &m);
    graph = (vector*)malloc(sizeof(vector) * (n + 1));
    for (int i = 0; i <= n; i++) {
        init(&graph[i]);
    }
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        push_back(&graph[a], b);
        push_back(&graph[b], a);
    }
}
void dfs(int cur, int depth, bool visited[]) {  // 현재 정점으로부터 최대 깊이를 알아낸 다음에 그 값을 토대로 다른 값이랑 비교했을 시 된다면 flag를 true로 바꿔주기
    if (depth >= 5) {
        printf("1");
        exit(0);
    }

    for (int i = 0; i < graph[cur].size; i++) {
        int next = graph[cur].arr[i];
        if (visited[next]) continue;  // 방문 했으면 넘어가기
        visited[next] = true;
        dfs(next, depth + 1, visited);
        visited[next] = false;  //
    }
}
void solve() {
    for (int i = 0; i < n; i++) {  // 아무 정점부터 시작해봅시두~
        bool visited[2002] = {};
        visited[i] = true;
        dfs(i, 1, visited);
        visited[i] = false;
    }
    printf("0");
}
int main() {
    inputs();
    solve();
    return 0;
}