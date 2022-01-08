//��ũ ����Ʈ�� �̿��� ���� ����Ʈ
//������ ������ �Ѱ谡 ����
// head�� �����͸� �߰�
// sort������ ����
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int LData;
typedef struct _node
{
    LData data;
    struct _node *next;
} Node;
typedef struct _linkedList
{
    Node *head;
    Node *cur;
    Node *before;
    int numOfData;
    int (*comp)(LData d1, LData d2);
} LinkedList;
typedef LinkedList List;

//���� ���Ḯ��Ʈ �Լ�
void ListInit(List *plist);
void LInsert(List *plist, LData data);
void FInsert(List *plist, LData data);
void SInsert(List *plist, LData data);
int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);
LData LRemove(List *plist);
int LCount(List *plist);

//�� �Լ�(���� ����)
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));
int WhoIsPrecede(LData d1, LData d2)
{
    if (d1 < d2)
        return 0; // d1�� ���� ������ �ռ���.
    else
        return 1; // d2�� ���� ������ �ռ��ų� ����.
}
int main()
{
    List list;
    LData data;
    ListInit(&list);

    SetSortRule(&list, WhoIsPrecede); //������ ���� ���

    //������ �Է�
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 33);
    LInsert(&list, 22);
    LInsert(&list, 11);

    printf("���� �Էµ� �������� ��: %d\n", LCount(&list));
    //�Էµ� ������ ���
    if (LFirst(&list, &data))
    {
        printf("%d ", data);
        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    if (LFirst(&list, &data))
    {
        if (data == 22) //�����Ͱ� 22�̸� ����
            LRemove(&list);
        while (LNext(&list, &data))
            if (data == 22)
                LRemove(&list);
    }

    printf("���� �Էµ� �������� ��: %d\n", LCount(&list));
    if (LFirst(&list, &data))
    {
        printf("%d ", data);
        while (LNext(&list, &data))
            printf("%d ", data);
    }
    return 0;
}
//���Ḯ��Ʈ �Լ�
void ListInit(List *plist)
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}
void LInsert(List *plist, LData data)
{
    if (plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}
void FInsert(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;
    (plist->numOfData)++;
}
void SInsert(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); //�� ��� ����
    Node *pred = plist->head;                     //���� ��带 ����Ų��

    newNode->data = data;
    while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
    {
        pred = pred->next; //���� ���� �̵�
    }
    newNode->next = pred->next;
    pred->next = newNode;
    (plist->numOfData)++;
}
int LFirst(List *plist, LData *pdata) //ù ��° ������ ����
{
    if (plist->head->next == NULL)
        return FALSE; //���̳�Ʈ�� NULL�� ����ų��

    plist->before = plist->head;
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List *plist, LData *pdata) //�� ��° ���� ������ ����
{
    if (plist->cur->next == NULL)
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}
LData LRemove(List *plist) //������ ������ ����
{
    Node *rpos = plist->cur;  //�Ҹ� ����� �ּ� ��
    LData rdata = rpos->data; //�Ҹ� ����� ������

    plist->before->next = plist->cur->next; //�Ҹ� ����� ����Ʈ���� ����
    plist->cur = plist->before;             // cur�� ��ġ�� ������

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}
int LCount(List *plist) //����� ������ �� ��ȯ
{
    return plist->numOfData;
}
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}