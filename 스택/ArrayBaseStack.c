//배열 기반의 스택
#include <stdio.h>
#include <stdlib.h>
#define STACK_LEN 100
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;
typedef ArrayStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

int main()
{
    // Source
}
void StackInit(Stack *pstack)
{
    pstack->topIndex = -1;
}
int SIsEmpty(Stack *pstack)
{
    if (pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}
Data SPop(Stack *pstack)
{
    if (SIsEmpty(pstack))
        return -1;

    int rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    return pstack->stackArr[rIdx];
}
Data SPeek(Stack *pstack)
{
    if (SIsEmpty(pstack))
        return -1;

    return pstack->stackArr[pstack->topIndex];
}