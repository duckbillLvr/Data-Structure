//����� ���� ����Ʈ
//���ʰ� ������ ��ο��� ������ ����
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

int LCount(List *plist);

int main()
{
}
//���Ḯ��Ʈ �Լ�
void ListInit(List *plist)
{
    plist->head = NULL;
    plist->cur = NULL;
    plist->numOfData = 0;
}
void LInsert(List *plist, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head;
    if (plist->head != NULL)
        plist->head->prev = newNode;

    newNode->prev = NULL;
    plist->head = newNode;
    (plist->numOfData)++;
}
int LFirst(List *plist, Data *pdata) //ù ��° ������ ����
{
    if (plist->head == NULL)
        return FALSE;

    plist->cur = plist->head;
    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List *plist, Data *pdata) //�� ��° ���� ������ ����
{
    if (plist->cur->next == NULL)
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}
int LPrevious(List *plist, Data *pdata)
{
    if (plist->cur->prev == NULL)
        return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return TRUE;
}

int LCount(List *plist) //����� ������ �� ��ȯ
{
    return plist->numOfData;
}