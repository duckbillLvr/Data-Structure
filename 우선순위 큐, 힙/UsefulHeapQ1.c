//�켱������ �Է��ϴ� ��(�켱���� ť)
// Priority�� ������ �°� �ڵ� ����
//���ڿ��� ª�� ���� �켱 ������ ����
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
    PriorityComp *comp; //�켱���� ���� �Լ�
} Heap;

//�� �⺻ �Լ�
void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);
void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);
//�� �켱���� �Լ�
int GetParentIdx(int idx);
int GetLChildIdx(int idx);
int GetRChildIdx(int idx);
int GetHiPriChildIdx(Heap *ph, int idx);
//������ �켱 ���� �Լ�
int DataPriorityComp(HData d1, HData d2)
{
    return strlen(d2) - strlen(d1); // ch1�� �� ���� ��� ��ȯ �ǽ�(�켱������ ���� ���)
    // return�� ����� ��� ��ȯ �ǽ�
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
    printf("�켱������ ���� ���� ��� ���\n");
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
{ //�ΰ��� �ڽ� ��� �� ���� �켱������ �ڽ� ��� �ε��� �� ��ȯ
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