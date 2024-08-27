#define _CRT_SECURE_NO_WARNINGS // ���ð�ȫ����

#include "BST_K.h"

// ��ʾ�˵�
void DisplayMenu() {
    printf("\nMenu:\n");
    printf("1. ����ؼ���\n");
    printf("2. ɾ���ؼ���\n");
    printf("3. ���ҹؼ���\n");
    printf("4. �����ؼ���\n");
    printf("5. �ж��Ƿ�Ϊ�ؼ���\n");
    printf("6. �˳�\n");
    printf("���������ѡ��: ");
}

// �����µĽڵ�
TreeNode* CreateNode(const char* key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); // �����ڴ�
    strcpy(newNode->key, key); // ���ƹؼ���
    newNode->left = newNode->right = NULL; // ��ʼ�������ӽڵ�Ϊ��
    return newNode;
}

// ����ڵ�
TreeNode* Insert(TreeNode* root, const char* key) {
    if (root == NULL) { // �����ǰ�ڵ�Ϊ�գ��򴴽��µĽڵ�
        return CreateNode(key); // �����´����Ľڵ���Ϊ�����ĸ��ڵ�
    }
    if (strcmp(key, root->key) < 0) { // �������Ĺؼ���С�ڵ�ǰ�ڵ�Ĺؼ���
        root->left = Insert(root->left, key); // �ݹ�ؽ��ؼ��ֲ���������
    }
    else if (strcmp(key, root->key) > 0) { // �������Ĺؼ��ִ��ڵ�ǰ�ڵ�Ĺؼ���
        root->right = Insert(root->right, key); // �ݹ�ؽ��ؼ��ֲ���������
    }
    // ����ؼ��ֵ��ڵ�ǰ�ڵ�Ĺؼ��֣�ʲô������������BST�в������ظ��ؼ��֣�
    return root; // ���ص�ǰ�ڵ���Ϊ�����ĸ��ڵ�
}

// ������Сֵ�ڵ�
TreeNode* FindMin(TreeNode* root) {
    while (root->left != NULL) root = root->left; // һֱ���������ƶ�
    return root;
}

// ɾ���ڵ�
TreeNode* Delete(TreeNode* root, const char* key) {
    if (root == NULL) return root; // �����Ϊ�գ�ֱ�ӷ���
    if (strcmp(key, root->key) < 0) {
        root->left = Delete(root->left, key); // �ݹ�ɾ��������
    }
    else if (strcmp(key, root->key) > 0) {
        root->right = Delete(root->right, key); // �ݹ�ɾ��������
    }
    else {
        // �ҵ�Ҫɾ���Ľڵ�
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root); // �ͷŽڵ��ڴ�
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root); // �ͷŽڵ��ڴ�
            return temp;
        }
        TreeNode* temp = FindMin(root->right); // �ҵ�����������Сֵ�ڵ�
        strcpy(root->key, temp->key); // �滻�ؼ���
        root->right = Delete(root->right, temp->key); // ɾ������������Сֵ�ڵ�
    }
    return root;
}

// ���ҽڵ�
TreeNode* Search(TreeNode* root, const char* key) {
    if (root == NULL || strcmp(key, root->key) == 0) {
        return root; // ����ڵ�Ϊ�ջ����ҵ��ؼ��֣����ؽڵ�
    }
    if (strcmp(key, root->key) < 0) {
        return Search(root->left, key); // �ݹ����������
    }
    else {
        return Search(root->right, key); // �ݹ����������
    }
}

// �������
void InOrder(TreeNode* root, int* count, int columns) {
    if (root != NULL) {
        InOrder(root->left, count, columns); // �ݹ����������
        printf("%-10s", root->key); // ��ӡ�ؼ��֣�����룬ռ10���ַ����
        (*count)++;
        if (*count % columns == 0) {
            printf("\n"); // ÿcolumns���ؼ��ֻ���
        }
        InOrder(root->right, count, columns); // �ݹ����������
    }
}

// ��������ķ�װ����
void InOrderTraversal(TreeNode* root, int columns) {
    int count = 0;
    InOrder(root, &count, columns); // �����������
    if (count % columns != 0) {
        printf("\n"); // ������һ��δ��columns���ؼ��֣�����
    }
}

// �ж��Ƿ�Ϊ�ؼ���
int IsKeyword(TreeNode* root, const char* key) {
    return Search(root, key) != NULL; // ���ò��Һ����ж��Ƿ�Ϊ�ؼ���
}
