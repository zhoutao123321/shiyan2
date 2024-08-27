#include "BST.h"

int main() {
    BSTNode* bst;
    bst = InitBST(bst);

    printf("����ڵ�: 50, 30, 70, 20, 40, 60, 80\n");
    bst = InsertBST(bst, 50);
    bst = InsertBST(bst, 30);
    bst = InsertBST(bst, 70);
    bst = InsertBST(bst, 20);
    bst = InsertBST(bst, 40);
    bst = InsertBST(bst, 60);
    bst = InsertBST(bst, 80);

    printf("����������: ");
    DispBST(bst);
    printf("\n");

    printf("���ҽڵ� 40: ");
    BSTNode* searchResult = SearchBST(bst, 40);
    if (searchResult) {
        printf("�ҵ��ڵ�: %d\n", searchResult->key);
    }
    else {
        printf("δ�ҵ��ڵ� 40\n");
    }

    printf("���ҽڵ� 100: ");
    searchResult = SearchBST(bst, 100);
    if (searchResult) {
        printf("�ҵ��ڵ�: %d\n", searchResult->key);
    }
    else {
        printf("δ�ҵ��ڵ� 100\n");
    }

    printf("����: %d\n", BSTHeight(bst));

    printf("�������: ");
    PreOrder(bst);
    printf("\n");

    printf("�������: ");
    InOrder(bst);
    printf("\n");

    printf("�������: ");
    PostOrder(bst);
    printf("\n");

    printf("ɾ���ڵ� 20\n");
    bst = DeleteBST(bst, 20);
    DispBST(bst);
    printf("\n");

    printf("ɾ���ڵ� 30\n");
    bst = DeleteBST(bst, 30);
    DispBST(bst);
    printf("\n");

    printf("ɾ���ڵ� 50\n");
    bst = DeleteBST(bst, 50);
    DispBST(bst);
    printf("\n");

    printf("�п�: %s\n", BSTEmpty(bst) ? "��" : "����");

    printf("������\n");
    DestroyBST(bst);
    printf("�п�: %s\n", BSTEmpty(bst) ? "��" : "����");

    return 0;
}
