//���� Ʈ��
//������ �´� ��ȸ �Լ��� ����
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

//��ȸ �Լ�
typedef void VisitFuncPtr(BTData data);
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);  //����
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);   //����
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action); //����
//�Լ� �����͸� �̿��� ��� �Լ�
void DeleteTree(BTData data)
{
    printf("%d ", data);
}
int main()
{
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    BTreeNode *bt5 = MakeBTreeNode();
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    /*Tree�� ���
                1
            2       3
        4       5
    */

    PreorderTraverse(bt1, DeleteTree);
    printf("\n");
    InorderTraverse(bt1, DeleteTree);
    printf("\n");
    PostorderTraverse(bt1, DeleteTree);
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
//���� Ʈ���� ��ȸ
// 1. ���� ��ȸ �Լ�
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}
// 2. ���� ���� �Լ�
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}
// 3. ���� ��ȸ �Լ�
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}