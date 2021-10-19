#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sz = 1;

bool check(char v)
{
    char t;
    scanf("%c", &t);
    if(t == EOF || t == '\n' || t == 0)
    {
        return (!sz ? true : false);
    }

    if(t == ')')
    {
        if(v == '(')
        {
            sz--;
            return true;
        }
        return false;
    }

    if(t == '}')
    {
        if(v == '{')
        {
            sz--;
            return true;
        }
        return false;
    }

    if(t == ']')
    {
        if(v == ']')
        {
            sz--;
            return false;
        }
        return true;
    }

    if(t == '{' || t == '[' || t == '(')
    {
        sz++;
        if(check(t))
            return check(v);
        else
            return false;
    }

    return check(v);
}

typedef struct Node
{
    int dat;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
} List;

void init(List *list)
{
    list->head = NULL;
    list->size = 0;
}

void insert(List *list, int data)
{
    Node *new = (Node*) malloc(sizeof (Node));
    new->dat = data;
    new->next = NULL;

    Node *current = list->head;
    if(!current)
    {
        list->head = new;
        list->size++;
    }
    else
    {
        while (current->next != NULL)
            current = current->next;

        current->next = new;
        list->size++;
    }
}

Node* removeNode(List *list, int data)
{
    Node *current = list->head;
    Node *parent = NULL;

    if(current == NULL)
        return NULL;

    while (current->next != NULL && current->dat != data)
    {
        parent = current;
        current = current->next;
    }

    if(current->dat != data)
        return NULL;
    if(current == list->head)
    {
        list->head = current->next;
        list->size--;
        return current;
    }
    parent->next = current->next;
    list->size--;

    return current;
}

void printNode(Node *node)
{
    if(node == NULL)
    {
        printf("[]");
        return;
    }
    printf("[%d] ", node->dat);
}

void printList(List *list)
{
    Node *current = list->head;
    if(current == NULL)
        printNode(current);
    else
    {
        do
        {
            printNode(current);
            current = current->next;
        }
        while(current != NULL);
    }
    printf(" Size: %d \n", list->size);
}

List* copyList(List *list)
{
    List *newList = (List*) malloc(sizeof(List));
    init(newList);

    Node *current = list->head;

    while (current != NULL)
    {
        insert(newList, current->dat);
        current = current->next;
    }

    return newList;
}

bool isSorted(List *list)
{
    if(list->size == 0)
        return false;
    if(list->size == 1)
        return true;

    Node *current = list->head;
    while (current->next != NULL)
    {
        if(current->dat > current->next->dat)
            return false;

        current = current->next;
    }

    return true;
}

int main()
{
    char t;
    scanf("%c", &t);

    while(t != EOF && t != '\n' && t != 0)
    {
        if(!check(t))
        {
            printf("no\n");
            return 0;
        }
        scanf("%c", &t);
    }

    printf("yes\n");
    return 0;
}
