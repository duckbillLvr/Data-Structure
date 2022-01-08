//���� Ʈ��
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