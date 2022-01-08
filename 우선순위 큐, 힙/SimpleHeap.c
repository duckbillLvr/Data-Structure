//우선순위 큐, 힙
//우선순위를 직접 입력하여 구현
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
    Priority pr; // 값이 작을수록 높은 우선순위
    HData data;
} HeapElem;

typedef struct _heap
{
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap;

/*** Heap 관련 연산들 ****/
void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data, Priority pr);
HData HDelete(Heap *ph);
//우선순위 인덱스 관련 함수
int GetParentIDX(int idx);
int GetLChildIDX(int idx);
int GetRChildIDX(int idx);
int GetHiPriChildIDX(Heap *ph, int idx);

int main(void)
{
    Heap heap;
    HeapInit(&heap);

    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("%c ", HDelete(&heap));

    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("%c ", HDelete(&heap));
    printf("\n");
    while (!HIsEmpty(&heap))
        printf("%c ", HDelete(&heap));

    return 0;
}

void HeapInit(Heap *ph)
{
    ph->numOfData = 0;
}

int HIsEmpty(Heap *ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx)
{
    return idx / 2;
}

int GetLChildIDX(int idx)
{
    return idx * 2;
}

int GetRChildIDX(int idx)
{
    return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap *ph, int idx)
{
    if (GetLChildIDX(idx) > ph->numOfData) // 자식 노드가 없다면
        return 0;

    else if (GetLChildIDX(idx) == ph->numOfData) // 왼쪽 자식 노드가 마지막 노드라면
        return GetLChildIDX(idx);

    else // 왼쪽 자식 노드와 오른쪽 자식 노드의 우선순위를 비교
    {
        if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

void HInsert(Heap *ph, HData data, Priority pr)
{
    int idx = ph->numOfData + 1;
    HeapElem nelem = {pr, data};

    while (idx != 1)
    {
        if (pr < (ph->heapArr[GetParentIDX(idx)].pr))
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
    }

    ph->heapArr[idx] = nelem;
    ph->numOfData += 1;
}

HData HDelete(Heap *ph)
{
    HData retData = (ph->heapArr[1]).data; // 삭제할 데이터 임시 저장
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1; // 루트 노드의 Index
    int childIdx;

    while (childIdx = GetHiPriChildIDX(ph, parentIdx))
    {
        if (lastElem.pr <= ph->heapArr[childIdx].pr)
            break;

        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}