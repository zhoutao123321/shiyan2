#define _CRT_SECURE_NO_WARNINGS // ���ð�ȫ����

#include "Tries.h"
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// ��ʼ�� Trie ��
void InitTrie(Trie_node*& root) {
    // ������ڵ�
    root = new Trie_node();
    root->data = nullptr; // ���ڵ�����Ϊ��
    // ��ʼ�������ӽڵ�Ϊ��
    for (int i = 0; i < num_chars; i++) {
        root->branch[i] = nullptr;
    }
}

// ���� Trie ��
void DestroyTrie(Trie_node*& root) {
    if (root) {
        // �ݹ����������ӽڵ�
        for (int i = 0; i < num_chars; i++) {
            DestroyTrie(root->branch[i]);
        }
        // ɾ����ǰ�ڵ������
        delete root->data;
        // ɾ����ǰ�ڵ�
        delete root;
        root = nullptr; // �����ڵ�ָ����Ϊ��
    }
}

// �ж� Trie ���Ƿ�Ϊ��
bool TrieEmpty(Trie_node* root) {
    // ������ڵ�Ϊ�գ���Ϊ��
    if (!root) return true;
    // ���������ӽڵ�
    for (int i = 0; i < num_chars; i++) {
        // ������κ��ӽڵ㲻Ϊ�գ�����Ϊ��
        if (root->branch[i]) return false;
    }
    // �����ӽڵ㶼Ϊ�գ���Ϊ��
    return true;
}

// ���ҵ���
bool TrieSearch(Trie_node* root, const char* target, Record& x) {
    Trie_node* current = root; // �Ӹ��ڵ㿪ʼ
    // ����Ŀ�굥�ʵ�ÿ���ַ�
    for (int i = 0; i < strlen(target); i++) {
        int index = target[i] - 'a'; // �����ַ����ӽڵ������е�����
        // �Ҳ�����Ӧ���ӽڵ㣬���� false
        if (!current->branch[index]) return false;
        // �ƶ����ӽڵ�
        current = current->branch[index];
    }
    // �����ǰ�ڵ������ݣ��������ݵ� x
    if (current->data) {
        x = *(current->data);
        return true;
    }
    // ���ʲ�����
    return false;
}

// ���뵥��
bool TrieInsert(Trie_node*& root, const Record& new_entry) {
    // ������ڵ�Ϊ�գ���ʼ�� Trie ��
    if (!root) InitTrie(root);
    Trie_node* current = root; // �Ӹ��ڵ㿪ʼ
    // �����µ��ʵ�ÿ���ַ�
    for (int i = 0; i < strlen(new_entry.key); i++) {
        int index = new_entry.key[i] - 'a'; // �����ַ����ӽڵ������е�����
        // �����Ӧ���ӽڵ㲻���ڣ������µ��ӽڵ�
        if (!current->branch[index]) {
            current->branch[index] = new Trie_node();
            current->branch[index]->data = nullptr;
            for (int j = 0; j < num_chars; j++) {
                current->branch[index]->branch[j] = nullptr;
            }
        }
        // �ƶ����ӽڵ�
        current = current->branch[index];
    }
    // �����ǰ�ڵ�û�����ݣ������µ���
    if (!current->data) {
        current->data = new Record(new_entry);
        return true;
    }
    // �����Ѵ���
    return false;
}

// ɾ������
bool TrieDelete(Trie_node*& root, const char* entry) {
    // Trie ��Ϊ�գ����� false
    if (!root) return false;
    Trie_node* current = root; // �Ӹ��ڵ㿪ʼ
    stack<Trie_node*> nodes; // ���ڴ洢·���ڵ�
    // ����Ҫɾ�����ʵ�ÿ���ַ�
    for (int i = 0; i < strlen(entry); i++) {
        int index = entry[i] - 'a'; // �����ַ����ӽڵ������е�����
        // �Ҳ������ʣ����� false
        if (!current->branch[index]) return false;
        // ����ǰ�ڵ�ѹ��ջ
        nodes.push(current);
        // �ƶ����ӽڵ�
        current = current->branch[index];
    }
    // �����ǰ�ڵ�������
    if (current->data) {
        delete current->data; // ɾ����������
        current->data = nullptr;
        // ������·���ڵ㣬ɾ���սڵ�
        while (!nodes.empty()) {
            Trie_node* node = nodes.top();
            nodes.pop();
            int index = entry[nodes.size()] - 'a'; // ���㵱ǰ�ڵ���ַ�����
            // ����ýڵ���ӽڵ�Ϊ�գ�ɾ���ýڵ�
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
    // ���ʲ�����
    return false;
}

void DisplayByOrderHelper(Trie_node* root, const char* prefix) {
    if (!root) return; // ��Ϊ�գ�����

    // �����ǰ�ڵ������ݣ���ӡ����
    if (root->data) {
        printf("%s\n", root->data->key);
    }

    // ���������ӽڵ�
    for (int i = 0; i < num_chars; i++) {
        if (root->branch[i]) {
            size_t len = strlen(prefix); // ���㵱ǰǰ׺����
            char* new_prefix = new char[len + 2]; // �����µ�ǰ׺�ַ���
            strcpy(new_prefix, prefix); // ���Ƶ�ǰǰ׺
            new_prefix[len] = 'a' + i; // ��ӵ�ǰ�ַ�
            new_prefix[len + 1] = '\0'; // ����ַ���������
            DisplayByOrderHelper(root->branch[i], new_prefix); // �ݹ�����ӽڵ�
            delete[] new_prefix; // �ͷ��µ�ǰ׺�ַ���
        }
    }
}

// �����ֵ���������е���
void DisplayByOrder(Trie_node* root) {
    DisplayByOrderHelper(root, ""); // ��ʼǰ׺Ϊ��
}


// ���յ��ʳ��ȱ������е���
void DisplayByLength(Trie_node* root) {
    if (!root) return; // ���ڵ�Ϊ�գ�����

    queue<pair<Trie_node*, string>> nodes; // ���ڴ洢�ڵ㼰��ǰ׺�Ķ���
    nodes.push({ root, "" }); // �����ڵ㼰��ǰ׺ѹ�����

    while (!nodes.empty()) {
        auto node_pair = nodes.front(); // ��ȡ����Ԫ��
        nodes.pop(); // ��������Ԫ��
        Trie_node* node = node_pair.first;
        string prefix = node_pair.second;

        // �����ǰ�ڵ������ݣ���ӡ����
        if (node->data) {
            cout << node->data->key << endl;
        }

        // ���������ӽڵ�
        for (int i = 0; i < num_chars; i++) {
            if (node->branch[i]) {
                string new_prefix = prefix + char('a' + i); // ��ӵ�ǰ�ַ�
                nodes.push({ node->branch[i], new_prefix }); // ���ӽڵ㼰��ǰ׺ѹ�����
            }
        }
    }
}
