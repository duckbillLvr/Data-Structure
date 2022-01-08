//연결리스트의 배열 기반 구현
//구조체 연결리스트
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
#define NAME_LEN 30
#define PHONE_LEN 30
// typedef int LData;
//구조체
typedef struct __namecard
{
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} NameCard;
typedef NameCard *LData;

typedef struct __ArrayList
{                        //배열 기반 리스트 정의 구조체
    LData arr[LIST_LEN]; //리스트의 저장소 배열
    int numOfData;       //저장된 데이터의 수
    int curPosition;     //데이터 참조위치 기록
} ArrayList;

typedef ArrayList List;

//연결리스트 기본 동작 함수
void ListInit(List *plist);
void LInsert(List *plist, LData data);
int LFirst(List *plist, LData *pdata); //첫 번째 데이터 참조
int LNext(List *plist, LData *pdata);  //두 번째 이후 데이터 참조
LData LRemove(List *plist);            //참조한 데이터 삭제
int LCount(List *plist);               //저장된 데이터 수 반환

//구조체 설정 함수
NameCard *MakeNameCard(char *name, char *phone);   //구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
void ShowNameCardInfo(NameCard *pcard);            // Namecard구조체 변수의 정보 출력
int NameCompare(NameCard *pcard, char *name);      //이름이 같으면 0, 다르면 0이 아닌 값 반환
void ChangePhoneNum(NameCard *pcard, char *phone); //전화번호 정보를 변경
int main()
{
    List list;
    ListInit(&list);

    // 3명의 전화번호 저장
    NameCard *data;
    data = MakeNameCard("김철수", "010-8382-9138");
    LInsert(&list, data);
    data = MakeNameCard("손나은", "010-2244-4349");
    LInsert(&list, data);
    data = MakeNameCard("나중철", "010-3929-4840");
    LInsert(&list, data);

    //특정 이름을 대상으로 탐색하여 정보를 출력
    char fname[NAME_LEN], fphone[PHONE_LEN];
    printf("조회할 이름 입력: ");
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

    //특정 이름을 대상으로 탐색하여 그 사람의 전화번호를 변경
    printf("조회할 이름 입력: ");
    scanf("%s", fname);
    getchar();
    printf("변경할 전화번호 입력: ");
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

    //특정 이름을 탐색하여 해당 인원의 정보를 삭제
    printf("조회할 이름 입력: ");
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

    //남은 인원의 정보를 출력
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
        puts("저장이 불가능합니다.");
        return;
    }
    plist->arr[plist->numOfData] = data;
    (plist->numOfData) += 1;
}
int LFirst(List *plist, LData *pdata) //첫 번째 데이터 참조
{
    if (plist->numOfData == 0)
        return FALSE;

    (plist->curPosition) = 0;
    *pdata = plist->arr[0];
    return TRUE;
}
int LNext(List *plist, LData *pdata) //두 번째 이후 데이터 참조
{
    if (plist->curPosition >= (plist->numOfData) - 1)
        return FALSE;
    (plist->curPosition) += 1;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}
LData LRemove(List *plist) //참조한 데이터 삭제
{
    int rpos = plist->curPosition; //참조하는 위치
    int num = plist->numOfData;    //데이터의 수
    LData rdata = plist->arr[rpos];

    for (int i = rpos; i < num - 1; i++)
        plist->arr[i] = plist->arr[i + 1];

    (plist->curPosition)--;
    (plist->numOfData)--;
    return rdata;
}
int LCount(List *plist) //저장된 데이터 수 반환
{
    return plist->numOfData;
}
//구조체 설정 함수
NameCard *MakeNameCard(char *name, char *phone) //구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
{
    NameCard *pcard = (NameCard *)malloc(sizeof(NameCard));
    strcpy(pcard->name, name);
    strcpy(pcard->phone, phone);
    return pcard;
}
void ShowNameCardInfo(NameCard *pcard) // Namecard구조체 변수의 정보 출력
{
    printf("%s %s\n", pcard->name, pcard->phone);
}
int NameCompare(NameCard *pcard, char *name) //이름이 같으면 0, 다르면 0이 아닌 값 반환
{
    if (!strcmp(pcard->name, name))
        return FALSE;
    else
        return TRUE;
}
void ChangePhoneNum(NameCard *pcard, char *phone) //전화번호 정보를 변경
{
    strcpy(pcard->phone, phone);
}
