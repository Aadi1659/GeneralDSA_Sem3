//Implement Josephus problem using circular linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *tail;
}NODE;

typedef struct listlink{
    NODE *head;
    
}CLINK;

void init(CLINK *ptr){   
    ptr->head = NULL;
      
}
    
NODE *getnode(int element){
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = element;
    temp->tail = NULL;
    return temp;
}

void display(CLINK *ptr){
    NODE *current = ptr->head->tail;
    if(ptr->head == ptr->head->tail){
        printf("%d",ptr->head->data);
        return ;
    }
    else{
        while (current->tail!=ptr->head->tail)
        {
            printf("%d-->",current->data);
            current = current->tail;
        }
        printf("%d-->",current->data);
    }
}

void insertFront(CLINK *ptr,int element){
    NODE *newnode;
    newnode = getnode(element);
    if (ptr->head == NULL) {
        newnode->tail = newnode;
        ptr->head = newnode;
    }
    else {
        newnode->tail = ptr->head->tail;
        ptr->head->tail = newnode;
    }
}
   
void insertRear(CLINK *ptr, int element) {
  NODE *newnode = getnode(element);
  if (ptr->head == NULL) {
    newnode->tail = newnode;
    ptr->head = newnode;
  } else {
    newnode->tail = ptr->head->tail;
    ptr->head->tail = newnode;
    ptr->head = newnode;
  }
}

int josephs(CLINK *ptr,int position){
    NODE *p = ptr->head;
    NODE *q = ptr->head;

    while (p->tail!=p)
    {
        for (int i = 0; i < position; i++)
        {
            q = p;
            p = p->tail;
        }
        q->tail = p->tail;
        printf("%d has been killed\n",p->data);
        free(p);
        p = q->tail;
    }
    ptr->head = p;
    return p->data;   
}
    



int main(){
    CLINK l1;
    init(&l1);
    insertRear(&l1,10);
    insertRear(&l1,40);
    insertRear(&l1,20);
    insertRear(&l1,30);

    printf("*******************************************************\n");
    printf("NODES\n");
    display(&l1);
    printf("\n*******************************************************\n");
    int ans = josephs(&l1,2);
    printf("%d is the survivor\n",ans);
}

  
