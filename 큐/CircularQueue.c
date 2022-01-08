//배열 기반의 큐
//원형 큐
// FIFO
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define QUE_LEN 100

typedef int Data;
typedef struct _cQueue
{
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue;
typedef CQueue Que;

//배열 기반 원형 큐 함수
void QueueInit(Que *pq);
int QIsEmpty(Que *pq);
void QPush(Que *pq, Data data);
Data QPop(Que *pq);
Data QPeek(Que *pq);
int NextPosIdx(int pos);

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
int NextPosIdx(int pos)
{
    if (pos == QUE_LEN - 1)
        return 0;
    else
        return pos + 1;
}
void QueueInit(Que *pq)
{
    pq->front = 0;
    pq->rear = 0;
}
int QIsEmpty(Que *pq)
{
    if (pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}
void QPush(Que *pq, Data data)
{
    if (NextPosIdx(pq->rear) == pq->front)
        exit(-1);

    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}
Data QPop(Que *pq)
{
    if (QIsEmpty(pq))
        return -1;

    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}
Data QPeek(Que *pq)
{
    if (QIsEmpty(pq))
        return -1;

    return pq->queArr[NextPosIdx(pq->front)];
}