// Deque
//앞, 뒤 모두에서 넣고 뺴기 가능
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node
{
    Data data;
    struct _node *next;
    struct _node *prev;
} Node;
typedef struct _dlDeque
{
    Node *head;
    Node *tail;
} DLDeque;
typedef DLDeque Que;

// Deque 기본 함수
void DequeInit(Que *pq);
int DQIsEmpty(Que *pq);

void DQAddFirst(Que *pq, Data data);
void DQAddLast(Que *pq, Data data);
Data DQRemoveFirst(Que *pq);
Data DQRemoveLast(Que *pq);

Data DQGetFirst(Que *pq);
Data DQGetLast(Que *pq);

int main()
{
    Que q;
    DequeInit(&q);

    //데이터 삽입
    DQAddFirst(&q, 3);
    DQAddFirst(&q, 2);
    DQAddFirst(&q, 1);
    DQAddLast(&q, 4);
    DQAddLast(&q, 5);
    DQAddLast(&q, 6);

    //데이터 꺼내기
    while (!DQIsEmpty(&q))
        printf("%d ", DQRemoveFirst(&q));
    printf("\n");

    //데이터 삽입
    DQAddFirst(&q, 3);
    DQAddFirst(&q, 2);
    DQAddFirst(&q, 1);

    DQAddLast(&q, 4);
    DQAddLast(&q, 5);
    DQAddLast(&q, 6);

    //데이터 꺼내기
    while (!DQIsEmpty(&q))
        printf("%d ", DQRemoveLast(&q));
    printf("\n");

    return 0;
}
void DequeInit(Que *pq)
{
    pq->head = NULL;
    pq->tail = NULL;
}
int DQIsEmpty(Que *pq)
{
    if (pq->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void DQAddFirst(Que *pq, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pq->head;

    if (DQIsEmpty(pq))
        pq->tail = newNode;
    else
        pq->head->prev = newNode;

    newNode->prev = NULL;
    pq->head = newNode;
}
void DQAddLast(Que *pq, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pq->tail;

    if (DQIsEmpty(pq))
        pq->head = newNode;
    else
        pq->tail->next = newNode;

    newNode->next = NULL;
    pq->tail = newNode;
}
Data DQRemoveFirst(Que *pq)
{
    if (DQIsEmpty(pq))
        return -1;
    Node *rnode = pq->head;
    Data rdata = rnode->data;
    pq->head = pq->head->next;
    free(rnode);

    if (pq->head == NULL)
        pq->tail = NULL;
    else
        pq->head->prev = NULL;

    return rdata;
}
Data DQRemoveLast(Que *pq)
{
    if (DQIsEmpty(pq))
        return -1;
    Node *rnode = pq->tail;
    Data rdata = rnode->data;

    pq->tail = pq->tail->prev;
    free(rnode);
    if (pq->tail == NULL)
        pq->head = NULL;
    else
        pq->tail->next = NULL;

    return rdata;
}

Data DQGetFirst(Que *pq)
{
    if (DQIsEmpty(pq))
        return -1;

    return pq->head->data;
}
Data DQGetLast(Que *pq)
{
    if (DQIsEmpty(pq))
        return -1;

    return pq->tail->data;
}
