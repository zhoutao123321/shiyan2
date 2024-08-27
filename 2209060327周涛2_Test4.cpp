#define _CRT_SECURE_NO_WARNINGS // 禁用安全警告

#include "Tries_K.h"


int main() {
    TrieNode* root = createNode();
    int choice;
    char key[20];

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("请输入要插入的关键字: ");
            scanf("%s", key);
            insert(root, key);
            printf("关键字 '%s' 已插入。\n", key);
            break;
        case 2:
            printf("请输入要删除的关键字: ");
            scanf("%s", key);
            deleteKeywords(root, key); 
            printf("关键字 '%s' 已删除。\n", key);
            break;
        case 3:
            printf("请输入要查找的关键字: ");
            scanf("%s", key);
            if (search(root, key)) {
                printf("关键字 '%s' 存在。\n", key);
            }
            else {
                printf("关键字 '%s' 不存在。\n", key);
            }
            break;
        case 4:
            printf("当前关键字库中的关键字:\n");
            displayByColumns(root, 5); // 每行显示 5 个关键字
            break;
        case 5:
            printf("初始化关键字库。\n");
            initKeywords(root); // 初始化关键字库
            printf("关键字库已初始化。\n");
            break;
        case 6:
            printf("请输入要判断的单词: ");
            scanf("%s", key);
            if (isKeyword(root, key)) { 
                printf("%s 是C语言的关键字\n", key);
            }
            else {
                printf("%s 不是C语言的关键字\n", key);
            }
            break;
        case 7:
            printf("退出程序。\n");
            return 0;
        default:
            printf("无效的选择，请重新输入。\n");
        }
    }

    return 0;
}
