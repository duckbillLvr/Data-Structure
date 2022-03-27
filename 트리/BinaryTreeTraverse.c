//���� Ʈ��
//��ȸ �Լ��� ����
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
//���� Ʈ���� ��ȸ
// 1. ���� ��ȸ �Լ�
void InorderTraverse(BTreeNode *bt)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left);
    printf("%d ", bt->data);
    InorderTraverse(bt->right);
}
// 2. ���� ���� �Լ�
void PreorderTraverse(BTreeNode *bt)
{
    if (bt == NULL)
        return;

    printf("%d ", bt->data);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}
// 3. ���� ��ȸ �Լ�
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