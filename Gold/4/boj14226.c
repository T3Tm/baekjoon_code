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
    https://www.acmicpc.net/problem/14226
    14226번 이모티콘
*/
int s;
int visited[2500][2500];  // i에 j만큼 복사한 경우
void inputs() {
    scanf("%d", &s);
}

typedef struct Pair {
    int copy;   // 얼마나 복사됐는지
    int count;  // 현재 갯수
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
int bfs() {
    Pair t = {0, 1};
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init(q);
    push(q, &t);
    for (int i = 0; i < 2500; i++) {
        memset(visited[i], -1, sizeof(int) * 2500);
    }
    visited[t.count][t.copy] = 0;
    while (q->size) {
        pnode ret = pop(q);
        Pair *now = (Pair *)ret->element;
        if (now->count == s) {
            return visited[now->count][now->copy];
        }
        Pair *t;
        if (now->copy != 0 && now->count + now->copy <= 2000 && visited[now->count + now->copy][now->copy] == -1) {  // 붙여넣기 가능
            visited[now->count + now->copy][now->copy] = visited[now->count][now->copy] + 1;
            t = (Pair *)malloc(sizeof(Pair));
            t->copy = now->copy;
            t->count = now->count + now->copy;
            push(q, t);
        }
        /* 복사 */
        if (visited[now->count][now->count] == -1) {
            visited[now->count][now->count] = visited[now->count][now->copy] + 1;
            t = (Pair *)malloc(sizeof(Pair));
            t->copy = now->count;
            t->count = now->count;
            push(q, t);
        }
        /* 삭제 */
        if (now->count - 1 >= 0 && visited[now->count - 1][now->copy] == -1) {
            visited[now->count - 1][now->copy] = visited[now->count][now->copy] + 1;
            t = (Pair *)malloc(sizeof(Pair));
            t->copy = now->copy;
            t->count = now->count - 1;
            push(q, t);
        }
    }
}
void solve() {
    printf("%d", bfs());
}
int main() {
    inputs();
    solve();
    return 0;
}