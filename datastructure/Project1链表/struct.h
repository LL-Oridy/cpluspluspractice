#pragma once
#include<iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* next;
}LNode,*Linklist;
 
Linklist& Initlist(Linklist& L);
Linklist& headInsert(Linklist& L);
bool Reverse(Linklist& L);
bool TailInsert(Linklist& L);
void print(Linklist L);
bool InsertLink(Linklist& L, int i, int e);
LNode* getElem(Linklist L, int i);
bool deleteList(Linklist& L, int i);

