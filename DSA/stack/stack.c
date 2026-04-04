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
void push(struct stack* s, int data){
    if(isfull(s)){
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top]=data;
}
void pop(struct stack* s){
    if(isempty(s)){
        printf("Stack Underflow\n");
        return;
    }
    int value =s->arr[s->top];
    printf("Popped element is %d\n",value); 
    s->top--;
    return ;
}
void display(struct stack* s){
    if(isempty(s)){
        printf("Stack is empty\n");
        return;
    }
    for(int i=s->top;i>=0;i--){
        printf("%d\n",s->arr[i]);
    }
}
int peek(struct stack* s, int position){
    if(isempty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    if(position<=0 || position>s->top+1){
        printf("Invalid position\n");
        return -1;
    }
    return s->arr[s->top-position+1];
}
int main(){
    struct stack *s;
    s->size=80;
    s->arr = (int*)malloc(s->size*sizeof(int));
    s->top = -1;

push(s, 23);
push(s, 24);
push(s, 25);
push(s, 26);
pop(s);
// s->arr[0]=23;
// s->top++;
display(s);
int pos;
printf("Enter position to peek: ");
scanf("%d", &pos);
int value = peek(s, pos);
if(value != -1){
    printf("Value at position %d is %d\n", pos, value);
}


    return 0;
}