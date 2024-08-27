#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义BST节点结构
typedef struct TreeNode {
    char key[20]; // 关键字
    struct TreeNode* left; // 左子节点
    struct TreeNode* right; // 右子节点
} TreeNode;

// 函数原型
TreeNode* Insert(TreeNode* root, const char* key); // 插入节点
TreeNode* Delete(TreeNode* root, const char* key); // 删除节点
TreeNode* Search(TreeNode* root, const char* key); // 查找节点
void InOrder(TreeNode* root, int* count, int columns); // 中序遍历
void InOrderTraversal(TreeNode* root, int columns); // 中序遍历的封装函数
TreeNode* CreateNode(const char* key); // 创建节点
TreeNode* FindMin(TreeNode* root); // 查找最小值节点
int IsKeyword(TreeNode* root, const char* key); // 判断是否为关键字
void DisplayMenu(); // 显示菜单
