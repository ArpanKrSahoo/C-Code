#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
int is_empty(struct stack* s){
    if(s->top==-1)
        return 1;
    return 0;
}
int is_full(struct stack* s){
    if(s->top==s->size-1)
        return 1;
    return 0;
}
void push(int data){
    struct stack *s;
    if(is_full(s)){
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top]=data;
}

int main(){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));

    push(67);
    if(is_empty(s)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }
    if(is_full(s)){
        printf("Stack is full\n");
    }
    else{
        printf("Stack is not full\n");
    }
    
    return 0;
}