#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define min(a,b)(a>b?b:a)
#define max(a,b)(a>b?a:b)
/*
 https://www.acmicpc.net/problem/1049
 1049번 기타줄
 패키지 가격, 낱개 가격이 있다.
 패키지로 사는 것이 이득일 수도 있고, 낱개로 사는 것이 이득일 수도 있다.
 일단은
 낱개 금액 갖고 오고
 패키지 금액  갖고 와서
 
 1. 6개 묶음 가격 갖고 오기.
 2. n개를 최대한 채우기. (패키지로만 해서)
 3. n에서 n%6한 뒤에 나오는 낱개들로만 해서
 4. 가격 갖고 오기.
*/
int n,m;
typedef long long ll;

typedef struct node{//해당하는 값을 arr로 갖는다.
    int v;
}node;

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
int cmp(void*a,void*b){
    return ((node *)a)->v-((node*)b)->v;
}
int result;
main(){scanf("%d %d",&n,&m);
    vector *v=(vector*)malloc(sizeof(vector));//패키지 저장
    vector *v1=(vector*)malloc(sizeof(vector));//낱개 저장
    init(v),init(v1);
    for(int i=0,n6,q;i<m;i++){
        scanf("%d %d",&n6,&q);
        push_back(v,n6);
        push_back(v,q*6);
        push_back(v1,q);
    }
    qsort(v->arr,v->size,sizeof(node),cmp);
    qsort(v1->arr,v1->size,sizeof(node),cmp);
    result=min(v->arr[0].v*(n/6+1),v->arr[0].v*(n/6)+v1->arr[0].v*(n%6));
    printf("%d",result);
}