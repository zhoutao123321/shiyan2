#define _CRT_SECURE_NO_WARNINGS // 禁用安全警告

#include"BST_K.h"

int main() {
    TreeNode* root = NULL;
    int choice;
    char key[20];

    // 插入初始的C语言关键字
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
            printf("请输入要插入的关键字: ");
            scanf("%s", key);
            root = Insert(root, key);
            printf("关键字插入成功\n");
            break;
        case 2:
            printf("请输入要删除的关键字: ");
            scanf("%s", key);
            root = Delete(root, key);
            printf("关键字删除成功\n");
            break;
        case 3:
            printf("请输入要查找的关键字: ");
            scanf("%s", key);
            if (Search(root, key)) {
                printf("找到关键字: %s\n", key);
            }
            else {
                printf("未找到关键字: %s\n", key);
            }
            break;
        case 4:
            printf("关键字库内容(中序遍历): \n");
            InOrderTraversal(root, 5); // 每行5个关键字
            break;
        case 5:
            printf("请输入要判断的单词: ");
            scanf("%s", key);
            if (IsKeyword(root, key)) {
                printf("%s 是C语言的关键字\n", key);
            }
            else {
                printf("%s 不是C语言的关键字\n", key);
            }
            break;
        case 6:
            printf("退出程序\n");
            exit(0);
        default:
            printf("无效的选择，请重新输入\n");
        }
    }
    return 0;
}
