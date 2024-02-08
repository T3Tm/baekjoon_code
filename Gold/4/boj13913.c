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
    https://www.acmicpc.net/problem/13913
    13913번 숨바꼭질 4
*/
int n, k;
int memo[100002];
int visited[100002];
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
    scanf("%d %d", &n, &k);
    memset(memo, -1, sizeof(int) * 100001);
}
int bfs() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    memset(visited, -1, sizeof(int) * 100001);
    init(q);
    push(q, &n);
    visited[n] = 0;
    while (q->size) {
        pnode ret = pop(q);
        int *cur = (int *)ret->element;
        if (*cur == k) {
            return visited[*cur];
        }
        int *next = (int *)malloc(sizeof(int) * 3);
        next[0] = *cur + 1;
        next[1] = *cur - 1;
        next[2] = *cur * 2;
        for (int i = 0; i < 3; i++) {
            if (next[i] < 0 || next[i] > 100000) continue;
            if (visited[next[i]] != -1) continue;
            visited[next[i]] = visited[*cur] + 1;  // 전에 어느지점에서 왔는지 체크
            memo[next[i]] = *cur;                  // 어느 지점에서 왔는지 체크
            push(q, &next[i]);
        }
    }
}
typedef struct Stack {
    pnode top;
    int size;
} Stack;
void sinit(Stack *src) {
    src->top = NULL;
}
void spush(Stack *src, void *element) {
    pnode temp = (pnode)malloc(sizeof(Node));
    temp->element = element;
    if (src->size) {
        temp->prev = src->top;
    }
    src->top = temp;
    src->size++;
}
pnode spop(Stack *src) {
    if (!src->size) return NULL;
    pnode ret = src->top;
    src->top = src->top->prev;
    src->size--;
    return ret;
}

void tracking() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    sinit(s);
    spush(s, &k);
    int cur = k;
    while (1) {
        int *prev = &memo[cur];
        if (*prev == -1) break;
        spush(s, prev);
        cur = *prev;
    }
    while (s->size) {
        printf("%d ", *((int *)spop(s)->element));
    }
}
void solve() {
    printf("%d\n", bfs());
    tracking();
}
int main() {
    inputs();
    solve();
    return 0;
}