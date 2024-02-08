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
    https://www.acmicpc.net/problem/1261
    1261번 알고스팟
*/
int n, m;
char **board;
int visited[2][102][102];  // 0은 안 부셧을 때 1은 부셨을 때
typedef struct Tuple {
    int x, y;
    bool fire;
} Tuple;
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
void inputs() {
    scanf("%d %d", &m, &n);
    board = (char **)malloc(sizeof(char *) * n);
    FOR(i, n) {
        board[i] = (char *)malloc(sizeof(char) * (m + 1));
        scanf("%s", board[i]);

        memset(visited[0][i], -1, sizeof(int) * (m + 1));
        memset(visited[1][i], -1, sizeof(int) * (m + 1));
    }
}
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int bfs() {
    Tuple t = {0, 0, 0};
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init(q);
    push(q, &t);
    visited[0][0][0] = 0;
    while (q->size) {
        pnode ret = pop(q);
        Tuple *now = (Tuple *)ret->element;
        FOR(i, 4) {
            Tuple *next = (Tuple *)malloc(sizeof(Tuple));
            next->x = now->x + dx[i];
            next->y = now->y + dy[i];
            if (next->x < 0 || next->x >= n || next->y < 0 || next->y >= m) continue;
            next->fire = board[next->x][next->y] - '0';
            if (visited[next->fire][next->x][next->y] != -1) {
                if (visited[next->fire][next->x][next->y] <= visited[now->fire][now->x][now->y] + next->fire) continue;
            }
            visited[next->fire][next->x][next->y] = visited[now->fire][now->x][now->y] + next->fire;
            push(q, next);
        }
    }
    return visited[0][n - 1][m - 1];
}
void solve() {
    printf("%d", bfs());
}
int main() {
    inputs();
    solve();
    return 0;
}