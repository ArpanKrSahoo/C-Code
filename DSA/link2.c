#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL; // Initialize head to NULL

void insertbeg(int data){ // Removed struct node* head parameter
     struct node* ptr=(struct node*)malloc(sizeof(struct node));
     if (ptr == NULL) {
 printf("Memory allocation failed\n");
 return;
     }
 ptr->data = data;
 ptr->next = head;
 head = ptr; // Update the global head
}

void reverse() {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void display(){ // Removed struct node* ptr parameter, use global head
    struct node* ptr = head;
    printf("Element:\n");
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

int main(){

    insertbeg(5); // Insert 5 at the beginning
    insertbeg(4); // Insert 5 at the beginning
    insertbeg(3); // Insert 5 at the beginning
    insertbeg(2); // Insert 5 at the beginning
    display();
    reverse();
    display();
    return 0;
}