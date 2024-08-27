#pragma once

#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;    //定义关键字类型
typedef char InfoType;

typedef struct node
{
	KeyType key;    //关键字项
	InfoType data;  //其他数据域
	struct node* lchild, * rchild; //左右孩子指针
} BSTNode;    //二叉排序树结点类型


void DestroyBST(BSTNode*& bt);     //销毁二叉排序树 bt
BSTNode* InitBST(BSTNode*& bt);    //创建空二叉排序树
BSTNode* InsertBST(BSTNode* bt, KeyType k);   //在二叉排序树 bt 中插入一个关键字为 k 的结点
void DispBST(BSTNode* bt);        //输出一棵排序二叉树，使用（）标明子树嵌套层次
BSTNode* SearchBST(BSTNode* bt, KeyType k);   //递归算法：在二叉排序树 bt 中查找关键字为 k 的结点
BSTNode* DeleteBST(BSTNode* bt, KeyType k);     //在 bt 中删除关键字为 k 的结点
bool BSTEmpty(BSTNode* bt);   //判空
int BSTHeight(BSTNode* b);   //求树高
void PreOrder(BSTNode* b);   //先序遍历的递归算法
void InOrder(BSTNode* b);    //中序遍历的递归算法
void PostOrder(BSTNode* b);   //后序遍历的递归算法