//이진 트리
#include <stdio.h>
#include <stdlib.h>

typedef int BTData;
typedef struct _bTreeNode //연결 리스트로 구성
{
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;
// 이진 트리의 기본 함수 구성
BTreeNode *MakeBTreeNode(void);           //노드의 생성
BTData GetData(BTreeNode *bt);            //노드에 저장된 데이터를 반환
void SetData(BTreeNode *bt, BTData data); //노드에 데이터를 저장

BTreeNode *GetLeftSubTree(BTreeNode *bt);  //왼쪽 서브 트리 주소 값 반환
BTreeNode *GetRightSubTree(BTreeNode *bt); //오른쪽 서브 트리 주소 값 반환

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub); //왼쪽 서브 트리를 연결한다.
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

int main()
{
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);

    printf("bt1's left %d\n", GetData(GetLeftSubTree(bt1)));
    printf("bt1's left->left %d\n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
    return 0;
}
BTreeNode *MakeBTreeNode(void) //노드의 생성
{
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}
BTData GetData(BTreeNode *bt) //노드에 저장된 데이터를 반환
{
    return bt->data;
}
void SetData(BTreeNode *bt, BTData data) //노드에 데이터를 저장
{
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt) //왼쪽 서브 트리 주소 값 반환
{
    return bt->left;
}
BTreeNode *GetRightSubTree(BTreeNode *bt) //오른쪽 서브 트리 주소 값 반환
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) //왼쪽 서브 트리를 연결한다.
{
    if (main->left != NULL)
        free(main->left);

    main->left = sub;
}
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    if (main->right != NULL)
        free(main->right);

    main->right = sub;
}