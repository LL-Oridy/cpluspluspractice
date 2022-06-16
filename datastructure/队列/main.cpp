#include"struct.h"

void Initlist(Qlink* L) {
	L->front = new Queue;
	if (L->front == NULL) {
		return;
	}
	L->rear = L->front;
	L->front->pNext = NULL;
	L->rear->pNext = NULL;
}

bool Insertlist(Qlink* L) {
	if (L->front->pNext == NULL) {
		int num;
		cout << "请输入插入的第一个元素" << endl;
		cin >> num;
		Queue* pNew = new Queue;
		pNew->num = num;
		pNew->pNext = L->rear->pNext;
		L->front->pNext = pNew;
		L->rear->pNext = pNew;
		L->rear = pNew;
	}
	int num;
	cout << "请输入后续待插入元素" << endl;
	cin >> num;
	while (num != 10) {
		Queue* pNew = new Queue;
		pNew->num = num;
		pNew->pNext = L->rear->pNext;
		L->rear->pNext = pNew;
		L->rear = pNew;
		cin >> num;
	}
	return true;
}

bool Deletelist(Qlink* L) {
	if (L->front == L->rear) {
		cout << "没有元素" << endl;
		return false;
	}

	while (L->front->pNext != NULL) {
		Queue* pCur = L->front->pNext;
		int e;
		e = pCur->num;
		cout << "删除的元素是" << e << endl;
		L->front->pNext = pCur->pNext;
		if (L->rear == pCur) {
			L->rear = L->front;
		}
		delete pCur;
	}
	return true;
}


int main() {
	Qlink* L;
	L = new Qlink;
	Initlist(L);
	Insertlist(L);
	Deletelist(L);
	return 0;
}