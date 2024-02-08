#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -a)
#define FOR(i, j) for (int i = 0; i < j; i++)
typedef long long ll;
/*
    https://www.acmicpc.net/problem/7576
    7576번 토마토
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
int m, n;
int zero;
int **board;
int **visited;
void inputs() {
    scanf("%d %d", &m, &n);
    board = (int **)malloc(sizeof(int *) * n);
    visited = (int **)malloc(sizeof(int *) * n);
    FOR(i, n) {
        board[i] = (int *)malloc(sizeof(int) * (m + 1));
        visited[i] = (int *)malloc(sizeof(int) * (m + 1));
        FOR(j, m) {
            scanf("%d", &board[i][j]);
            if (!board[i][j])
                zero++;
            visited[i][j] = -1;
        }
    }
}
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int bfs() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init(q);
    FOR(i, n) {
        FOR(j, m) {
            if (board[i][j] == 1) {
                Pair *loc = (Pair *)malloc(sizeof(Pair));
                loc->x = i;
                loc->y = j;
                push(q, loc);
                visited[loc->x][loc->y] = 0;
            }
        }
    }
    int res = zero ? -1 : 0;
    while (q->size) {
        pnode ret = pop(q);
        Pair *cur = (Pair *)ret->element;
        FOR(i, 4) {
            Pair *next = (Pair *)malloc(sizeof(Pair));
            next->x = cur->x + dx[i];
            next->y = cur->y + dy[i];
            if (next->x < 0 || next->x >= n || next->y < 0 || next->y >= m) continue;
            if (visited[next->x][next->y] != -1 || board[next->x][next->y] == -1) continue;
            visited[next->x][next->y] = visited[cur->x][cur->y] + 1;
            push(q, next);
            zero--;
            if (!zero) {
                res = visited[next->x][next->y];
            }
        }
        free(cur);
        free(ret);
    }
    free(q);
    return res;
}
void solve() {
    printf("%d", bfs());
}
int main() {
    inputs();
    solve();
    return 0;
}