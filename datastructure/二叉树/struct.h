#pragma once
#include<iostream>
#include<string>
#define MAXSIZE 20
using namespace std;


typedef struct tree {
	char data;
	struct tree* pleft, *pright;
}BiTNode,*BiTree;

typedef struct queue {
	BiTNode* s[MAXSIZE];
	int top;
	int bottom;
}pQueue,*Queue;

void InitQueue(Queue& T);
void EnQueue(Queue& T,BiTree& L);
void DeQueue(Queue& T, BiTree& L);

void preOrder(BiTree& L);
void midOrder(BiTree L);
void postOrder(BiTree L);

void createInsertTree(BiTree& L, int* a,int len);
//void createBiTree(BiTree& L);
void insertBiTree(BiTree& L, int val);
int getHeight(BiTree L);
int getMax(BiTree L);
void bianli(BiTree& L);