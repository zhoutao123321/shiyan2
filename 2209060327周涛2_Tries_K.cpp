#define _CRT_SECURE_NO_WARNINGS // ���ð�ȫ����

#include"Tries_K.h"

// ��ʾ�˵�
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. ����ؼ���\n");
    printf("2. ɾ���ؼ���\n");
    printf("3. ���ҹؼ���\n");
    printf("4. �����ؼ���\n");
    printf("5. ��ʼ���ؼ��ֿ�\n");
    printf("6. �ж��Ƿ�Ϊ�ؼ���\n");
    printf("7. �˳�\n");
    printf("���������ѡ��: ");
}

// �����µ� Trie �ڵ�
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0; // ��ʼ��Ϊ�ǵ��ʽ�β
    for (int i = 0; i < NUM_CHARS; i++) {
        node->children[i] = NULL; // ��ʼ�������ӽڵ�Ϊ��
    }
    return node;
}

// ����ؼ���
void insert(TrieNode* root, const char* key) {
    TrieNode* current = root;
    while (*key) {
        // �����ǰ�ַ���Ӧ���ӽڵ�Ϊ�գ��򴴽��½ڵ�
        if (current->children[*key - 'a'] == NULL) {
            current->children[*key - 'a'] = createNode();
        }
        current = current->children[*key - 'a'];
        key++;
    }
    current->isEndOfWord = 1; // ��ǵ��ʽ�β
}

// ���ҹؼ���
int search(TrieNode* root, const char* key) {
    TrieNode* current = root;
    while (*key) {
        // �����ǰ�ַ���Ӧ���ӽڵ�Ϊ�գ��򵥴ʲ�����
        if (current->children[*key - 'a'] == NULL) {
            return 0;
        }
        current = current->children[*key - 'a'];
        key++;
    }
    return current->isEndOfWord; // �����Ƿ�Ϊ���ʽ�β
}

// ɾ���ؼ��ֵĸ�������
int deleteHelper(TrieNode* root, const char* key, int depth) {
    if (root == NULL) return 0;

    if (*key == '\0') {
        if (root->isEndOfWord) {
            root->isEndOfWord = 0; // ȡ�����ʽ�β���
            for (int i = 0; i < NUM_CHARS; i++) {
                if (root->children[i] != NULL) return 0; // ��������ӽڵ���ɾ��
            }
            return 1; // û���ӽڵ����ɾ����ǰ�ڵ�
        }
        return 0;
    }

    int index = *key - 'a';
    if (deleteHelper(root->children[index], key + 1, depth + 1)) {
        free(root->children[index]); // �ͷ��ӽڵ��ڴ�
        root->children[index] = NULL;

        // ��ǰ�ڵ㲻�ǵ��ʽ�β��û�������ӽڵ����ɾ����ǰ�ڵ�
        return !root->isEndOfWord && depth != 0;
    }
    return 0;
}

// ɾ���ؼ���
void deleteKeywords(TrieNode* root, const char* key) {
    deleteHelper(root, key, 0);
}

// ���ֵ�������ؼ��֣�����ָ���������
void display(TrieNode* root, char* prefix, int level, int* count, int columns) {
    if (root->isEndOfWord) {
        prefix[level] = '\0';
        printf("%-10s", prefix); // %-10s ����룬���10
        (*count)++;
        if (*count % columns == 0) {
            printf("\n");
        }
    }

    for (int i = 0; i < NUM_CHARS; i++) {
        if (root->children[i]) {
            prefix[level] = 'a' + i;
            display(root->children[i], prefix, level + 1, count, columns);
        }
    }
}

// ��ָ��������ʾ Trie ���еĵ���
void displayByColumns(TrieNode* root, int columns) {
    char prefix[100]; // �������ؼ��ֳ��Ȳ�����100
    int count = 0;
    display(root, prefix, 0, &count, columns);
    if (count % columns != 0) {
        printf("\n");
    }
}

// ��ʼ���ؼ��ֿ�
void initKeywords(TrieNode* root) {
    const char* keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        insert(root, keywords[i]);
    }
}

// �ж��Ƿ�Ϊ�ؼ���
int isKeyword(TrieNode* root, const char* key) {
    return search(root, key);
}
