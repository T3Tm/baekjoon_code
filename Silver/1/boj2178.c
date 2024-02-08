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
    https://www.acmicpc.net/problem/2178
    2178번 미로탐색
*/
typedef struct Pair {
    int x, y;
} Pair;
typedef struct Node {
    void *element;
    struct Node *next;
    struct Node *prev;
} Node, *pnode;
typedef struct Queue {
    pnode front;
    pnode back;
    int size;
} Queue;
void init(Queue *src) {
    src->back = NULL;
    src->front = NULL;
    src->size = 0;
}
void push(Queue *src, void *element) {
    pnode temp = (pnode)malloc(sizeof(Node));
    temp->element = element;
    if (!src->size) {
        src->front = temp;
    } else {
        src->back->next = temp;
        temp->prev = src->back;
    }
    src->back = temp;
    src->size++;
}
pnode pop(Queue *src) {
    if (!src->size) return NULL;
    pnode ret = src->front;
    if (src->size == 1) {
        src->back = NULL;
    }
    if (src->front) {
        src->front = src->front->next;
    }
    src->size--;
    return ret;
}
int n, m;
char **board;
void inputs() {
    scanf("%d %d", &n, &m);
    board = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (char *)malloc(sizeof(char) * (m + 1));
        scanf("%s", board[i]);
    }
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void bfs(int x, int y) {
    int visited[102][102] = {};
    visited[x][y] = 1;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init(q);
    Pair t = {x, y};
    push(q, &t);
    while (q->size) {
        pnode front = pop(q);
        Pair *loc = (Pair *)front->element;
        if (loc->x == n - 1 && loc->y == m - 1) {
            printf("%d", visited[loc->x][loc->y]);
            exit(0);
        }
        for (int i = 0; i < 4; i++) {
            Pair *next = (Pair *)malloc(sizeof(Pair));
            next->x = loc->x + dx[i];
            next->y = loc->y + dy[i];
            if (next->x < 0 || next->x >= n || next->y < 0 || next->y >= m) continue;
            if (visited[next->x][next->y] || board[next->x][next->y] == '0') continue;
            push(q, next);
            visited[next->x][next->y] = visited[loc->x][loc->y] + 1;
        }
        free(front);
    }
}
void solve() {
    bfs(0, 0);
}
int main() {
    inputs();
    solve();
    return 0;
}