#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����BST�ڵ�ṹ
typedef struct TreeNode {
    char key[20]; // �ؼ���
    struct TreeNode* left; // ���ӽڵ�
    struct TreeNode* right; // ���ӽڵ�
} TreeNode;

// ����ԭ��
TreeNode* Insert(TreeNode* root, const char* key); // ����ڵ�
TreeNode* Delete(TreeNode* root, const char* key); // ɾ���ڵ�
TreeNode* Search(TreeNode* root, const char* key); // ���ҽڵ�
void InOrder(TreeNode* root, int* count, int columns); // �������
void InOrderTraversal(TreeNode* root, int columns); // ��������ķ�װ����
TreeNode* CreateNode(const char* key); // �����ڵ�
TreeNode* FindMin(TreeNode* root); // ������Сֵ�ڵ�
int IsKeyword(TreeNode* root, const char* key); // �ж��Ƿ�Ϊ�ؼ���
void DisplayMenu(); // ��ʾ�˵�
