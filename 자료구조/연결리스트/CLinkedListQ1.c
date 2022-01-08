//���� ���� ����Ʈ
// head�� tail�� ������ �߰� ����(tail->head->tail->head)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct _employee
{
    char name[30];
    int id;
} Employee;
typedef Employee *Data;
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

//���� ���Ḯ��Ʈ �Լ�
void ListInit(List *plist);
void LInsert(List *plist, Data data);
void LInsertFront(List *plist, Data data);

int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);
Data LRemove(List *plist);
int LCount(List *plist);

// Employee fun
Employee *ENightDuty(List *plist, char *name, int day);
void ShowEmployeeInfo(Employee *em);
int main()
{
    List list;
    ListInit(&list);

    Employee *em;
    em = (Employee *)malloc(sizeof(Employee));
    em->id = 111111;
    strcpy(em->name, "Terry");
    LInsert(&list, em);
    em = (Employee *)malloc(sizeof(Employee));
    em->id = 222222;
    strcpy(em->name, "Jery");
    LInsert(&list, em);
    em = (Employee *)malloc(sizeof(Employee));
    em->id = 333333;
    strcpy(em->name, "Sunny");
    LInsert(&list, em);
    em = (Employee *)malloc(sizeof(Employee));
    em->id = 444444;
    strcpy(em->name, "Harry");
    LInsert(&list, em);

    // Terry�� 3�� �� �����ڴ�?
    em = ENightDuty(&list, "Terry", 3);
    ShowEmployeeInfo(em);

    // Sunny �ڷ� 15�� �� �����ڴ�?
    em = ENightDuty(&list, "Sunny", 15);
    ShowEmployeeInfo(em);

    //�޸� ����
    if (LFirst(&list, &em))
    {
        free(em);
        for (int i = 0; i < LCount(&list) - 1; i++)
        {
            if (LNext(&list, &em))
                free(em);
        }
    }
}
//���Ḯ��Ʈ �Լ�
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
int LFirst(List *plist, Data *pdata) //ù ��° ������ ����
{
    if (plist->tail == NULL)
        return FALSE;
    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List *plist, Data *pdata) //�� ��° ���� ������ ����
{
    if (plist->tail == NULL)
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}
Data LRemove(List *plist) //������ ������ ����
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
int LCount(List *plist) //����� ������ �� ��ȯ
{
    return plist->numOfData;
}
Employee *ENightDuty(List *plist, char *name, int day)
{
    Employee *rem;
    int i;

    int num = LCount(plist);
    LFirst(plist, &rem);
    if (strcmp(rem->name, name) != 0)
    {
        for (i = 0; i < num - 1; i++)
        {
            LNext(plist, &rem);
            {
                if (strcmp(rem->name, name) == 0)
                    break;
            }
        }
        if (i >= num - 1)
            return NULL;
    }

    for (i = 0; i < day; i++)
        LNext(plist, &rem);

    return rem;
}
void ShowEmployeeInfo(Employee *em)
{
    printf("%s  %d\n", em->name, em->id);
}