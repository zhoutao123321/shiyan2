#define _CRT_SECURE_NO_WARNINGS // 禁用安全警告

#include "Tries.h"
#include <stdio.h>
#include <string.h>

// 主函数
int main() {
    Trie_node* root = nullptr;
    InitTrie(root); // 初始化 Trie 树

    // 定义要插入的单词记录
    Record rec1 = { "apple" };
    Record rec2 = { "banana" };
    Record rec3 = { "grape" };
    Record rec4 = { "apricot" };
    Record rec5 = { "blueberry" };

    // 插入单词
    TrieInsert(root, rec1);
    TrieInsert(root, rec2);
    TrieInsert(root, rec3);
    TrieInsert(root, rec4);
    TrieInsert(root, rec5);

    // 查找单词 "banana"
    Record searchResult;
    if (TrieSearch(root, "banana", searchResult)) {
        printf("找到: %s\n", searchResult.key);
    }
    else {
        printf("未找到: banana\n");
    }

    // 按字典序遍历所有单词
    printf("字典顺序中的 Trie 内容:\n");
    DisplayByOrder(root);

    // 按长度遍历所有单词
    printf("按长度排序的 Trie 内容:\n");
    DisplayByLength(root);

    // 删除单词 "banana"
    TrieDelete(root, "banana");

    // 再次按字典序遍历，查看删除结果
    printf("删除 'banana' 后:\n");
    DisplayByOrder(root);

    // 销毁 Trie 树
    DestroyTrie(root);

    // 检查 Trie 是否为空
    if (TrieEmpty(root)) {
        printf("销毁后 Trie 为空。\n");
    }
    else {
        printf("销毁后 Trie 不为空。\n");
    }

    return 0;
}
