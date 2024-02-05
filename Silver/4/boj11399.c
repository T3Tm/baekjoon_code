#include <stdlib.h>
/*
 https://www.acmicpc.net/problem/11399
 11399번 ATM
*/
int n;

typedef long long ll;

typedef struct node{//해당하는 값을 arr로 갖는다.
    int v;
}node;
int cmp(void *a,void *b){
    return ((node *)a)->v - ((node *)b)->v;
}

typedef struct vector{//인덱스 접근 가능해야 하며, size 존재, back, pop_back,
    node* arr;//값을 저장하는 곳
    ll size;//크기
    ll capacity;//전체 크기
}vector;

void init(vector *q){
    q->arr=(node *)malloc(sizeof(node)*(64));
    q->size=0;
    q->capacity=64;//초기 크기 64개
}

void push_back(vector *q,int v){//v가 추가되기.
    if(q->size+1<=q->capacity){//
        q->arr[q->size].v=v;
    }else{
        ll new_size= q->capacity*2;
        q->arr = (node*)realloc(q->arr,sizeof(node)*new_size);
        q->arr[q->size].v=v;
        q->capacity=new_size;
    }
    q->size++;//크기 증가
}

void pop_back(vector *q){
    if(q->size){//없을 때는 불러내면 안됨.
        q->size--;//값 줄이기
    }else{
        printf("size가 0이므로 더이상 못 뺌\n");
    }
}

node* back(vector *q){
    node* ret = &q->arr[q->size-1];
    return ret;//값 넘겨주기
}
main(){scanf("%d",&n);
    vector*arr=(vector *)malloc(sizeof(vector));init(arr);
    for(int i=0,t;i<n;i++){scanf("%d",&t);
        push_back(arr,t);
    }
    qsort(arr->arr, n, sizeof(node), cmp);
    ll total=arr->arr[0].v;
    for(int i=1;i<n;i++){
        arr->arr[i].v+=arr->arr[i-1].v;
        total+=arr->arr[i].v;
    }
    printf("%lld",total);
}