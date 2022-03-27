//기수 정렬(Radix Sort)
//데이터의 길이가 같은 경우만 기수 정렬이 용이 하다
// LSD(Least Significant Digit)
// 작은 자릿수 부터 판단
// MSD의 경우 구현의 편의성이 낮다
// 기수 정렬을 큐(FIFO 선입선출)로 구성
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define BUCKET_NUM 10 //양동이 변수
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

//기수 정렬 함수
void RadixSort(Data *arr, int num, int maxLen);

int main()
{
    Data arr[7] = {13, 212, 14, 7141, 10987, 6, 15};
    int len = sizeof(arr) / sizeof(Data);

    RadixSort(arr, len, 5);

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
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
void RadixSort(Data *arr, int num, int maxLen)
{
    // maxLen에는 정렬 대상 중 가장 긴 데이터 길이 정보 전달
    int radix, divfac = 1;
    //필요한 양동이 개수만큼 큐를 만들고 초기화
    Que buckets[BUCKET_NUM];
    for (int i = 0; i < BUCKET_NUM; i++)
        QueueInit(&buckets[i]);

    //가장 긴 데이터의 길이만큼 반복
    for (int pos = 0; pos < maxLen; pos++)
    {
        //정렬 대상의 수 만큼 반복
        for (int i = 0; i < num; i++)
        {
            radix = (arr[i] / divfac) % 10;
            QPush(&buckets[radix], arr[i]);
        }

        for (int i = 0, j = 0; i < BUCKET_NUM; i++)
        {
            //버킷에 저장된 것을 다 꺼내서 다시 arr에 저장
            while (!QIsEmpty(&buckets[i]))
                arr[j++] = QPop(&buckets[i]);
        }

        divfac *= 10;
    }
}