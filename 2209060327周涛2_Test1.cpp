#include "BST.h"

int main() {
    BSTNode* bst;
    bst = InitBST(bst);

    printf("插入节点: 50, 30, 70, 20, 40, 60, 80\n");
    bst = InsertBST(bst, 50);
    bst = InsertBST(bst, 30);
    bst = InsertBST(bst, 70);
    bst = InsertBST(bst, 20);
    bst = InsertBST(bst, 40);
    bst = InsertBST(bst, 60);
    bst = InsertBST(bst, 80);

    printf("二叉排序树: ");
    DispBST(bst);
    printf("\n");

    printf("查找节点 40: ");
    BSTNode* searchResult = SearchBST(bst, 40);
    if (searchResult) {
        printf("找到节点: %d\n", searchResult->key);
    }
    else {
        printf("未找到节点 40\n");
    }

    printf("查找节点 100: ");
    searchResult = SearchBST(bst, 100);
    if (searchResult) {
        printf("找到节点: %d\n", searchResult->key);
    }
    else {
        printf("未找到节点 100\n");
    }

    printf("树高: %d\n", BSTHeight(bst));

    printf("先序遍历: ");
    PreOrder(bst);
    printf("\n");

    printf("中序遍历: ");
    InOrder(bst);
    printf("\n");

    printf("后序遍历: ");
    PostOrder(bst);
    printf("\n");

    printf("删除节点 20\n");
    bst = DeleteBST(bst, 20);
    DispBST(bst);
    printf("\n");

    printf("删除节点 30\n");
    bst = DeleteBST(bst, 30);
    DispBST(bst);
    printf("\n");

    printf("删除节点 50\n");
    bst = DeleteBST(bst, 50);
    DispBST(bst);
    printf("\n");

    printf("判空: %s\n", BSTEmpty(bst) ? "空" : "不空");

    printf("销毁树\n");
    DestroyBST(bst);
    printf("判空: %s\n", BSTEmpty(bst) ? "空" : "不空");

    return 0;
}
