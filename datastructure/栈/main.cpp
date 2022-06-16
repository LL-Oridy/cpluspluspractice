#include"struct.h"

bool Initlist(pStack_t& top) {
	top = new Stack_t;
	if (top == NULL) {
		cout << "分配失败" << endl;
	}
	top = NULL;
	return true;
}

//压栈
bool push(pStack_t& top) {
	int num;
	cout << "请输入入栈元素,10停止入栈" << endl;
	cin >> num;
	while (num != 10) {
		Stack_t* pNew = new Stack_t;
		cout << num << "入栈" << endl;
		pNew->data = num;
		pNew->pNext = top;
		top = pNew;
		cin >> num;
	}
	return true;
}

//弹栈
bool pop(pStack_t& top) {
	if (top == NULL) {
		cout << "空栈" << endl;
		return false;
	}
	int num;
	while (top) {
		Stack_t* pCur = top;
		num = top->data;
		cout << num << "出栈" << endl;
		top = top->pNext;
		delete pCur;
	}
	return true;
}

//打印
void print(pStack_t top) {
	if (top == NULL) {
		cout << "没有元素" << endl;
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
	//传入的是top指针的别名
	Initlist(top);
	push(top);
	pop(top);
	print(top);
	return 0;
}