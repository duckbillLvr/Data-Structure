//���Ḯ��Ʈ�� �迭 ��� ����
//���� ���Ḯ��Ʈ
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
typedef int LData;

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

int main()
{
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