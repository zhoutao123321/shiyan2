#pragma once

const int num_chars = 26; // 字母表大小

// 记录结构
struct Record {
    char key[50]; // 关键字（单词）
    // 可以根据需要扩展其他数据成员
};

// Trie 树节点结构
struct Trie_node {
    Record* data; // 指向记录的指针
    Trie_node* branch[num_chars]; // 子节点数组
};

// 初始化 Trie 树
void InitTrie(Trie_node*& root);

// 销毁 Trie 树
void DestroyTrie(Trie_node*& root);

// 判断 Trie 树是否为空
bool TrieEmpty(Trie_node* root);

// 查找单词
bool TrieSearch(Trie_node* root, const char* target, Record& x);

// 插入单词
bool TrieInsert(Trie_node*& root, const Record& new_entry);

// 删除单词
bool TrieDelete(Trie_node*& root, const char* entry);

// 按照字典序遍历所有单词
void DisplayByOrder(Trie_node* root);

// 按照单词长度遍历所有单词
void DisplayByLength(Trie_node* root);
