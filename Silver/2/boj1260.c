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
    https://www.acmicpc.net/problem/1260
    1260번 DFS와 BFS
*/
typedef struct vector {
    int *arr;
    int size;
    int capacity;
} vector;
void init(vector *src) {
    src->arr = (int *)malloc(sizeof(int) * 8);
    src->size = 0;
    src->capacity = 8;
}
void resize(vector *src) {
    int newCapacity = src->capacity + 8;
    src->arr = (int *)realloc(src->arr, sizeof(int) * newCapacity);
    src->capacity = newCapacity;
}
void push_back(vector *src, int item) {
    if (src->size == src->capacity) resize(src);
    src->arr[src->size++] = item;
}

typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} Node, *pnode;

typedef struct Queue {
    pnode front;  //
    pnode back;
    int size;  // 사이즈
} Queue;
void qinit(Queue *src) {
    src->front = NULL;
    src->back = NULL;
    src->size = 0;
}
void push(Queue *src, void *item) {
    pnode temp = (pnode)malloc(sizeof(Node));
    temp->data = (int *)item;
    if (!src->size) {
        src->front = temp;
        src->back = temp;
    } else {
        src->back->next = temp;
        temp->prev = src->back;
        src->back = temp;
    }
    src->size++;
}
pnode pop(Queue *src) {
    if (src->size == 0) return NULL;
    pnode ret = src->front;
    if (src->size == 1) {
        src->back = NULL;  // 없애주기
    }
    if (src->front) {
        src->front = src->front->next;
    }
    src->size--;
    return ret;
}
int n, m, v;
vector *graph;
void inputs() {
    scanf("%d %d %d", &n, &m, &v);
    graph = (vector *)malloc(sizeof(vector) * (n + 1));
    for (int i = 1; i <= n; i++) {
        init(&graph[i]);
    }
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        push_back(&graph[a], b);
        push_back(&graph[b], a);
    }
}
int compare(void *a, void *b) {
    return *((int *)a) > *((int *)b);
}
bool visited[1002];
void dfs(int cur) {
    visited[cur] = true;
    printf("%d ", cur);
    for (int i = 0; i < graph[cur].size; i++) {
        int next = graph[cur].arr[i];
        if (visited[next]) continue;
        dfs(next);
    }
}
void bfs(int cur) {
    memset(visited, 0, sizeof(bool) * (n + 1));
    Queue *q = (Queue *)malloc(sizeof(Queue));
    qinit(q);
    push(q, &cur);
    visited[cur] = true;
    while (q->size) {
        pnode ret = pop(q);
        int cur = *((int *)ret->data);
        printf("%d ", cur);
        for (int i = 0; i < graph[cur].size; i++) {
            int *next = &graph[cur].arr[i];
            if (visited[*next]) continue;
            push(q, next);
            visited[*next] = true;
        }
    }
}
void solve() {
    // 일단 모든 정점 소트 먼저
    for (int i = 1; i <= n; i++) {
        qsort(graph[i].arr, graph[i].size, sizeof(int), compare);
    }
    dfs(v);
    printf("\n");
    bfs(v);
}
int main() {
    inputs();
    solve();
    return 0;
}