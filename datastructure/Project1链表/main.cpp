#pragma once
#include<iostream>
using namespace std;
#include"struct.h"

//��ʼ��
Linklist& Initlist(Linklist& L) {
	L = new LNode;
	L->next = NULL;
	return L;
}

//ͷ��
Linklist& headInsert(Linklist& L) {
	cout << "������Ҫ����Ľڵ�" << endl;
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


//����
bool Reverse(Linklist& L) {
	//��pָ���һ��Ԫ��
	LNode* p = L->next, * r;
	//��ͷ�ڵ�͵�һ��Ԫ�ضϿ�
	L->next = NULL;
	//��p��Ϊ��ʱ��ʾp��û�е����һ��Ԫ����һ��Ԫ�أ�����ѭ��
	while (p != NULL) {
		//��rָ��ָ��p����һ��Ԫ�أ���ֹp����һ���ڵ�Ͽ����Ҳ���
		r = p->next;
		//������������ͷ�����
		p->next = L->next;
		L->next = p;
		//p���ƿ�ʼִ����һ��Ԫ��
		p = r;
	}
	return true;
}

//β��
bool TailInsert(Linklist& L) {
	LNode* pTail = L;
	cout << "������Ҫ����Ľڵ�" << endl;
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

//��ָ���ڵ�ǰһ�����
LNode* getElem(Linklist L, int i) {
	LNode* p = L;
	int j = 0;
	while (p!=NULL&&j < i - 1) {
		p = p->next;
		j++;
	}
	return p;
}

//��λ����
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

//ɾ��
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

//��ӡ
void print(Linklist L) {
	if (L->next == NULL) {
		cout << "û�нڵ�" << endl;
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
	cout << "ͷ��Ľ����" << endl;
	print(L);
	Reverse(L);
	cout << "ͷ������" << endl;
	print(L);

	/*TailInsert(L);
	cout << "β��Ľ����" << endl;
	print(L);
	InsertLink(L, 2, 5);
	cout << "β������λ����Ľ����" << endl;
	print(L);
	deleteList(L, 3);
	cout << "ɾ����Ľ����" << endl;
	print(L);*/
	return 0;
}
