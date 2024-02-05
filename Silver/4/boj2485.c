#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/*
 https://www.acmicpc.net/problem/2485
 2485번 가로수
 x,x1,x2
 4,6의 간격이 있을 때
 2,6,12,18
 4,5 최대 공약수 1
 나오는 간격들의 최대 공약수로 맞히면 된다.
 vector구현하기.
 0,1,2번 인덱스
 a,b,c
*/
typedef long long ll;

typedef struct node{
    int v;
}node;

typedef struct vector{//인덱스 접근 가능해야 하며, size 존재, back, pop_back,
    node* arr;//값을 저장하는 곳
    node* back;
    ll size;
    ll capacity;
}vector;

ll gcd(ll a,ll b){
    ll tmp,n;
    if(a<b){
        tmp = a;
        a=b,b=tmp;
    }
    while(b){
        n=a%b;
        a=b,b=n;
    }
    return a;
}

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
        free(&q->arr[q->size]);//마지막 값 빼야 됨.
        q->size--;//값 줄이기
    }
}

int n;
ll cnt;
vector* b;
main(){scanf("%d",&n);
    vector *a=(vector *)malloc(sizeof(vector));
    b=(vector *)malloc(sizeof(vector));
    init(a);init(b);
    for(int i=0,t;i<n;i++){
        scanf("%d",&t);
        push_back(b,t);
    }
    int value = b->arr[1].v-b->arr[0].v;
    for(int i=1;i<n;i++){//최대 공약수 알아내기
        int n1 =b->arr[i].v-b->arr[i-1].v;
        push_back(a,n1);
        value=gcd(value,n1);
    }
    for(int i=0;i<a->size;i++){
        cnt+=a->arr[i].v/value-1;
    }
    printf("%lld",cnt);
}
