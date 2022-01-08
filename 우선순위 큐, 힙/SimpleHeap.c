//�켱���� ť, ��
//�켱������ ���� �Է��Ͽ� ����
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
    Priority pr; // ���� �������� ���� �켱����
    HData data;
} HeapElem;

typedef struct _heap
{
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap;

/*** Heap ���� ����� ****/
void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data, Priority pr);
HData HDelete(Heap *ph);
//�켱���� �ε��� ���� �Լ�
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
    if (GetLChildIDX(idx) > ph->numOfData) // �ڽ� ��尡 ���ٸ�
        return 0;

    else if (GetLChildIDX(idx) == ph->numOfData) // ���� �ڽ� ��尡 ������ �����
        return GetLChildIDX(idx);

    else // ���� �ڽ� ���� ������ �ڽ� ����� �켱������ ��
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
    HData retData = (ph->heapArr[1]).data; // ������ ������ �ӽ� ����
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1; // ��Ʈ ����� Index
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