#define _CRT_SECURE_NO_WARNINGS // ���ð�ȫ����

#include"BST_K.h"

int main() {
    TreeNode* root = NULL;
    int choice;
    char key[20];

    // �����ʼ��C���Թؼ���
    const char* keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < n; i++) {
        root = Insert(root, keywords[i]);
    }

    while (1) {
        DisplayMenu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("������Ҫ����Ĺؼ���: ");
            scanf("%s", key);
            root = Insert(root, key);
            printf("�ؼ��ֲ���ɹ�\n");
            break;
        case 2:
            printf("������Ҫɾ���Ĺؼ���: ");
            scanf("%s", key);
            root = Delete(root, key);
            printf("�ؼ���ɾ���ɹ�\n");
            break;
        case 3:
            printf("������Ҫ���ҵĹؼ���: ");
            scanf("%s", key);
            if (Search(root, key)) {
                printf("�ҵ��ؼ���: %s\n", key);
            }
            else {
                printf("δ�ҵ��ؼ���: %s\n", key);
            }
            break;
        case 4:
            printf("�ؼ��ֿ�����(�������): \n");
            InOrderTraversal(root, 5); // ÿ��5���ؼ���
            break;
        case 5:
            printf("������Ҫ�жϵĵ���: ");
            scanf("%s", key);
            if (IsKeyword(root, key)) {
                printf("%s ��C���ԵĹؼ���\n", key);
            }
            else {
                printf("%s ����C���ԵĹؼ���\n", key);
            }
            break;
        case 6:
            printf("�˳�����\n");
            exit(0);
        default:
            printf("��Ч��ѡ������������\n");
        }
    }
    return 0;
}
