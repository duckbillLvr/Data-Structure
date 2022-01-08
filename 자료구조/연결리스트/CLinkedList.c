//원형 연결 리스트
// head와 tail에 데이터 추가 가능(tail->head->tail->head)
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
typedef struct _linkedList
{
    Node *tail;
    Node *cur;
    Node *before;
    int numOfData;
} CList;
typedef CList List;

//더미 연결리스트 함수
void ListInit(List *plist);
void LInsert(List *plist, Data data);
void LInsertFront(List *plist, Data data);

int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);
Data LRemove(List *plist);
int LCount(List *plist);

int main()
{
    List list;
    ListInit(&list);

    //데이터 저장
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);

    //리스트의 데이터를 3회 연속 출력
    Data data;
    if (LFirst(&list, &data))
    {
        printf("%d ", data);
        for (int i = 0; i < LCount(&list) * 3 - 1; i++)
        {
            if (LNext(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");
    int nodeNum = LCount(&list); // Node의 개수
    if (nodeNum != 0)
    {
        LFirst(&list, &data);
        if (data % 2 == 0)
            LRemove(&list);

        for (int i = 0; i < nodeNum - 1; i++)
        {
            LNext(&list, &data);
            if (data % 2 == 0)
                LRemove(&list);
        }
    }

    if (LFirst(&list, &data))
    {
        printf("%d ", data);
        for (int i = 0; i < LCount(&list) - 1; i++)
        {
            if (LNext(&list, &data))
                printf("%d ", data);
        }
    }
}
//연결리스트 함수
void ListInit(List *plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}
void LInsertFront(List *plist, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    (plist->numOfData)++;
}
void LInsert(List *plist, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    (plist->numOfData)++;
}
int LFirst(List *plist, Data *pdata) //첫 번째 데이터 참조
{
    if (plist->tail == NULL)
        return FALSE;
    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List *plist, Data *pdata) //두 번째 이후 데이터 참조
{
    if (plist->tail == NULL)
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}
Data LRemove(List *plist) //참조한 데이터 삭제
{
    Node *rpos = plist->cur;
    Data rdata = rpos->data;

    if (rpos == plist->tail)
    {
        if (plist->tail == plist->tail->next)
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}
int LCount(List *plist) //저장된 데이터 수 반환
{
    return plist->numOfData;
}