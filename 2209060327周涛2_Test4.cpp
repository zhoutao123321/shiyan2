#define _CRT_SECURE_NO_WARNINGS // ���ð�ȫ����

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
            printf("������Ҫ����Ĺؼ���: ");
            scanf("%s", key);
            insert(root, key);
            printf("�ؼ��� '%s' �Ѳ��롣\n", key);
            break;
        case 2:
            printf("������Ҫɾ���Ĺؼ���: ");
            scanf("%s", key);
            deleteKeywords(root, key); 
            printf("�ؼ��� '%s' ��ɾ����\n", key);
            break;
        case 3:
            printf("������Ҫ���ҵĹؼ���: ");
            scanf("%s", key);
            if (search(root, key)) {
                printf("�ؼ��� '%s' ���ڡ�\n", key);
            }
            else {
                printf("�ؼ��� '%s' �����ڡ�\n", key);
            }
            break;
        case 4:
            printf("��ǰ�ؼ��ֿ��еĹؼ���:\n");
            displayByColumns(root, 5); // ÿ����ʾ 5 ���ؼ���
            break;
        case 5:
            printf("��ʼ���ؼ��ֿ⡣\n");
            initKeywords(root); // ��ʼ���ؼ��ֿ�
            printf("�ؼ��ֿ��ѳ�ʼ����\n");
            break;
        case 6:
            printf("������Ҫ�жϵĵ���: ");
            scanf("%s", key);
            if (isKeyword(root, key)) { 
                printf("%s ��C���ԵĹؼ���\n", key);
            }
            else {
                printf("%s ����C���ԵĹؼ���\n", key);
            }
            break;
        case 7:
            printf("�˳�����\n");
            return 0;
        default:
            printf("��Ч��ѡ�����������롣\n");
        }
    }

    return 0;
}
