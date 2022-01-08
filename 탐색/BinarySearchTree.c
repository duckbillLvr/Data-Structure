//이진 탐색 트리
// left < root && root < right의 조건을 만족
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

//이진탐색 트리의 생성 함수
typedef BTData BSTData;
void BSTMakeAndInit(BTreeNode **pRoot);          // BST의 생성 및 초기화
BSTData BSTGetNodeData(BTreeNode *bst);          //노드에 저장된 데이터 반환
void BSTInsert(BTreeNode **pRoot, BSTData data); // BST를 대상으로 데이터 저장(노드의 생성 포함)
//이진탐색 트리의 노드 탐색
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target);

int main()
{
    BTreeNode *bstRoot;       // BST의 루트 노드
    BSTMakeAndInit(&bstRoot); // BST생성 및 초기화

    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);

    BTreeNode *sNode;
    // 1탐색
    sNode = BSTSearch(bstRoot, 1); //데이터 탐색
    if (sNode == NULL)
        printf("탐색 실패\n");
    else
        printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));
    // 4 탐색
    sNode = BSTSearch(bstRoot, 4); //데이터 탐색
    if (sNode == NULL)
        printf("탐색 실패\n");
    else
        printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));
    // 6 탐색
    sNode = BSTSearch(bstRoot, 6); //데이터 탐색
    if (sNode == NULL)
        printf("탐색 실패\n");
    else
        printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));
    // 7 탐색
    sNode = BSTSearch(bstRoot, 7); //데이터 탐색
    if (sNode == NULL)
        printf("탐색 실패\n");
    else
        printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));
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

//이진탐색 트리의 생성 함수
void BSTMakeAndInit(BTreeNode **pRoot) // BST의 생성 및 초기화
{
    *pRoot = NULL;
}
BSTData BSTGetNodeData(BTreeNode *bst) //노드에 저장된 데이터 반환
{
    return GetData(bst);
}
void BSTInsert(BTreeNode **pRoot, BSTData data) // BST를 대상으로 데이터 저장(노드의 생성 포함)
{
    BTreeNode *pNode = NULL;   // parent node
    BTreeNode *cNode = *pRoot; // current node;
    BTreeNode *nNode = NULL;   // new node;

    while (cNode != NULL)
    {
        if (data == GetData(cNode))
            return; //데이터 중복 허용 X

        pNode = cNode;
        if (GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    nNode = MakeBTreeNode();
    SetData(nNode, data);
    if (pNode != NULL)
    {
        if (data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else
        *pRoot = nNode;
}
//이진탐색 트리의 노드 탐색
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target)
{
    BTreeNode *cNode = bst; // current node
    BSTData cd;             // current Data

    while (cNode != NULL)
    {
        if (GetData(cNode) < target)
            cNode = GetRightSubTree(cNode);
        else if (GetData(cNode) > target)
            cNode = GetLeftSubTree(cNode);
        else
            return cNode;
    }
    return NULL;
}