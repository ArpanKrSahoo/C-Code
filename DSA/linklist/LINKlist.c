#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void insert_beg(int data){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data=data;
    new_node->next=head;
    head=new_node;
}
void insert_end(int data){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data=data;
    new_node->next=NULL;
    struct node *p;
    p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=new_node;
}
void insert_pos(int data,int pos){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data=data;
    new_node->next=NULL;
    if(pos==0){
        new_node->next=head;
        head=new_node;
        return;
    }
    struct node *p=head;
    for(int i=0;i<pos-1 && p!=NULL;i++){
        p=p->next;
    }
    if(p==NULL){
        printf("Position out of bounds\n");
        free(new_node);
        return;
    }
    new_node->next=p->next;
    p->next=new_node;
}
void delete_beg(){
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    head=head->next;
    free(temp);
}
void delete_end(){
    struct node *temp=head;
    struct node *prev;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }   
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void delete_pos(int pos){
    struct node *temp=head;
    struct node *prev;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(pos==0){
        head=head->next;
        free(temp);
        return;
    }
    for(int i=0;i<pos && temp!=NULL;i++){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Position out of bounds\n");
        return;
    }
    prev->next=temp->next;
    free(temp);
}
void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    int choice, data;
    while(1){
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_beg(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_end(data);
                break;
            case 3:
                delete_beg();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        }
    return 0;
}