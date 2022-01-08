//연결 리스트 기반 큐
// FIFO
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

typedef struct _lQueue
{
    Node *front;
    Node *rear;
} LQueue;
typedef LQueue Que;

//연결 리스트 기반 큐 함수
void QueueInit(Que *pq);
int QIsEmpty(Que *pq);
void QPush(Que *pq, Data data);
Data QPop(Que *pq);
Data QPeek(Que *pq);

int main()
{
    Que q;
    QueueInit(&q);

    QPush(&q, 1);
    QPush(&q, 2);
    QPush(&q, 3);
    QPush(&q, 4);
    QPush(&q, 5);

    while (!QIsEmpty(&q))
        printf("%d ", QPop(&q));

    return 0;
}

void QueueInit(Que *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}
int QIsEmpty(Que *pq)
{
    if (pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}
void QPush(Que *pq, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if (QIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}
Data QPop(Que *pq)
{
    if (QIsEmpty(pq))
        return -1;

    Node *delNode = pq->front;
    Data retData = delNode->data;
    pq->front = pq->front->next;

    free(delNode);
    return retData;
}
Data QPeek(Que *pq)
{
    if (QIsEmpty(pq))
        return -1;

    return pq->front->data;
}