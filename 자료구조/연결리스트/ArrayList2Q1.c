//���Ḯ��Ʈ�� �迭 ��� ����
//����ü ���Ḯ��Ʈ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
#define NAME_LEN 30
#define PHONE_LEN 30
// typedef int LData;
//����ü
typedef struct __namecard
{
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} NameCard;
typedef NameCard *LData;

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
NameCard *MakeNameCard(char *name, char *phone);   //����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
void ShowNameCardInfo(NameCard *pcard);            // Namecard����ü ������ ���� ���
int NameCompare(NameCard *pcard, char *name);      //�̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
void ChangePhoneNum(NameCard *pcard, char *phone); //��ȭ��ȣ ������ ����
int main()
{
    List list;
    ListInit(&list);

    // 3���� ��ȭ��ȣ ����
    NameCard *data;
    data = MakeNameCard("��ö��", "010-8382-9138");
    LInsert(&list, data);
    data = MakeNameCard("�ճ���", "010-2244-4349");
    LInsert(&list, data);
    data = MakeNameCard("����ö", "010-3929-4840");
    LInsert(&list, data);

    //Ư�� �̸��� ������� Ž���Ͽ� ������ ���
    char fname[NAME_LEN], fphone[PHONE_LEN];
    printf("��ȸ�� �̸� �Է�: ");
    scanf("%s", fname);
    getchar();
    if (LFirst(&list, &data))
    {
        if (!NameCompare(data, fname))
            ShowNameCardInfo(data);
        while (LNext(&list, &data))
            if (!NameCompare(data, fname))
                ShowNameCardInfo(data);
    }

    //Ư�� �̸��� ������� Ž���Ͽ� �� ����� ��ȭ��ȣ�� ����
    printf("��ȸ�� �̸� �Է�: ");
    scanf("%s", fname);
    getchar();
    printf("������ ��ȭ��ȣ �Է�: ");
    scanf("%s", fphone);
    getchar();
    if (LFirst(&list, &data))
    {
        if (!NameCompare(data, fname))
            ChangePhoneNum(data, fphone);
        while (LNext(&list, &data))
            if (!NameCompare(data, fname))
                ChangePhoneNum(data, fphone);
    }

    //Ư�� �̸��� Ž���Ͽ� �ش� �ο��� ������ ����
    printf("��ȸ�� �̸� �Է�: ");
    scanf("%s", fname);
    getchar();
    if (LFirst(&list, &data))
    {
        if (!NameCompare(data, fname))
            LRemove(&list);
        while (LNext(&list, &data))
            if (!NameCompare(data, fname))
                LRemove(&list);
    }

    //���� �ο��� ������ ���
    if (LFirst(&list, &data))
    {
        ShowNameCardInfo(data);
        while (LNext(&list, &data))
            ShowNameCardInfo(data);
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
NameCard *MakeNameCard(char *name, char *phone) //����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
{
    NameCard *pcard = (NameCard *)malloc(sizeof(NameCard));
    strcpy(pcard->name, name);
    strcpy(pcard->phone, phone);
    return pcard;
}
void ShowNameCardInfo(NameCard *pcard) // Namecard����ü ������ ���� ���
{
    printf("%s %s\n", pcard->name, pcard->phone);
}
int NameCompare(NameCard *pcard, char *name) //�̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
{
    if (!strcmp(pcard->name, name))
        return FALSE;
    else
        return TRUE;
}
void ChangePhoneNum(NameCard *pcard, char *phone) //��ȭ��ȣ ������ ����
{
    strcpy(pcard->phone, phone);
}
