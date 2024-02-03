#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    boj1707
    1. dfs 돌면서 방문 표시를 달리 표현한 뒤에
    2. 재방문 시 나와 같은 집합인지 확인
*/

typedef struct vector{
    int* data;//데이터 공간
    int size;
    int capacity;
} vector;

void init(vector *graph){
    for(int i=1;i<=20000;i++){
        graph[i].data = (int *)malloc(sizeof(int) * 32);
        graph[i].size = 0;
        graph[i].capacity = 32;
    }
}

void resize(vector *graph){
    //배열 vector의 크기를 2배로 늘림
    int newSize = graph->capacity * 2;
    graph->data =(int *)realloc(graph->data, sizeof(int) * newSize);
    graph->capacity = newSize;
}

void push_back(vector* graph, int item){
    if(graph->size >= graph->capacity) resize(graph);
    //lastOfVector 증가시킨뒤 vector[lastOfVector]에 item 대입
    graph->data[graph->size++] = item;
}

int visited[20002];
vector graph[20002];
char result[] = "YES";
void dfs(int cur, int visitValid)
{
    visited[cur] = visitValid; // 이 값으로 방문 찍기
    for (int i = 0; i < graph[cur].size; i++)
    { //
        int next = graph[cur].data[i];
        if (visited[next] == -1)
        { // 이미 방문 한
            dfs(next, !visitValid);
        }
        else if (visited[next] != !visited[cur])
        { // 방문 했었는데, 다른 정점으로 가네? 그럼 불가능
            strcpy(result, "NO");
        }
    }
}
int main()
{
    int k;
    scanf("%d", &k);
    int v, e;
    while (k--){
        scanf("%d %d", &v, &e);
        memset(visited, -1, sizeof visited);
        init(&graph);
        strcpy(result, "YES");

        for (int i = 0, x, y; i < e; i++)//그래프 연결
        {
            scanf("%d %d", &x, &y);
            push_back(&graph[x],y);
            push_back(&graph[y],x);
        }
        for(int i=1;i<=v;i++){//방문 안 한 것들 다 돌아주기
            if(visited[i]!=-1)continue;
            dfs(i,0);
        }

        printf("%s\n", result);
    }
    return 0;
}
