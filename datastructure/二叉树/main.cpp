#include"struct.h"
//��ʼ��
void InitQueue(Queue& T) {
	T = new pQueue();
	T->top = 0;
	T->bottom = 0;
}
//���
void EnQueue(Queue& T, BiTree& L) {
	if ((T->bottom + 1) % MAXSIZE == T->top) {
		return;
	}
	T->s[T->bottom] = L;
	T->bottom = (T->bottom + 1) % MAXSIZE;
}
//����
void DeQueue(Queue& T,BiTree& L) {
	if (T->bottom == T->top) {
		return ;
	}
	L = T->s[T->top];
	T->top = (T->top + 1) % MAXSIZE;
}
//���򴴽���
void createBiTree(BiTree& L){
	char num;
	cin >> num;
	if (num == '#') {
		L = NULL;
	}
	else {
		L = new BiTNode;
		L->data = num;
		createBiTree(L->pleft);
		createBiTree(L->pright);
	}
}

//�������
void insertBiTree(BiTree& L, int val) {
	if (L == NULL) {
		BiTNode* pNew = new BiTNode();
		pNew->data = val;
		pNew->pleft = NULL;
		pNew->pright = NULL;
		L = pNew;
	}
	else {
		if (val > L->data) {
			insertBiTree(L->pright, val);
		}
		else if (val < L->data) {
			insertBiTree(L->pleft, val);
		}
	}
}
//���β���
void createInsertTree(BiTree& L, int* a,int len) {
	L = NULL;
	for (int i = 0; i < len; i++)
	{
		insertBiTree(L, a[i]);
	}
}

//�������
void bianli(BiTree& L) {
	Queue q;
	q = new pQueue();
	InitQueue(q);
	//���û�нڵ�
	if (L == NULL) {
		return;
	}
	else {
		//���ͷ�ڵ�
		EnQueue(q, L);
		//�Ӳ�Ϊ��
		while (q->top != q->bottom) {
			//����ͷ�ڵ�
			DeQueue(q, L);
			cout << L->data << " ";
			if (L->pleft != NULL) {
				EnQueue(q, L->pleft);
			}
			if (L->pright != NULL) {
				EnQueue(q, L->pright);
			}
		}
	}
}

//���ĸ߶�
int getHeight(BiTree L) {
	if (L == NULL) {
		return 0;
	}
	else {
		int getLeft = getHeight(L->pleft);
		int getRight = getHeight(L->pright);
		int max = (getLeft > getRight) ? getLeft : getRight;
		return max + 1;
	}
}

//���Ҷ�ӽڵ�
int getMax(BiTree L) {
	if (L == NULL) {
		return -1;
	}
	else {
		int getLeft = getMax(L->pleft);
		int getRight = getMax(L->pright);
		int mid = L->data;
		int max = (getLeft > getRight ? getLeft : getRight) > mid ? (getLeft > getRight ? getLeft : getRight) : mid;
		return max;
	}
}

//ǰ������������
void preOrder(BiTree& L) {
	if (L != NULL) {
		preOrder(L->pleft);
		cout << L->data;
		preOrder(L->pright);
	}
}
void midOrder(BiTree L) {
	if (L != NULL) {
		cout << L->data;
		midOrder(L->pleft);
		midOrder(L->pright);
	}
}
void postOrder(BiTree L) {
	if (L != NULL) {
		postOrder(L->pleft);
		postOrder(L->pright);
		cout << L->data;
	}
}

//int main() {
//	BiTree L;
//
//	createBiTree(L);
//	//int arr[5] = { 3,9,20,15,7 };
//	//int len = sizeof(arr)/sizeof(arr[0]);
//	//createInsertTree(L, arr,len);
//
//	cout << "h = " << getHeight(L) << endl;
//	cout << "max = " << (char)getMax(L) << endl;
//	/*preOrder(L);
//	cout << endl;*/
//	cout << "��α�����" << " ";
//	bianli(L);
//	cout << endl;
//	/*midOrder(L);
//	cout << endl;
//	postOrder(L);
//	cout << endl;*/
//
//
//	/*cout << "�����������" << endl;
//	createBiTree(T);
//	cout << "����������" << endl;
//	preOrder(T);
//	cout << endl;
//	cout << "����������" << endl;
//	midOrder(T);
//	cout << endl;
//	cout << "�����������" << endl;
//	postOrder(T);*/
//	return 0;
//}