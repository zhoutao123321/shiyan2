#define _CRT_SECURE_NO_WARNINGS // ���ð�ȫ����

#include "Tries.h"
#include <stdio.h>
#include <string.h>

// ������
int main() {
    Trie_node* root = nullptr;
    InitTrie(root); // ��ʼ�� Trie ��

    // ����Ҫ����ĵ��ʼ�¼
    Record rec1 = { "apple" };
    Record rec2 = { "banana" };
    Record rec3 = { "grape" };
    Record rec4 = { "apricot" };
    Record rec5 = { "blueberry" };

    // ���뵥��
    TrieInsert(root, rec1);
    TrieInsert(root, rec2);
    TrieInsert(root, rec3);
    TrieInsert(root, rec4);
    TrieInsert(root, rec5);

    // ���ҵ��� "banana"
    Record searchResult;
    if (TrieSearch(root, "banana", searchResult)) {
        printf("�ҵ�: %s\n", searchResult.key);
    }
    else {
        printf("δ�ҵ�: banana\n");
    }

    // ���ֵ���������е���
    printf("�ֵ�˳���е� Trie ����:\n");
    DisplayByOrder(root);

    // �����ȱ������е���
    printf("����������� Trie ����:\n");
    DisplayByLength(root);

    // ɾ������ "banana"
    TrieDelete(root, "banana");

    // �ٴΰ��ֵ���������鿴ɾ�����
    printf("ɾ�� 'banana' ��:\n");
    DisplayByOrder(root);

    // ���� Trie ��
    DestroyTrie(root);

    // ��� Trie �Ƿ�Ϊ��
    if (TrieEmpty(root)) {
        printf("���ٺ� Trie Ϊ�ա�\n");
    }
    else {
        printf("���ٺ� Trie ��Ϊ�ա�\n");
    }

    return 0;
}
