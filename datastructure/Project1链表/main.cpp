#pragma once
#include<iostream>
using namespace std;
#include"struct.h"

//初始化
Linklist& Initlist(Linklist& L) {
	L = new LNode;
	L->next = NULL;
	return L;
}

//头插
Linklist& headInsert(Linklist& L) {
	cout << "请输入要插入的节点" << endl;
	int num;
	cin >> num;
	while (num != 9999) {
		LNode* pNew = new LNode;
		pNew->data = num;
		pNew->next = L->next;
		L->next = pNew;
		cin >> num;
	}
	return L;
}


//逆置
bool Reverse(Linklist& L) {
	//将p指向第一个元素
	LNode* p = L->next, * r;
	//将头节点和第一个元素断开
	L->next = NULL;
	//当p不为空时表示p还没有到最后一个元素下一个元素，可以循环
	while (p != NULL) {
		//将r指针指向p的下一个元素，防止p和下一个节点断开了找不到
		r = p->next;
		//这两个步骤是头插操作
		p->next = L->next;
		L->next = p;
		//p后移开始执行下一个元素
		p = r;
	}
	return true;
}

//尾插
bool TailInsert(Linklist& L) {
	LNode* pTail = L;
	cout << "请输入要插入的节点" << endl;
	int num;
	cin >> num;

	while (num != 9999) {
		LNode* pNew = new LNode;
		pNew->data = num;
		pTail->next = pNew;
		pTail = pNew;
		cin >> num;
	}
	pTail->next = NULL;
	return true;
}

//找指定节点前一个结点
LNode* getElem(Linklist L, int i) {
	LNode* p = L;
	int j = 0;
	while (p!=NULL&&j < i - 1) {
		p = p->next;
		j++;
	}
	return p;
}

//按位插入
bool InsertLink(Linklist& L, int i, int e) {
	if (i < 1) {
		return false;
	}
	LNode* p = getElem(L, i);
	if (p == NULL) {
		return false;
	}
	LNode* pNew = new LNode;
	pNew->data = e;
	pNew->next = p->next;
	p->next = pNew;
	return true;
}

//删除
bool deleteList(Linklist& L, int i) {
	if (i < 0) {
		return false;
	}
	LNode* p = getElem(L, i);
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;
	p->next = q->next;
	delete q;
	return true;
}

//打印
void print(Linklist L) {
	if (L->next == NULL) {
		cout << "没有节点" << endl;
		return;
	}
	else {
		LNode* p = L->next;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

}


int main() {
	Linklist L;
	Initlist(L);
	L = headInsert(L);
	cout << "头插的结果是" << endl;
	print(L);
	Reverse(L);
	cout << "头插逆置" << endl;
	print(L);

	/*TailInsert(L);
	cout << "尾插的结果是" << endl;
	print(L);
	InsertLink(L, 2, 5);
	cout << "尾插结果按位插入的结果是" << endl;
	print(L);
	deleteList(L, 3);
	cout << "删除后的结果是" << endl;
	print(L);*/
	return 0;
}
