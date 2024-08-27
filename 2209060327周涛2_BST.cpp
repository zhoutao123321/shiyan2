#include "BST.h"

// ���ٶ��������� bt(�������)
void DestroyBST(BSTNode*& bt) {
    if (bt) {
        DestroyBST(bt->lchild);  // �ݹ�����������
        DestroyBST(bt->rchild);  // �ݹ�����������
        free(bt);                // �ͷŵ�ǰ�ڵ�
        bt = NULL;               // ��ָ���ÿ�
    }
}

// �����ն���������
BSTNode* InitBST(BSTNode*& bt) {
    bt = NULL;  // ��ʼ�����ڵ�Ϊ NULL
    return bt;  // ���ؿ����ĸ��ڵ�
}

// �ڶ��������� bt �в���һ���ؼ���Ϊ k �Ľ��
BSTNode* InsertBST(BSTNode* bt, KeyType k) {
    if (!bt) {
        // �����ǰ�ڵ�Ϊ�գ������½ڵ�
        bt = (BSTNode*)malloc(sizeof(BSTNode)); // �����ڴ�
        bt->key = k;                           // ���ýڵ�Ĺؼ���
        bt->lchild = bt->rchild = NULL;        // ��ʼ�����Һ���Ϊ NULL
    }
    else if (k < bt->key) {
        // �ؼ���С�ڵ�ǰ�ڵ�ؼ��֣�����������
        bt->lchild = InsertBST(bt->lchild, k);
    }
    else if (k > bt->key) {
        // �ؼ��ִ��ڵ�ǰ�ڵ�ؼ��֣�����������
        bt->rchild = InsertBST(bt->rchild, k);
    }
    return bt;  // ���ز����ĸ��ڵ�
}

// ���һ�������������ʹ�ã�����������Ƕ�ײ��
void DispBST(BSTNode* bt) {
    if (bt) {
        printf("%d(", bt->key); // ��ӡ��ǰ�ڵ�ؼ���
        DispBST(bt->lchild);    // ��ӡ������
        printf(",");            // ��ӡ�ָ���
        DispBST(bt->rchild);    // ��ӡ������
        printf(")");            // ��ӡ������
    }
    else {
        printf("");  // ��ǰ�ڵ�Ϊ��ʱ����ӡ���ַ���
    }
}

// �ݹ��㷨���ڶ��������� bt �в��ҹؼ���Ϊ k �Ľ��
BSTNode* SearchBST(BSTNode* bt, KeyType k) {
    if (!bt || bt->key == k) {
        return bt;  // �ҵ��ڵ����Ϊ��ʱ���ص�ǰ�ڵ�
    }
    else if (k < bt->key) {
        return SearchBST(bt->lchild, k);  // ���������в���
    }
    else {
        return SearchBST(bt->rchild, k);  // ���������в���
    }
}

// �� bt ��ɾ���ؼ���Ϊ k �Ľ��
BSTNode* DeleteBST(BSTNode* bt, KeyType k) {
    if (!bt) return NULL;  // ��Ϊ��ʱ���� NULL

    if (k < bt->key) {
        bt->lchild = DeleteBST(bt->lchild, k);  // ����������ɾ��
    }
    else if (k > bt->key) {
        bt->rchild = DeleteBST(bt->rchild, k);  // ����������ɾ��
    }
    else {
        // �ҵ�Ҫɾ���Ľڵ�
        if (!bt->lchild) {
            // �ڵ�ֻ����������û������
            BSTNode* temp = bt->rchild;
            free(bt);  // �ͷŵ�ǰ�ڵ�
            return temp;  // �����������ĸ��ڵ�
        }
        else if (!bt->rchild) {
            // �ڵ�ֻ��������
            BSTNode* temp = bt->lchild;
            free(bt);  // �ͷŵ�ǰ�ڵ�
            return temp;  // �����������ĸ��ڵ�
        }
        // �ڵ�����������
        BSTNode* temp = bt->rchild;
        while (temp && temp->lchild) {
            temp = temp->lchild;  // �ҵ�������������ڵ�
        }
        bt->key = temp->key;  // ��������������ڵ��滻��ǰ�ڵ�
        bt->rchild = DeleteBST(bt->rchild, temp->key);  // ɾ��������������ڵ�
    }
    return bt;  // ����ɾ����ĸ��ڵ�
}

// �п�
bool BSTEmpty(BSTNode* bt) {
    return bt == NULL;  // �жϸ��ڵ��Ƿ�Ϊ��
}

// ������
int BSTHeight(BSTNode* bt) {
    if (!bt) return 0;  // ��Ϊ��ʱ���߶�Ϊ0
    int lheight = BSTHeight(bt->lchild);  // �����������߶�
    int rheight = BSTHeight(bt->rchild);  // �����������߶�
    return (lheight > rheight ? lheight : rheight) + 1;  // �����������߶ȼ�1
}

// ��������ĵݹ��㷨
void PreOrder(BSTNode* bt) {
    if (bt) {
        printf("%d ", bt->key);  // ���ʸ��ڵ�
        PreOrder(bt->lchild);    // �������������
        PreOrder(bt->rchild);    // �������������
    }
}

// ��������ĵݹ��㷨
void InOrder(BSTNode* bt) {
    if (bt) {
        InOrder(bt->lchild);     // �������������
        printf("%d ", bt->key);  // ���ʸ��ڵ�
        InOrder(bt->rchild);     // �������������
    }
}

// ��������ĵݹ��㷨
void PostOrder(BSTNode* bt) {
    if (bt) {
        PostOrder(bt->lchild);   // �������������
        PostOrder(bt->rchild);   // �������������
        printf("%d ", bt->key);  // ���ʸ��ڵ�
    }
}
