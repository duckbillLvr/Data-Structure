//우선순위를 입력하는 힙(우선순위 큐)
// Priority를 목적에 맞게 자동 설정
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef int HData;
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
int PriComp(int n1, int n2)
{
    return n2 - n1; //오름차순 정렬(최소힙)
}
//힙 정렬
void HeapSort(HData arr[], int n, PriorityComp pc)
{
    Heap heap;
    HeapInit(&heap, pc);

    // arr을 이용하여 힙 구성
    for (int i = 0; i < n; i++)
        HInsert(&heap, arr[i]); // Insert하면서 힙을 이용하여 정렬

    for (int i = 0; i < n; i++)
        arr[i] = HDelete(&heap);
}
int main()
{
    HData arr[4] = {3, 2, 1, 4};

    HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d ", arr[i]);

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