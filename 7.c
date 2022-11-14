#include <stdio.h>
#include <stdlib.h>

struct tNode
{
    int data;
    struct tNode *right;
    struct tNode *left;
};

struct sNode
{
    struct tNode *tree_pointer;
    struct sNode *next;
};

void push(struct sNode **top, struct tNode *t);
struct tNode *pop(struct sNode **top);
int isEmpty(struct sNode *top);

void inorder_iterative(struct tNode *root)
{
    struct tNode *current = root; // set current to root
    struct sNode *s = NULL;       // empty stack

    do
    {
        while (current != NULL)
        {
            push(&s, current);
            current = current->left;
        }
        current = pop(&s);
        printf("%d\t", current->data);
        current = current->right;

    } while (!isEmpty(s) || current != NULL);
}

void preorder_iterative(struct tNode *root)
{
    struct tNode *current = root;
    struct sNode *s = NULL;
    push(&s, current);
    while (!isEmpty(s))
    {
        current = pop(&s);
        printf("Popped element is %d\n", current->data);
        if (current->right)
        {
            push(&s, current->right);
        }
        if (current->left)
        {
            push(&s, current->left);
        }
    }
}

void postorder_iterative(struct tNode *root)
{
    struct tNode *current = root;
    struct sNode *s1 = NULL;
    struct sNode *s2 = NULL;
    push(&s1, current);
    while (!isEmpty(s1))
    {
        current = pop(&s1);
        push(&s2, current);
        if (current->right)
        {
            push(&s1, current->right);
        }
        if (current->left)
        {
            push(&s1, current->left);
        }
    }
    while (!isEmpty(s2))
    {
        current = pop(&s2);
        printf("%d\t", current->data);
    }
}

void push(struct sNode **top, struct tNode *t)
{
    struct sNode *newnode = (struct sNode *)malloc(sizeof(struct sNode));
    if (newnode == NULL)
    {
        printf("Stack Overflow\n");
        getchar();
        exit(0);
    }

    newnode->tree_pointer = t;
    newnode->next = (*top);
    *top = newnode;
}

int isEmpty(struct sNode *top)
{
    return (top == NULL) ? 1 : 0;
}

struct tNode *pop(struct sNode **top)
{
    struct tNode *res;
    struct sNode *stop;
    if (isEmpty(*top))
    {
        printf("Stack underflow\n");
        exit(0);
    }
    else
    {
        stop = *top;
        res = stop->tree_pointer;
        *top = stop->next;
        free(stop);
        return (res);
    }
}

struct tNode *newtNode(int data)
{
    struct tNode *tNode = (struct tNode *)
        malloc(sizeof(struct tNode));
    tNode->data = data;
    tNode->left = NULL;
    tNode->right = NULL;

    return (tNode);
}

int height(struct tNode *ptr){
    if(!ptr){
        return 0;
    }
    else{
        int left = height(ptr->left);
        int right = height(ptr->right);
        if (left >= right)
            return left + 1;
        else
            return right + 1;
    }
}

//to calculate total number of nodes we need left height and right height
int left_height(struct tNode *ptr){
    int ht = 0;
    while(ptr){
        ht ++;
        ptr = ptr->left;
    }
    return ht;
}

int right_height(struct tNode *ptr){
    int ht = 0;
    while(ptr){
        ht++;
        ptr = ptr->right;
        
    }
    return ht;
}
    
int total_no_of_nodes(struct tNode *ptr)
{
    if(ptr==NULL){
        return 0;
    }
    int lh = left_height(ptr);
    int rh = right_height(ptr);

    if (lh == rh)
        return (1 << lh) - 1;
    // Otherwise, recursive call
    return 1 + total_no_of_nodes(ptr->left) + total_no_of_nodes(ptr->right);
}


int main()
{

    /* Constructed binary tree is
                1
            / \
            2	 3
        / \
        4	 5
    */
    struct tNode *root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);

    // inorder_iterative(root);
    // preorder_iterative(root);
    postorder_iterative(root);

    int answer = height(root);
    printf("\n height is %d\n",answer);

    int nodes = total_no_of_nodes(root);
    printf("\nTotal number of nodes in the tree are %d\n",nodes);
    return 0;
}
