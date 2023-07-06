#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define min(a,b)(a>b?b:a)
#define max(a,b)(a>b?a:b)
/*
 https://www.acmicpc.net/problem/20437
 20437번 문자열 게임 2
*/
#define ll long long
typedef struct newtype{
    int idx;//자료형 새로 추가하면 된다.
}newtype;

typedef struct node{
    struct newtype x;//
    struct node* next;//다음 노드 가리키기
}node;

typedef struct queue{//front,pop,size,empty,push
    node* front;//처음에 연결
    node* back;//마지막에 바로 연결
    ll size;
}queue;

void init(queue* q){
    q->front=NULL;
    q->back=NULL;
    q->size=0;
}

void push(queue *q,newtype v){//qush하려면
    node* new_node = (node *)malloc(sizeof(node));

    new_node->x=v;//newtype으로 값 제대로 주기.

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
    q->size--;//사이즈 하나 줄여주기
}

ll size(queue * q){//사이즈 확인
    return q->size;
}

bool empty(queue *q){//비어있는지 확인
    return q->size==0;
}

int t,k;
char W[10002];
main(){scanf("%d",&t);
    while(t--){
        scanf("%s %d",W,&k);
        int alpha[26]={};
        queue *q = (queue *)malloc(sizeof(queue)*26);
        int maxlen=0,minlen=INT_MAX;
        for(int i=0;W[i];i++){
            newtype temp={i+1};
            push(&q[W[i]-'a'],temp);
            alpha[W[i]-'a']++;
            if(alpha[W[i]-'a']==k){
                node* t=front(&q[W[i]-'a']);
                int idx =t->x.idx;
                pop(&q[W[i]-'a']);
                alpha[W[i]-'a']--;
                maxlen=max(maxlen,i-idx+2);
                minlen=min(minlen,i-idx+2);
            }
        }
        if(maxlen)printf("%d %d\n",minlen,maxlen);
        else printf("-1\n");
    }
}
