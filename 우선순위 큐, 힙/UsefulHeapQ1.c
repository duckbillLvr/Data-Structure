//우선순위를 입력하는 힙(우선순위 큐)
// Priority를 목적에 맞게 자동 설정
//문자열이 짧을 수록 우선 순위가 높음
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef char *HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
    HData heapArr[HEAP_LEN];
    int numOfData;
    PriorityComp *comp; //우선순위 지정 함수
} Heap;

//힙 기본 함수
void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);
void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);
//힙 우선순위 함수
int GetParentIdx(int idx);
int GetLChildIdx(int idx);
int GetRChildIdx(int idx);
int GetHiPriChildIdx(Heap *ph, int idx);
//데이터 우선 순위 함수
int DataPriorityComp(HData d1, HData d2)
{
    return strlen(d2) - strlen(d1); // ch1이 더 작을 경우 교환 실시(우선순위가 높을 경우)
    // return이 양수일 경우 교환 실시
}
int main()
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, "Good morning");
    HInsert(&heap, "I am a boy");
    HInsert(&heap, "Priority Queue");
    HInsert(&heap, "Do you like coffee?");
    HInsert(&heap, "I am so happy");
    printf("우선순위가 높은 순서 대로 출력\n");
    while (!HIsEmpty(&heap))
        printf("%s\n", HDelete(&heap));

    return 0;
}

void HeapInit(Heap *ph, PriorityComp pc)
{
    ph->comp = pc;
    ph->numOfData = 0;
}
int HIsEmpty(Heap *ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}
void HInsert(Heap *ph, HData data)
{
    int idx = ph->numOfData + 1;

    while (idx != 1)
    {
        if (ph->comp(data, ph->heapArr[GetParentIdx(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
            idx = GetParentIdx(idx);
        }
        else
            break;
    }
    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}
HData HDelete(Heap *ph)
{
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while (childIdx = GetHiPriChildIdx(ph, parentIdx))
    {
        if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}

int GetParentIdx(int idx)
{
    return idx / 2;
}
int GetLChildIdx(int idx)
{
    return idx * 2;
}
int GetRChildIdx(int idx)
{
    return GetLChildIdx(idx) + 1;
}
int GetHiPriChildIdx(Heap *ph, int idx)
{ //두개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
    if (GetLChildIdx(idx) > ph->numOfData)
        return 0;
    else if (GetLChildIdx(idx) == ph->numOfData)
        return GetLChildIdx(idx);
    else
    {
        if (ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) < 0)
            return GetRChildIdx(idx);
        else
            return GetLChildIdx(idx);
    }
}