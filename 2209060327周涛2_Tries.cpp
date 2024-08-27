#define _CRT_SECURE_NO_WARNINGS // 禁用安全警告

#include "Tries.h"
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// 初始化 Trie 树
void InitTrie(Trie_node*& root) {
    // 分配根节点
    root = new Trie_node();
    root->data = nullptr; // 根节点数据为空
    // 初始化所有子节点为空
    for (int i = 0; i < num_chars; i++) {
        root->branch[i] = nullptr;
    }
}

// 销毁 Trie 树
void DestroyTrie(Trie_node*& root) {
    if (root) {
        // 递归销毁所有子节点
        for (int i = 0; i < num_chars; i++) {
            DestroyTrie(root->branch[i]);
        }
        // 删除当前节点的数据
        delete root->data;
        // 删除当前节点
        delete root;
        root = nullptr; // 将根节点指针置为空
    }
}

// 判断 Trie 树是否为空
bool TrieEmpty(Trie_node* root) {
    // 如果根节点为空，树为空
    if (!root) return true;
    // 遍历所有子节点
    for (int i = 0; i < num_chars; i++) {
        // 如果有任何子节点不为空，树不为空
        if (root->branch[i]) return false;
    }
    // 所有子节点都为空，树为空
    return true;
}

// 查找单词
bool TrieSearch(Trie_node* root, const char* target, Record& x) {
    Trie_node* current = root; // 从根节点开始
    // 遍历目标单词的每个字符
    for (int i = 0; i < strlen(target); i++) {
        int index = target[i] - 'a'; // 计算字符在子节点数组中的索引
        // 找不到相应的子节点，返回 false
        if (!current->branch[index]) return false;
        // 移动到子节点
        current = current->branch[index];
    }
    // 如果当前节点有数据，复制数据到 x
    if (current->data) {
        x = *(current->data);
        return true;
    }
    // 单词不存在
    return false;
}

// 插入单词
bool TrieInsert(Trie_node*& root, const Record& new_entry) {
    // 如果根节点为空，初始化 Trie 树
    if (!root) InitTrie(root);
    Trie_node* current = root; // 从根节点开始
    // 遍历新单词的每个字符
    for (int i = 0; i < strlen(new_entry.key); i++) {
        int index = new_entry.key[i] - 'a'; // 计算字符在子节点数组中的索引
        // 如果相应的子节点不存在，创建新的子节点
        if (!current->branch[index]) {
            current->branch[index] = new Trie_node();
            current->branch[index]->data = nullptr;
            for (int j = 0; j < num_chars; j++) {
                current->branch[index]->branch[j] = nullptr;
            }
        }
        // 移动到子节点
        current = current->branch[index];
    }
    // 如果当前节点没有数据，插入新单词
    if (!current->data) {
        current->data = new Record(new_entry);
        return true;
    }
    // 单词已存在
    return false;
}

// 删除单词
bool TrieDelete(Trie_node*& root, const char* entry) {
    // Trie 树为空，返回 false
    if (!root) return false;
    Trie_node* current = root; // 从根节点开始
    stack<Trie_node*> nodes; // 用于存储路径节点
    // 遍历要删除单词的每个字符
    for (int i = 0; i < strlen(entry); i++) {
        int index = entry[i] - 'a'; // 计算字符在子节点数组中的索引
        // 找不到单词，返回 false
        if (!current->branch[index]) return false;
        // 将当前节点压入栈
        nodes.push(current);
        // 移动到子节点
        current = current->branch[index];
    }
    // 如果当前节点有数据
    if (current->data) {
        delete current->data; // 删除单词数据
        current->data = nullptr;
        // 逆序处理路径节点，删除空节点
        while (!nodes.empty()) {
            Trie_node* node = nodes.top();
            nodes.pop();
            int index = entry[nodes.size()] - 'a'; // 计算当前节点的字符索引
            // 如果该节点的子节点为空，删除该节点
            if (TrieEmpty(node->branch[index])) {
                delete node->branch[index];
                node->branch[index] = nullptr;
            }
            else {
                break;
            }
        }
        return true;
    }
    // 单词不存在
    return false;
}

void DisplayByOrderHelper(Trie_node* root, const char* prefix) {
    if (!root) return; // 树为空，返回

    // 如果当前节点有数据，打印单词
    if (root->data) {
        printf("%s\n", root->data->key);
    }

    // 遍历所有子节点
    for (int i = 0; i < num_chars; i++) {
        if (root->branch[i]) {
            size_t len = strlen(prefix); // 计算当前前缀长度
            char* new_prefix = new char[len + 2]; // 分配新的前缀字符串
            strcpy(new_prefix, prefix); // 复制当前前缀
            new_prefix[len] = 'a' + i; // 添加当前字符
            new_prefix[len + 1] = '\0'; // 添加字符串结束符
            DisplayByOrderHelper(root->branch[i], new_prefix); // 递归遍历子节点
            delete[] new_prefix; // 释放新的前缀字符串
        }
    }
}

// 按照字典序遍历所有单词
void DisplayByOrder(Trie_node* root) {
    DisplayByOrderHelper(root, ""); // 初始前缀为空
}


// 按照单词长度遍历所有单词
void DisplayByLength(Trie_node* root) {
    if (!root) return; // 根节点为空，返回

    queue<pair<Trie_node*, string>> nodes; // 用于存储节点及其前缀的队列
    nodes.push({ root, "" }); // 将根节点及空前缀压入队列

    while (!nodes.empty()) {
        auto node_pair = nodes.front(); // 获取队首元素
        nodes.pop(); // 弹出队首元素
        Trie_node* node = node_pair.first;
        string prefix = node_pair.second;

        // 如果当前节点有数据，打印单词
        if (node->data) {
            cout << node->data->key << endl;
        }

        // 遍历所有子节点
        for (int i = 0; i < num_chars; i++) {
            if (node->branch[i]) {
                string new_prefix = prefix + char('a' + i); // 添加当前字符
                nodes.push({ node->branch[i], new_prefix }); // 将子节点及新前缀压入队列
            }
        }
    }
}
