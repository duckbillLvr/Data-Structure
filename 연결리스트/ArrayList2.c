//���Ḯ��Ʈ�� �迭 ��� ����
//����ü ���Ḯ��Ʈ
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
// typedef int LData;
//����ü
typedef struct _point
{
    int xpos;
    int ypos;
} Point;
typedef Point *LData;

typedef struct __ArrayList
{                        //�迭 ��� ����Ʈ ���� ����ü
    LData arr[LIST_LEN]; //����Ʈ�� ����� �迭
    int numOfData;       //����� �������� ��
    int curPosition;     //������ ������ġ ���
} ArrayList;

typedef ArrayList List;

//���Ḯ��Ʈ �⺻ ���� �Լ�
void ListInit(List *plist);
void LInsert(List *plist, LData data);
int LFirst(List *plist, LData *pdata); //ù ��° ������ ����
int LNext(List *plist, LData *pdata);  //�� ��° ���� ������ ����
LData LRemove(List *plist);            //������ ������ ����
int LCount(List *plist);               //����� ������ �� ��ȯ

//����ü ���� �Լ�
void SetPointPos(Point *ppos, int xpos, int ypos);
int PointComp(Point *pos1, Point *pos2);
void ShowPointPos(Point *ppos);

int main()
{
    List list;
    Point comPos;
    Point *ppos;

    ListInit(&list);

    // 4�� ������ ����
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);

    //����� ������ ���
    printf("���� �������� ��: %d\n", LCount(&list));
    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);
        while (LNext(&list, &ppos))
            ShowPointPos(ppos);
    }

    // xpos�� 2�� ��� ������ ����
    comPos.xpos = 2;
    comPos.ypos = 0;

    if (LFirst(&list, &ppos))
    {
        if (PointComp(ppos, &comPos) == 1)
        {
            ppos = LRemove(&list);
            free(ppos);
        }

        while (LNext(&list, &ppos))
        {
            if (PointComp(ppos, &comPos) == 1)
            {
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }

    //����� ������ ���
    printf("���� �������� ��: %d\n", LCount(&list));
    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);
        while (LNext(&list, &ppos))
            ShowPointPos(ppos);
    }

    return 0;
}
void ListInit(List *plist)
{
    plist->curPosition = -1;
    plist->numOfData = 0;
}
void LInsert(List *plist, LData data)
{
    if (plist->numOfData >= LIST_LEN)
    {
        puts("������ �Ұ����մϴ�.");
        return;
    }
    plist->arr[plist->numOfData] = data;
    (plist->numOfData) += 1;
}
int LFirst(List *plist, LData *pdata) //ù ��° ������ ����
{
    if (plist->numOfData == 0)
        return FALSE;

    (plist->curPosition) = 0;
    *pdata = plist->arr[0];
    return TRUE;
}
int LNext(List *plist, LData *pdata) //�� ��° ���� ������ ����
{
    if (plist->curPosition >= (plist->numOfData) - 1)
        return FALSE;
    (plist->curPosition) += 1;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}
LData LRemove(List *plist) //������ ������ ����
{
    int rpos = plist->curPosition; //�����ϴ� ��ġ
    int num = plist->numOfData;    //�������� ��
    LData rdata = plist->arr[rpos];

    for (int i = rpos; i < num - 1; i++)
        plist->arr[i] = plist->arr[i + 1];

    (plist->curPosition)--;
    (plist->numOfData)--;
    return rdata;
}
int LCount(List *plist) //����� ������ �� ��ȯ
{
    return plist->numOfData;
}
//����ü ���� �Լ�
void SetPointPos(Point *ppos, int xpos, int ypos)
{
    ppos->xpos = xpos;
    ppos->ypos = ypos;
}
int PointComp(Point *pos1, Point *pos2)
{
    if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)
        return 0;
    else if (pos1->xpos == pos2->xpos)
        return 1;
    else if (pos1->ypos == pos2->ypos)
        return 2;
    else
        return -1;
}
void ShowPointPos(Point *ppos)
{
    printf("[%d, %d] \n", ppos->xpos, ppos->ypos);
}