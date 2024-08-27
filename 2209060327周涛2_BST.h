#pragma once

#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;    //����ؼ�������
typedef char InfoType;

typedef struct node
{
	KeyType key;    //�ؼ�����
	InfoType data;  //����������
	struct node* lchild, * rchild; //���Һ���ָ��
} BSTNode;    //�����������������


void DestroyBST(BSTNode*& bt);     //���ٶ��������� bt
BSTNode* InitBST(BSTNode*& bt);    //�����ն���������
BSTNode* InsertBST(BSTNode* bt, KeyType k);   //�ڶ��������� bt �в���һ���ؼ���Ϊ k �Ľ��
void DispBST(BSTNode* bt);        //���һ�������������ʹ�ã�����������Ƕ�ײ��
BSTNode* SearchBST(BSTNode* bt, KeyType k);   //�ݹ��㷨���ڶ��������� bt �в��ҹؼ���Ϊ k �Ľ��
BSTNode* DeleteBST(BSTNode* bt, KeyType k);     //�� bt ��ɾ���ؼ���Ϊ k �Ľ��
bool BSTEmpty(BSTNode* bt);   //�п�
int BSTHeight(BSTNode* b);   //������
void PreOrder(BSTNode* b);   //��������ĵݹ��㷨
void InOrder(BSTNode* b);    //��������ĵݹ��㷨
void PostOrder(BSTNode* b);   //��������ĵݹ��㷨