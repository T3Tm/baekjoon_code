#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int n,m;
bool break_point[10];

typedef struct newtype{
    int v;
    bool button;//버튼을 눌러서 된 건지 아니면 +된건지 확인.
}newtype;

typedef struct node{
    struct newtype x;//
    struct node* next;//다음 노드 가리키기
}node;

typedef struct queue{//front,pop,size,empty,push
    node* front;//처음에 연결
    node* back;//마지막에 바로 연결
    long long size;
}queue;

void init(queue* q){
    q->front=NULL;
    q->back=NULL;
    q->size=0;
}

void push(queue *q,newtype v){//qush하려면
    node* new_node = (node *)malloc(sizeof(node));
    new_node->x.v=v.v;
    new_node->x.button = v.button;
    new_node->next=NULL;
    if(!q->front){//아무것도 가리키고 있지 않을때
        q->front = new_node;
        q->back = new_node;
    }else{//front가 있으면 back만 바꿔주면 된다.
        q->back->next=new_node;//다음을 변경하고/
        q->back=new_node;//마지막 노드 변경하기.
    }
    q->size++;//사이즈 하나 증가
}
node* front(queue *q){
    node* ret=NULL;
    ret=q->front;
    return ret;
}

void pop(queue * q){//젤 앞에 값 빼기
    node* front_node = q->front;//front 갖고 오기
    q->front = q->front->next;//다음으로 포인터 옮겨주기.
    free(front_node);//날려주기.
    q->size--;
}
long long size(queue * q){
    return q->size;
}
bool empty(queue *q){
    return q->size==0;
}
int dx[] = {1,-1};
int visited[1111111][2]={};
int bfs(){
    queue *q=(queue *)malloc(sizeof(queue));
    init(q);
    newtype insert={100,0};
    push(q,insert);//초기에 100 넣기
    memset(visited,-1,sizeof(visited));
    visited[100][0]=0;
    for(int i=0;i<=9;i++){
        if(break_point[i])continue;
        newtype insert={i,1};
        push(q,insert);visited[i][1]=1;//첨에 버튼 한 번 누르면 되는 것들.
    }
    while(!empty(q)){//비어있지 않을 때까지
        node* cur = front(q);
        node temp;
        temp.x.v=cur->x.v;
        temp.x.button=cur->x.button;
        pop(q);
        cur = &temp;
        if(cur->x.v == n)return visited[n][cur->x.button];
        for(int i=0;i<=9;i++){//채널 번호 옆에 갖다 붙이기.
            if(break_point[i])continue;//망가져서 사용 불가.
            int nx= cur->x.v*10+i;
            if(nx < 0 || nx>=1000000)continue;
            if(visited[nx][1]!=-1 || !cur->x.button)continue;
            visited[nx][1] = visited[cur->x.v][1]+1;
            newtype insert={nx,1};
            push(q,insert);
        }
        for(int i=0;i<2;i++){
            int nx = cur->x.v+dx[i];
            if(nx < 0 || nx>=1000000)continue;
            if(visited[nx][0]!=-1)continue;
            visited[nx][0]=visited[cur->x.v][cur->x.button]+1;
            newtype insert={nx,0};
            push(q,insert);
        }
    }
    return -1;
}
main(){scanf("%d %d",&n,&m);
    for(int i=0,t;i<m;i++)scanf("%d",&t),break_point[t]=1;
    printf("%d",bfs());
}