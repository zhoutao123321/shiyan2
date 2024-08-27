#define _CRT_SECURE_NO_WARNINGS // 禁用安全警告

#include"Tries_K.h"

// 显示菜单
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. 插入关键字\n");
    printf("2. 删除关键字\n");
    printf("3. 查找关键字\n");
    printf("4. 遍历关键字\n");
    printf("5. 初始化关键字库\n");
    printf("6. 判断是否为关键字\n");
    printf("7. 退出\n");
    printf("请输入你的选择: ");
}

// 创建新的 Trie 节点
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0; // 初始化为非单词结尾
    for (int i = 0; i < NUM_CHARS; i++) {
        node->children[i] = NULL; // 初始化所有子节点为空
    }
    return node;
}

// 插入关键字
void insert(TrieNode* root, const char* key) {
    TrieNode* current = root;
    while (*key) {
        // 如果当前字符对应的子节点为空，则创建新节点
        if (current->children[*key - 'a'] == NULL) {
            current->children[*key - 'a'] = createNode();
        }
        current = current->children[*key - 'a'];
        key++;
    }
    current->isEndOfWord = 1; // 标记单词结尾
}

// 查找关键字
int search(TrieNode* root, const char* key) {
    TrieNode* current = root;
    while (*key) {
        // 如果当前字符对应的子节点为空，则单词不存在
        if (current->children[*key - 'a'] == NULL) {
            return 0;
        }
        current = current->children[*key - 'a'];
        key++;
    }
    return current->isEndOfWord; // 返回是否为单词结尾
}

// 删除关键字的辅助函数
int deleteHelper(TrieNode* root, const char* key, int depth) {
    if (root == NULL) return 0;

    if (*key == '\0') {
        if (root->isEndOfWord) {
            root->isEndOfWord = 0; // 取消单词结尾标记
            for (int i = 0; i < NUM_CHARS; i++) {
                if (root->children[i] != NULL) return 0; // 如果还有子节点则不删除
            }
            return 1; // 没有子节点可以删除当前节点
        }
        return 0;
    }

    int index = *key - 'a';
    if (deleteHelper(root->children[index], key + 1, depth + 1)) {
        free(root->children[index]); // 释放子节点内存
        root->children[index] = NULL;

        // 当前节点不是单词结尾且没有其他子节点可以删除当前节点
        return !root->isEndOfWord && depth != 0;
    }
    return 0;
}

// 删除关键字
void deleteKeywords(TrieNode* root, const char* key) {
    deleteHelper(root, key, 0);
}

// 按字典序遍历关键字，并按指定列数输出
void display(TrieNode* root, char* prefix, int level, int* count, int columns) {
    if (root->isEndOfWord) {
        prefix[level] = '\0';
        printf("%-10s", prefix); // %-10s 左对齐，宽度10
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

// 按指定列数显示 Trie 树中的单词
void displayByColumns(TrieNode* root, int columns) {
    char prefix[100]; // 假设最大关键字长度不超过100
    int count = 0;
    display(root, prefix, 0, &count, columns);
    if (count % columns != 0) {
        printf("\n");
    }
}

// 初始化关键字库
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

// 判断是否为关键字
int isKeyword(TrieNode* root, const char* key) {
    return search(root, key);
}
