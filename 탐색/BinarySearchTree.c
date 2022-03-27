//���� Ž�� Ʈ��
// left < root && root < right�� ������ ����
#include <stdio.h>
#include <stdlib.h>

typedef int BTData;
typedef struct _bTreeNode //���� ����Ʈ�� ����
{
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;
// ���� Ʈ���� �⺻ �Լ� ����
BTreeNode *MakeBTreeNode(void);           //����� ����
BTData GetData(BTreeNode *bt);            //��忡 ����� �����͸� ��ȯ
void SetData(BTreeNode *bt, BTData data); //��忡 �����͸� ����

BTreeNode *GetLeftSubTree(BTreeNode *bt);  //���� ���� Ʈ�� �ּ� �� ��ȯ
BTreeNode *GetRightSubTree(BTreeNode *bt); //������ ���� Ʈ�� �ּ� �� ��ȯ

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub); //���� ���� Ʈ���� �����Ѵ�.
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

//����Ž�� Ʈ���� ���� �Լ�
typedef BTData BSTData;
void BSTMakeAndInit(BTreeNode **pRoot);          // BST�� ���� �� �ʱ�ȭ
BSTData BSTGetNodeData(BTreeNode *bst);          //��忡 ����� ������ ��ȯ
void BSTInsert(BTreeNode **pRoot, BSTData data); // BST�� ������� ������ ����(����� ���� ����)
//����Ž�� Ʈ���� ��� Ž��
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target);

int main()
{
    BTreeNode *bstRoot;       // BST�� ��Ʈ ���
    BSTMakeAndInit(&bstRoot); // BST���� �� �ʱ�ȭ

    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);

    BTreeNode *sNode;
    // 1Ž��
    sNode = BSTSearch(bstRoot, 1); //������ Ž��
    if (sNode == NULL)
        printf("Ž�� ����\n");
    else
        printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));
    // 4 Ž��
    sNode = BSTSearch(bstRoot, 4); //������ Ž��
    if (sNode == NULL)
        printf("Ž�� ����\n");
    else
        printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));
    // 6 Ž��
    sNode = BSTSearch(bstRoot, 6); //������ Ž��
    if (sNode == NULL)
        printf("Ž�� ����\n");
    else
        printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));
    // 7 Ž��
    sNode = BSTSearch(bstRoot, 7); //������ Ž��
    if (sNode == NULL)
        printf("Ž�� ����\n");
    else
        printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));
    return 0;
}
BTreeNode *MakeBTreeNode(void) //����� ����
{
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}
BTData GetData(BTreeNode *bt) //��忡 ����� �����͸� ��ȯ
{
    return bt->data;
}
void SetData(BTreeNode *bt, BTData data) //��忡 �����͸� ����
{
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt) //���� ���� Ʈ�� �ּ� �� ��ȯ
{
    return bt->left;
}
BTreeNode *GetRightSubTree(BTreeNode *bt) //������ ���� Ʈ�� �ּ� �� ��ȯ
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) //���� ���� Ʈ���� �����Ѵ�.
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

//����Ž�� Ʈ���� ���� �Լ�
void BSTMakeAndInit(BTreeNode **pRoot) // BST�� ���� �� �ʱ�ȭ
{
    *pRoot = NULL;
}
BSTData BSTGetNodeData(BTreeNode *bst) //��忡 ����� ������ ��ȯ
{
    return GetData(bst);
}
void BSTInsert(BTreeNode **pRoot, BSTData data) // BST�� ������� ������ ����(����� ���� ����)
{
    BTreeNode *pNode = NULL;   // parent node
    BTreeNode *cNode = *pRoot; // current node;
    BTreeNode *nNode = NULL;   // new node;

    while (cNode != NULL)
    {
        if (data == GetData(cNode))
            return; //������ �ߺ� ��� X

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
//����Ž�� Ʈ���� ��� Ž��
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