#include"struct.h"

bool Initlist(pStack_t& top) {
	top = new Stack_t;
	if (top == NULL) {
		cout << "����ʧ��" << endl;
	}
	top = NULL;
	return true;
}

//ѹջ
bool push(pStack_t& top) {
	int num;
	cout << "��������ջԪ��,10ֹͣ��ջ" << endl;
	cin >> num;
	while (num != 10) {
		Stack_t* pNew = new Stack_t;
		cout << num << "��ջ" << endl;
		pNew->data = num;
		pNew->pNext = top;
		top = pNew;
		cin >> num;
	}
	return true;
}

//��ջ
bool pop(pStack_t& top) {
	if (top == NULL) {
		cout << "��ջ" << endl;
		return false;
	}
	int num;
	while (top) {
		Stack_t* pCur = top;
		num = top->data;
		cout << num << "��ջ" << endl;
		top = top->pNext;
		delete pCur;
	}
	return true;
}

//��ӡ
void print(pStack_t top) {
	if (top == NULL) {
		cout << "û��Ԫ��" << endl;
		return;
	}
	else {
		Stack_t* p = top;
		while (p) {
			cout << p->data << " ";
			p = p->pNext;
		}
		cout << endl;
	}
}

int main() {
	pStack_t top;
	//�������topָ��ı���
	Initlist(top);
	push(top);
	pop(top);
	print(top);
	return 0;
}