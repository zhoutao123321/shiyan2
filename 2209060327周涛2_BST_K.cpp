#define _CRT_SECURE_NO_WARNINGS // 禁用安全警告

#include "BST_K.h"

// 显示菜单
void DisplayMenu() {
    printf("\nMenu:\n");
    printf("1. 插入关键字\n");
    printf("2. 删除关键字\n");
    printf("3. 查找关键字\n");
    printf("4. 遍历关键字\n");
    printf("5. 判断是否为关键字\n");
    printf("6. 退出\n");
    printf("请输入你的选择: ");
}

// 创建新的节点
TreeNode* CreateNode(const char* key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); // 分配内存
    strcpy(newNode->key, key); // 复制关键字
    newNode->left = newNode->right = NULL; // 初始化左右子节点为空
    return newNode;
}

// 插入节点
TreeNode* Insert(TreeNode* root, const char* key) {
    if (root == NULL) { // 如果当前节点为空，则创建新的节点
        return CreateNode(key); // 返回新创建的节点作为子树的根节点
    }
    if (strcmp(key, root->key) < 0) { // 如果插入的关键字小于当前节点的关键字
        root->left = Insert(root->left, key); // 递归地将关键字插入左子树
    }
    else if (strcmp(key, root->key) > 0) { // 如果插入的关键字大于当前节点的关键字
        root->right = Insert(root->right, key); // 递归地将关键字插入右子树
    }
    // 如果关键字等于当前节点的关键字，什么都不做（假设BST中不允许重复关键字）
    return root; // 返回当前节点作为子树的根节点
}

// 查找最小值节点
TreeNode* FindMin(TreeNode* root) {
    while (root->left != NULL) root = root->left; // 一直向左子树移动
    return root;
}

// 删除节点
TreeNode* Delete(TreeNode* root, const char* key) {
    if (root == NULL) return root; // 如果树为空，直接返回
    if (strcmp(key, root->key) < 0) {
        root->left = Delete(root->left, key); // 递归删除左子树
    }
    else if (strcmp(key, root->key) > 0) {
        root->right = Delete(root->right, key); // 递归删除右子树
    }
    else {
        // 找到要删除的节点
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root); // 释放节点内存
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root); // 释放节点内存
            return temp;
        }
        TreeNode* temp = FindMin(root->right); // 找到右子树的最小值节点
        strcpy(root->key, temp->key); // 替换关键字
        root->right = Delete(root->right, temp->key); // 删除右子树的最小值节点
    }
    return root;
}

// 查找节点
TreeNode* Search(TreeNode* root, const char* key) {
    if (root == NULL || strcmp(key, root->key) == 0) {
        return root; // 如果节点为空或者找到关键字，返回节点
    }
    if (strcmp(key, root->key) < 0) {
        return Search(root->left, key); // 递归查找左子树
    }
    else {
        return Search(root->right, key); // 递归查找右子树
    }
}

// 中序遍历
void InOrder(TreeNode* root, int* count, int columns) {
    if (root != NULL) {
        InOrder(root->left, count, columns); // 递归遍历左子树
        printf("%-10s", root->key); // 打印关键字，左对齐，占10个字符宽度
        (*count)++;
        if (*count % columns == 0) {
            printf("\n"); // 每columns个关键字换行
        }
        InOrder(root->right, count, columns); // 递归遍历右子树
    }
}

// 中序遍历的封装函数
void InOrderTraversal(TreeNode* root, int columns) {
    int count = 0;
    InOrder(root, &count, columns); // 调用中序遍历
    if (count % columns != 0) {
        printf("\n"); // 如果最后一行未满columns个关键字，换行
    }
}

// 判断是否为关键字
int IsKeyword(TreeNode* root, const char* key) {
    return Search(root, key) != NULL; // 调用查找函数判断是否为关键字
}
