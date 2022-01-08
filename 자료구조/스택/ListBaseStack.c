//연결 리스트 기반 스택
// LIFO
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node
{
    Data data;
    struct _node *next;
} Node;

typedef struct _listStack
{
    Node *head;
} ListStack;
typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);
void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

int main()
{
}
void StackInit(Stack *pstack)
{
    pstack->head = NULL;
}
int SIsEmpty(Stack *pstack)
{
    if (pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}
void SPush(Stack *pstack, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->head;
    pstack->head = newNode;
}
Data SPop(Stack *pstack)
{
    if (SIsEmpty(pstack))
        return -1;

    Node *rnode = pstack->head;
    Data rdata = rnode->data;

    pstack->head = pstack->head->next;
    free(rnode);
    return rdata;
}
Data SPeek(Stack *pstack)
{
    if (SIsEmpty(pstack))
        return -1;

    return pstack->head->data;
}