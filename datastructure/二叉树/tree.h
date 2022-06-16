#pragma once
#include<iostream>
#include<string>
using namespace std;

typedef struct TreeNode {
	char data;
	struct TreeNode* pleft, * pright;
	/*0表示叶子节点，1表示前驱/后继节点*/
	int ltag;
	int rtag;
}TNode,*BTree;
TNode* pre;
TNode* head;
void inOrderThreadTree(BTree& T);
void inOrderTraverse(BTree& T);
void createTree(BTree& T);