//��� ����(Radix Sort)
//�������� ���̰� ���� ��츸 ��� ������ ���� �ϴ�
// LSD(Least Significant Digit)
// ���� �ڸ��� ���� �Ǵ�
// MSD�� ��� ������ ���Ǽ��� ����
// ��� ������ ť(FIFO ���Լ���)�� ����
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define BUCKET_NUM 10 //�絿�� ����
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

//���� ����Ʈ ��� ť �Լ�
void QueueInit(Que *pq);
int QIsEmpty(Que *pq);
void QPush(Que *pq, Data data);
Data QPop(Que *pq);
Data QPeek(Que *pq);

//��� ���� �Լ�
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
    // maxLen���� ���� ��� �� ���� �� ������ ���� ���� ����
    int radix, divfac = 1;
    //�ʿ��� �絿�� ������ŭ ť�� ����� �ʱ�ȭ
    Que buckets[BUCKET_NUM];
    for (int i = 0; i < BUCKET_NUM; i++)
        QueueInit(&buckets[i]);

    //���� �� �������� ���̸�ŭ �ݺ�
    for (int pos = 0; pos < maxLen; pos++)
    {
        //���� ����� �� ��ŭ �ݺ�
        for (int i = 0; i < num; i++)
        {
            radix = (arr[i] / divfac) % 10;
            QPush(&buckets[radix], arr[i]);
        }

        for (int i = 0, j = 0; i < BUCKET_NUM; i++)
        {
            //��Ŷ�� ����� ���� �� ������ �ٽ� arr�� ����
            while (!QIsEmpty(&buckets[i]))
                arr[j++] = QPop(&buckets[i]);
        }

        divfac *= 10;
    }
}