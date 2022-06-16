#pragma once
#include<iostream>
#include<string>
using namespace std;

typedef struct TreeNode {
	char data;
	struct TreeNode* pleft, * pright;
	/*0��ʾҶ�ӽڵ㣬1��ʾǰ��/��̽ڵ�*/
	int ltag;
	int rtag;
}TNode,*BTree;
TNode* pre;
TNode* head;
void inOrderThreadTree(BTree& T);
void inOrderTraverse(BTree& T);
void createTree(BTree& T);