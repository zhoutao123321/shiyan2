#pragma once

const int num_chars = 26; // ��ĸ���С

// ��¼�ṹ
struct Record {
    char key[50]; // �ؼ��֣����ʣ�
    // ���Ը�����Ҫ��չ�������ݳ�Ա
};

// Trie ���ڵ�ṹ
struct Trie_node {
    Record* data; // ָ���¼��ָ��
    Trie_node* branch[num_chars]; // �ӽڵ�����
};

// ��ʼ�� Trie ��
void InitTrie(Trie_node*& root);

// ���� Trie ��
void DestroyTrie(Trie_node*& root);

// �ж� Trie ���Ƿ�Ϊ��
bool TrieEmpty(Trie_node* root);

// ���ҵ���
bool TrieSearch(Trie_node* root, const char* target, Record& x);

// ���뵥��
bool TrieInsert(Trie_node*& root, const Record& new_entry);

// ɾ������
bool TrieDelete(Trie_node*& root, const char* entry);

// �����ֵ���������е���
void DisplayByOrder(Trie_node* root);

// ���յ��ʳ��ȱ������е���
void DisplayByLength(Trie_node* root);
