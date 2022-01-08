//링크 리스트를 이용한 연결 리스트
//데이터 저장의 한계가 없음
// head에 데이터를 추가
// sort구현이 가능
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

//더미 연결리스트 함수
void ListInit(List *plist);
void LInsert(List *plist, LData data);
void FInsert(List *plist, LData data);
void SInsert(List *plist, LData data);
int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);
LData LRemove(List *plist);
int LCount(List *plist);

//비교 함수(정렬 기준)
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));
int WhoIsPrecede(LData d1, LData d2)
{
    if (d1 < d2)
        return 0; // d1이 정렬 순서상 앞선다.
    else
        return 1; // d2가 정렬 순서상 앞서거나 같다.
}
int main()
{
    List list;
    LData data;
    ListInit(&list);

    SetSortRule(&list, WhoIsPrecede); //정렬의 기준 등록

    //데이터 입력
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 33);
    LInsert(&list, 22);
    LInsert(&list, 11);

    printf("현재 입력된 데이터의 수: %d\n", LCount(&list));
    //입력된 데이터 출력
    if (LFirst(&list, &data))
    {
        printf("%d ", data);
        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    if (LFirst(&list, &data))
    {
        if (data == 22) //데이터가 22이면 삭제
            LRemove(&list);
        while (LNext(&list, &data))
            if (data == 22)
                LRemove(&list);
    }

    printf("현재 입력된 데이터의 수: %d\n", LCount(&list));
    if (LFirst(&list, &data))
    {
        printf("%d ", data);
        while (LNext(&list, &data))
            printf("%d ", data);
    }
    return 0;
}
//연결리스트 함수
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
    Node *newNode = (Node *)malloc(sizeof(Node)); //새 노드 생성
    Node *pred = plist->head;                     //더미 노드를 가르킨다

    newNode->data = data;
    while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
    {
        pred = pred->next; //다음 노드로 이동
    }
    newNode->next = pred->next;
    pred->next = newNode;
    (plist->numOfData)++;
}
int LFirst(List *plist, LData *pdata) //첫 번째 데이터 참조
{
    if (plist->head->next == NULL)
        return FALSE; //더미노트가 NULL을 가리킬때

    plist->before = plist->head;
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List *plist, LData *pdata) //두 번째 이후 데이터 참조
{
    if (plist->cur->next == NULL)
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}
LData LRemove(List *plist) //참조한 데이터 삭제
{
    Node *rpos = plist->cur;  //소멸 대상의 주소 값
    LData rdata = rpos->data; //소멸 대상의 데이터

    plist->before->next = plist->cur->next; //소멸 대상을 리스트에서 제거
    plist->cur = plist->before;             // cur의 위치를 재조정

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}
int LCount(List *plist) //저장된 데이터 수 반환
{
    return plist->numOfData;
}
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}