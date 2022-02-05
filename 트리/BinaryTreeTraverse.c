//이진 트리
//순회 함수의 구현
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
//이진 트리의 순회
// 1. 중위 순회 함수
void InorderTraverse(BTreeNode *bt)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left);
    printf("%d ", bt->data);
    InorderTraverse(bt->right);
}
// 2. 전위 순위 함수
void PreorderTraverse(BTreeNode *bt)
{
    if (bt == NULL)
        return;

    printf("%d ", bt->data);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}
// 3. 후위 순회 함수
void PostorderTraverse(BTreeNode *bt)
{
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left);
    PostorderTraverse(bt->right);
    printf("%d ", bt->data);
}
int main()
{
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    BTreeNode *bt5 = MakeBTreeNode();
    BTreeNode *bt6 = MakeBTreeNode();
    BTreeNode *bt7 = MakeBTreeNode();
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);
    SetData(bt7, 7);
    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeLeftSubTree(bt3, bt6);
    MakeRightSubTree(bt3, bt7);

    PreorderTraverse(bt1);
    printf("\n");
    InorderTraverse(bt1);
    printf("\n");
    PostorderTraverse(bt1);

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