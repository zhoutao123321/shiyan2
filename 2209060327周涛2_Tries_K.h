#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHARS 26 // 假设只处理小写字母

// Trie 树节点结构
typedef struct TrieNode {
    int isEndOfWord; // 标记是否是一个单词的结尾
    struct TrieNode* children[NUM_CHARS]; // 子节点指针数组，每个节点有 26 个子节点
} TrieNode;

// 函数原型

// 创建一个新的 Trie 树节点
// 返回：新创建的 Trie 树节点指针
TrieNode* createNode();

// 在 Trie 树中插入一个单词
// 参数：root - Trie 树的根节点
//      key - 要插入的单词
void insert(TrieNode* root, const char* key);

// 在 Trie 树中搜索一个单词
// 参数：root - Trie 树的根节点
//      key - 要搜索的单词
// 返回：如果找到返回 1，否则返回 0
int search(TrieNode* root, const char* key);

// 从 Trie 树中删除一个单词
// 参数：root - Trie 树的根节点
//      key - 要删除的单词
void deleteKeywords(TrieNode* root, const char* key);

// 按字典序遍历 Trie 树中的单词，并按指定的列数显示
// 参数：root - Trie 树的根节点
//      prefix - 当前前缀
//      level - 当前遍历到的层级
//      count - 当前已输出的单词计数
//      columns - 每行显示的列数
void display(TrieNode* root, char* prefix, int level, int* count, int columns);

// 按指定列数显示 Trie 树中的单词
// 参数：root - Trie 树的根节点
//      columns - 每行显示的列数
void displayByColumns(TrieNode* root, int columns);

// 初始化 Trie 树，插入 C 语言的所有关键字
// 参数：root - Trie 树的根节点
void initKeywords(TrieNode* root);

// 显示菜单
void displayMenu();

// 判断一个单词是否为 C 语言的关键字
// 参数：root - Trie 树的根节点
//      key - 要判断的单词
// 返回：如果是关键字返回 1，否则返回 0
int isKeyword(TrieNode* root, const char* key);

