//����� ���� ����Ʈ
//����� ���Ḯ��Ʈ�� ���� ��� ��� ����
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node
{
    Data data;
    struct _node *next; //�����ʿ��� ����
    struct _node *prev; //���ʿ��� ����
} Node;
typedef struct _DLinkedList
{
    Node *head;
    Node *tail;
    Node *cur;
    int numOfData;
} DBLinkedList;
typedef DBLinkedList List;

//���� ���Ḯ��Ʈ �Լ�
void ListInit(List *plist);

void LInsert(List *plist, Data data);
int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);
int LPrevious(List *plist, Data *pdata);

Data LRemove(List *plist);
int LCount(List *plist);

int main()
{
    List list;
    ListInit(&list);

    Data data;
    //������ �Է�
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);

    //������ ��ȸ
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);

        printf("\n");
    }

    // 2�� ��� ����
    if (LFirst(&list, &data))
    {
        if (data % 2 == 0)
            LRemove(&list);
        while (LNext(&list, &data))
            if (data % 2 == 0)
                LRemove(&list);
    }

    //������ �����
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);

        printf("\n");
    }
    return 0;
}
//���Ḯ��Ʈ �Լ�
void ListInit(List *plist)
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist->tail = (Node *)malloc(sizeof(Node));

    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->next = NULL;
    plist->tail->prev = plist->head;

    plist->cur = NULL;
    plist->numOfData = 0;
}
void LInsert(List *plist, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;

    newNode->next = plist->tail;
    plist->tail->prev = newNode;
    (plist->numOfData)++;
}
int LFirst(List *plist, Data *pdata) //ù ��° ������ ����
{
    if (plist->head->next == plist->tail)
        return FALSE;

    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List *plist, Data *pdata) //�� ��° ���� ������ ����
{
    if (plist->cur->next == plist->tail)
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}
int LPrevious(List *plist, Data *pdata)
{
    if (plist->cur->prev == plist->head)
        return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return TRUE;
}
Data LRemove(List *plist)
{
    Node *rpos = plist->cur;
    Data rdata = rpos->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;

    plist->cur = plist->cur->prev;
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}
int LCount(List *plist) //����� ������ �� ��ȯ
{
    return plist->numOfData;
}