//Reverse the given singly linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}NODE;

typedef struct listlink{
    NODE *head;
    int count;
}LISTLINK;

void init(LISTLINK *ptr){   
    ptr->head = NULL;
    ptr->count = 0;   
}
    
NODE *getnode(int element){
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = element;
    temp->link = NULL;
    return temp;
}

void display(LISTLINK *ptr){
    NODE *current = ptr->head;
    if(current==NULL){
        printf("List empty...\n");
        return ;
    }
    else{
        while (current!=NULL)
        {
            printf("%d-->",current->data);
            current = current->link;
        }
        
    }
}

void insertRear(LISTLINK *ptr,int element){
    NODE *newnode = getnode(element);
    NODE *temp = ptr->head;
    if(ptr->head == NULL){
        ptr->head = newnode;
    }
    else{
        while (temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
        
    }
    ptr->count ++;
}

void reverse(LISTLINK *ptr){
    NODE *current = ptr->head;
    NODE *prev = NULL;
    NODE *next = NULL;
    while (current!=NULL)
    {
       next = current->link;
       current->link = prev;
       prev = current;
       current = next;
    }
    ptr->head = prev;
    
}

int main(){
    LISTLINK l1;
    init(&l1);
    insertRear(&l1,10);
    insertRear(&l1,40);
    insertRear(&l1,20);
    insertRear(&l1,30);

    printf("*******************************************************\n");
    printf("Before reversing\n");
    display(&l1);
    printf("\n*******************************************************\n");
    printf("After reversing!\n");
    printf("*******************************************************\n");
    reverse(&l1);
    display(&l1);
    printf("\n*******************************************************\n");

}