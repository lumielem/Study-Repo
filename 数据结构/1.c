#include <stdio.h>
#include <malloc.h>
typedef struct Lnode
{
    int data;
    struct Lnode* next;
} LNODE, * Linklist;
Linklist creat(Linklist L)
{
    int node; Linklist p;
    L = (Linklist)malloc(sizeof(LNODE));
    L->next = NULL;
    printf("\nplease input the node(end with 0):\n  ");
    scanf_s("%d", &node);
    while (node != 0)
    {
        p = (Linklist)malloc(sizeof(LNODE));
        if (!p)   exit();
        p->data = node;
        p->next = L->next;
        L->next = p;
        scanf_s("%d", &node);
    }
    return L;
}
Linklist insert(Linklist L, int i, int x)
{
    int j; Linklist p, s;
    p = L; j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (p == NULL || j > i - 1)
        printf("\n ERROR position!\n");
    else
    {
        s = (Linklist)malloc(sizeof(LNODE));
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
    return L;
}
void display(Linklist L)
{
    Linklist p;
    p = L->next;
    while (p != NULL)
    {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}
main()
{
    Linklist L = NULL; int i, x;
    L = creat(L);
    printf("the Linklist is:\n");
    display(L);
    printf("please input the position  you want to insert:");
    scanf_s("%d", &i);
    printf("please input the node you want to insert:");
    scanf_s("%d", &x);
    L = insert(L, i, x);
    printf("the Linklist after inserted is:\n");
    display(L);
}
