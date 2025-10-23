#include <stdio.h>
#include <stdlib.h>


struct link_list
{
    //self referential data type
    // struct link_list *link;
    int data;
    struct link_list *link;
};

struct link_list *head = NULL;

void insert_end(int data) {
    struct link_list *new_node = (struct link_list *)malloc(sizeof(struct link_list));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = data;
    new_node->link = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct link_list *temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = new_node;
    }
}

void insert_beg(int data) {
    struct link_list *new_node= (struct link_list *)malloc(sizeof(struct link_list));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
        new_node->data = data;
        new_node->link = NULL;
        if (head == NULL) {
            head = new_node;
        } else {
            new_node->link = head;
            head = new_node;
        }
}

    

void display() {
    struct link_list *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
} 

int main(){
    

    return 0;
}