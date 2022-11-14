// Implement hashing, where the collision is resolved using linear probing.

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct item
{
    int key;
    int value;
} item;
typedef struct hash_table
{
    int flag;
    struct item *data;
} hash_table;
hash_table *array;
int hash_fun(int key)
{
    return (key % MAX);
}
void init()
{
    for (int i = 0; i < MAX; i++)
    {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}
void insert(int key, int value)
{
    int index, i;
    i = hash_fun(key);
    index = i;
    item *ele = malloc(sizeof(item));
    ele->key = key;
    ele->value = value;
    while (array[i].flag != 0)
    {
        if (array[i].data->key == key)
        {
            printf("updating the data \n");
            array[i].data->value = value;
        }
        i = (i + 1) % MAX;
        if (index == i)
        {
            printf("Hash table is full");
            return;
        }
    }
    array[i].flag = 1;
    array[i].data = ele;
}
void search(int key)
{
    int index, i;
    i = hash_fun(key);
    index = i;
    while (array[i].flag != 0)
    {
        if (array[i].data->key == key)
        {
            printf("Element found");
            return;
        }
        i = (i + 1) % MAX;
        if (i == index)
            break;
    }
    printf("Element not found");
}
void display()
{
    for (int i = 0; i < MAX; i++)
    {
        if (array[i].data == NULL)
            printf("No Data\n");
        else
            printf("key %d and value %d\n", array[i].data->key, array[i].data->value);
    }
}
void delete_data(int key)
{
    int index, i;
    i = hash_fun(key);
    index = i;
    while (array[i].flag != 0)
    {
        if (array[i].data->key == key)
        {
            printf("Element deleted is %d\n",array[i].data->value);
            array[i].flag = 2;
            array[i].data = NULL;
        }
        i = (i + 1) % MAX;
        if (i == index)
            break;
    }
    
}
int main()
{
    int key, ch, value;
    array = malloc(MAX * sizeof(hash_table));
    init();
    while (ch>=5)
    {
        printf("1.Insert\n2.Search\n3.Remove\n4.Display\n");
        printf("Enter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter key and Value\n");
            scanf("%d %d", &key, &value);
            insert(key, value);
            break;
        case 2:
            printf("Enter key");
            scanf("%d", &key);
            search(key);
            break;
        case 3:
            printf("Enter key to be deleted\n");
            scanf("%d", &key);
            delete_data(key);
            break;
        case 4:
            printf("The elements are:\n");
            display();
        }
    }
}