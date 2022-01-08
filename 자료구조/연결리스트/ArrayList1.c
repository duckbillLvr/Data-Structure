//연결리스트의 배열 기반 구현
//정수 연결리스트
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
typedef int LData;

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