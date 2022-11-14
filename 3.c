// Perform the following operations on a singly/doubly linked list.

//    a) Insert at the given position

//    b) Delete alternate nodes, starting from the first node in the given list

//    c) Count the number of nodes

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

void insertFront(LISTLINK *ptr,int element){
    NODE *newnode;
    newnode = getnode(element);
    if (ptr->head == NULL) {
        ptr->head = newnode;
    }
    else {
        newnode->link = ptr->head;
        ptr->head = newnode;
    }
    ptr->count++;
}

void insertEnd(LISTLINK *ptr,int element){
    NODE *newnode,*aux=ptr->head;
    newnode = getnode(element);
    if (ptr->head==NULL) {
        ptr->head = newnode;
    }
    else {
        while (aux->link!=NULL) {
            aux = aux->link;
        }
        aux->link = newnode;
    }
    ptr->count++;
}

void insertSpecifed(LISTLINK *ptr,int element,int position){
    NODE *current = ptr->head, *previous = NULL, *newnode = getnode(element);
    int count = 1;
    if(position>ptr->count+1){
        printf("Invalid position\n");
    }
    else{ 
        if(position==ptr->count+1){
            insertEnd(ptr,element);
        }
        else if(position == 1){
            insertFront(ptr,element);
        }
        else{
            while (count!=position && current!=NULL)
            {
                previous = current;
                current = current->link;
                count ++;
            }
            newnode->link = current;
            previous->link = newnode;
            
        }
    }
    ptr->count++;
}
        
void alternateDelete(LISTLINK *ptr){
    NODE *current = ptr->head->link;
    NODE *prev = ptr->head;

    if(ptr->head==NULL){
        printf(
            "EMPTY LIST"
        );
    }
    while (current!=NULL && prev!=NULL)
    {
        
        prev->link = current->link;
        printf("Deleted node is %d\n",current->data);
        prev = prev->link;
        free(current);
        if(prev!=NULL){
            current = prev->link;
        }
    }
    
        
}         

int count_no_of_nodes(LISTLINK *ptr){
    printf("No of nodes in the list are %d" , ptr->count-1);
}

int main(){
    LISTLINK l1;
    init(&l1);
    insertSpecifed(&l1,10,1);
    insertSpecifed(&l1,40,2);
    insertSpecifed(&l1,20,3);
    insertSpecifed(&l1,30,4);

    printf("*******************************************************\n");
    printf("NODES\n");
    display(&l1);
    printf("\n*******************************************************\n");
    printf("Deleting Alternately\n");
    printf("*******************************************************\n");
    alternateDelete(&l1);
    display(&l1);
    printf("\n*******************************************************\n");
    count_no_of_nodes(&l1);
    printf("\n");
}

  
