#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHARS 26 // ����ֻ����Сд��ĸ

// Trie ���ڵ�ṹ
typedef struct TrieNode {
    int isEndOfWord; // ����Ƿ���һ�����ʵĽ�β
    struct TrieNode* children[NUM_CHARS]; // �ӽڵ�ָ�����飬ÿ���ڵ��� 26 ���ӽڵ�
} TrieNode;

// ����ԭ��

// ����һ���µ� Trie ���ڵ�
// ���أ��´����� Trie ���ڵ�ָ��
TrieNode* createNode();

// �� Trie ���в���һ������
// ������root - Trie ���ĸ��ڵ�
//      key - Ҫ����ĵ���
void insert(TrieNode* root, const char* key);

// �� Trie ��������һ������
// ������root - Trie ���ĸ��ڵ�
//      key - Ҫ�����ĵ���
// ���أ�����ҵ����� 1�����򷵻� 0
int search(TrieNode* root, const char* key);

// �� Trie ����ɾ��һ������
// ������root - Trie ���ĸ��ڵ�
//      key - Ҫɾ���ĵ���
void deleteKeywords(TrieNode* root, const char* key);

// ���ֵ������ Trie ���еĵ��ʣ�����ָ����������ʾ
// ������root - Trie ���ĸ��ڵ�
//      prefix - ��ǰǰ׺
//      level - ��ǰ�������Ĳ㼶
//      count - ��ǰ������ĵ��ʼ���
//      columns - ÿ����ʾ������
void display(TrieNode* root, char* prefix, int level, int* count, int columns);

// ��ָ��������ʾ Trie ���еĵ���
// ������root - Trie ���ĸ��ڵ�
//      columns - ÿ����ʾ������
void displayByColumns(TrieNode* root, int columns);

// ��ʼ�� Trie �������� C ���Ե����йؼ���
// ������root - Trie ���ĸ��ڵ�
void initKeywords(TrieNode* root);

// ��ʾ�˵�
void displayMenu();

// �ж�һ�������Ƿ�Ϊ C ���ԵĹؼ���
// ������root - Trie ���ĸ��ڵ�
//      key - Ҫ�жϵĵ���
// ���أ�����ǹؼ��ַ��� 1�����򷵻� 0
int isKeyword(TrieNode* root, const char* key);

