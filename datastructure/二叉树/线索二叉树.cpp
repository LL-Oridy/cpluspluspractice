#include"tree.h"

void createTree(BTree& T) {
	char ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else
	{
		T = new TNode();
		T->ltag = 0;
		T->rtag = 0;
		T->data = ch;
		createTree(T->pleft);
		createTree(T->pright);
	}
}
void inOrderThreadTree(BTree& T) {
	if (T == NULL) {
		return;
	}
	//处理左子树
	inOrderThreadTree(T->pleft);
	//找到的是第一个节点
	if (T->pleft == NULL) {
		T->ltag = 1;
		T->pleft = pre;
	}
	if (pre != NULL && pre->pright == NULL) {
		pre->pright = T;
		pre->rtag = 1;
	}
	//处理根节点
	pre = T;
	//处理右子树
	inOrderThreadTree(T->pright);
}

void inOrderTraverse(BTree& T) {
	while (T) {
		while (T->ltag == 0) {
			T = T->pleft;
		}
		cout << T->data << " ";
		while (T->rtag == 1 && T->pright != NULL) {
			T = T->pright;
			cout << T->data << " ";
		}
		T = T->pright;
	}
}

void main() {
	BTree T;
	createTree(T);
	inOrderThreadTree(T);
	inOrderTraverse(T);

}