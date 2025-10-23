#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack* s)
{
    if(s->top == -1)
        return 1;
    return 0;
}
int isfull(struct stack* s){
    if(s->top==s->size-1)
        return 1;
    return 0;
}

int main(){
    struct stack *s;
    s->size=80;
    s->arr = (int*)malloc(s->size*sizeof(int));
    s->top = -1;


// s->arr[0]=23;
// s->top++;
if ((isempty(s))){
printf("Stack is empty\n");
}
else
{
    printf("Stack is not empty\n");
}
if ((isfull(s))){
printf("Stack is full\n");
}
else
{
    printf("Stack is not full\n");
}



    return 0;
}