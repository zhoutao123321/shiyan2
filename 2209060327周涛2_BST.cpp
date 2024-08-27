#include "BST.h"

// 销毁二叉排序树 bt(后序遍历)
void DestroyBST(BSTNode*& bt) {
    if (bt) {
        DestroyBST(bt->lchild);  // 递归销毁左子树
        DestroyBST(bt->rchild);  // 递归销毁右子树
        free(bt);                // 释放当前节点
        bt = NULL;               // 将指针置空
    }
}

// 创建空二叉排序树
BSTNode* InitBST(BSTNode*& bt) {
    bt = NULL;  // 初始化根节点为 NULL
    return bt;  // 返回空树的根节点
}

// 在二叉排序树 bt 中插入一个关键字为 k 的结点
BSTNode* InsertBST(BSTNode* bt, KeyType k) {
    if (!bt) {
        // 如果当前节点为空，创建新节点
        bt = (BSTNode*)malloc(sizeof(BSTNode)); // 分配内存
        bt->key = k;                           // 设置节点的关键字
        bt->lchild = bt->rchild = NULL;        // 初始化左右孩子为 NULL
    }
    else if (k < bt->key) {
        // 关键字小于当前节点关键字，插入左子树
        bt->lchild = InsertBST(bt->lchild, k);
    }
    else if (k > bt->key) {
        // 关键字大于当前节点关键字，插入右子树
        bt->rchild = InsertBST(bt->rchild, k);
    }
    return bt;  // 返回插入后的根节点
}

// 输出一棵排序二叉树，使用（）标明子树嵌套层次
void DispBST(BSTNode* bt) {
    if (bt) {
        printf("%d(", bt->key); // 打印当前节点关键字
        DispBST(bt->lchild);    // 打印左子树
        printf(",");            // 打印分隔符
        DispBST(bt->rchild);    // 打印右子树
        printf(")");            // 打印右括号
    }
    else {
        printf("");  // 当前节点为空时，打印空字符串
    }
}

// 递归算法：在二叉排序树 bt 中查找关键字为 k 的结点
BSTNode* SearchBST(BSTNode* bt, KeyType k) {
    if (!bt || bt->key == k) {
        return bt;  // 找到节点或树为空时返回当前节点
    }
    else if (k < bt->key) {
        return SearchBST(bt->lchild, k);  // 在左子树中查找
    }
    else {
        return SearchBST(bt->rchild, k);  // 在右子树中查找
    }
}

// 在 bt 中删除关键字为 k 的结点
BSTNode* DeleteBST(BSTNode* bt, KeyType k) {
    if (!bt) return NULL;  // 树为空时返回 NULL

    if (k < bt->key) {
        bt->lchild = DeleteBST(bt->lchild, k);  // 在左子树中删除
    }
    else if (k > bt->key) {
        bt->rchild = DeleteBST(bt->rchild, k);  // 在右子树中删除
    }
    else {
        // 找到要删除的节点
        if (!bt->lchild) {
            // 节点只有右子树或没有子树
            BSTNode* temp = bt->rchild;
            free(bt);  // 释放当前节点
            return temp;  // 返回右子树的根节点
        }
        else if (!bt->rchild) {
            // 节点只有左子树
            BSTNode* temp = bt->lchild;
            free(bt);  // 释放当前节点
            return temp;  // 返回左子树的根节点
        }
        // 节点有两个子树
        BSTNode* temp = bt->rchild;
        while (temp && temp->lchild) {
            temp = temp->lchild;  // 找到右子树的最左节点
        }
        bt->key = temp->key;  // 用右子树的最左节点替换当前节点
        bt->rchild = DeleteBST(bt->rchild, temp->key);  // 删除右子树的最左节点
    }
    return bt;  // 返回删除后的根节点
}

// 判空
bool BSTEmpty(BSTNode* bt) {
    return bt == NULL;  // 判断根节点是否为空
}

// 求树高
int BSTHeight(BSTNode* bt) {
    if (!bt) return 0;  // 树为空时，高度为0
    int lheight = BSTHeight(bt->lchild);  // 计算左子树高度
    int rheight = BSTHeight(bt->rchild);  // 计算右子树高度
    return (lheight > rheight ? lheight : rheight) + 1;  // 返回树的最大高度加1
}

// 先序遍历的递归算法
void PreOrder(BSTNode* bt) {
    if (bt) {
        printf("%d ", bt->key);  // 访问根节点
        PreOrder(bt->lchild);    // 先序遍历左子树
        PreOrder(bt->rchild);    // 先序遍历右子树
    }
}

// 中序遍历的递归算法
void InOrder(BSTNode* bt) {
    if (bt) {
        InOrder(bt->lchild);     // 中序遍历左子树
        printf("%d ", bt->key);  // 访问根节点
        InOrder(bt->rchild);     // 中序遍历右子树
    }
}

// 后序遍历的递归算法
void PostOrder(BSTNode* bt) {
    if (bt) {
        PostOrder(bt->lchild);   // 后序遍历左子树
        PostOrder(bt->rchild);   // 后序遍历右子树
        printf("%d ", bt->key);  // 访问根节点
    }
}
