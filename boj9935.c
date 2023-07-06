#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/*
 https://www.acmicpc.net/problem/9935
 9935번 문자열 폭발
*/
typedef long long ll;
typedef struct node{
    char value;
    int cnt;//몇 개 쌓아왔는지
    struct node* pre;
}node;
typedef struct stack{
    node *top;
    ll size;
}stack;
ll size(stack* s){
    return s->size;
}
node* top(stack*s){
    return s->top;
}
bool empty(stack*s){
    return s->size==0;
}
void push(stack*s,char value,int cnt){
    node* newv=(node *)malloc(sizeof(node));
    newv->value=value;
    newv->cnt=cnt;
    newv->pre=s->top;
    s->top=newv;
    s->size++;
}
void pop(stack*s){
    node*removes=s->top;
    s->top=s->top->pre;
    s->size--;
    free(removes);
}
void init(stack*s){
    s->top=NULL;
    s->size=0;
}
char word[1000002];
char cmp[38];
main(){
    stack *s=(stack *)malloc(sizeof(stack));init(s);
    scanf("%s %s",word,cmp);
    int cmplen=strlen(cmp);
    for(int i=0;word[i];i++){
        if(cmp[0]==word[i]){
            if(cmplen==1)continue;
            push(s,word[i],1);
        }else{
            int cnt=0;
            if(!empty(s) && s->top->cnt)cnt=s->top->cnt;
            if(cnt<cmplen && cmp[cnt]==word[i])cnt++;
            else cnt=0;
            if(cnt == cmplen){//같으면 push하지 말고 그냥 다 빼내기.
                while(cnt-1)pop(s),cnt--;
                continue;
            }
            push(s,word[i],cnt);
        }
    }
    if(s->size==0)printf("FRULA");
    else{
        stack *t=(stack *)malloc(sizeof(stack));init(t);
        node* value=s->top;
        for(int i=0;i<s->size;i++,value=value->pre)push(t,value->value,0);
        for(int i=0;i<t->size;i++,t->top=t->top->pre)printf("%c",t->top->value);
    }
}