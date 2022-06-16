#include"struct.h"
//初始化
void InitQueue(Queue& T) {
	T = new pQueue();
	T->top = 0;
	T->bottom = 0;
}
//入队
void EnQueue(Queue& T, BiTree& L) {
	if ((T->bottom + 1) % MAXSIZE == T->top) {
		return;
	}
	T->s[T->bottom] = L;
	T->bottom = (T->bottom + 1) % MAXSIZE;
}
//出队
void DeQueue(Queue& T,BiTree& L) {
	if (T->bottom == T->top) {
		return ;
	}
	L = T->s[T->top];
	T->top = (T->top + 1) % MAXSIZE;
}
//先序创建树
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

//插入规则
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
//依次插入
void createInsertTree(BiTree& L, int* a,int len) {
	L = NULL;
	for (int i = 0; i < len; i++)
	{
		insertBiTree(L, a[i]);
	}
}

//层序遍历
void bianli(BiTree& L) {
	Queue q;
	q = new pQueue();
	InitQueue(q);
	//如果没有节点
	if (L == NULL) {
		return;
	}
	else {
		//入队头节点
		EnQueue(q, L);
		//队不为空
		while (q->top != q->bottom) {
			//出队头节点
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

//树的高度
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

//最大叶子节点
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

//前序中序后序遍历
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
//	cout << "层次遍历：" << " ";
//	bianli(L);
//	cout << endl;
//	/*midOrder(L);
//	cout << endl;
//	postOrder(L);
//	cout << endl;*/
//
//
//	/*cout << "中序遍历输入" << endl;
//	createBiTree(T);
//	cout << "先序遍历输出" << endl;
//	preOrder(T);
//	cout << endl;
//	cout << "中序遍历输出" << endl;
//	midOrder(T);
//	cout << endl;
//	cout << "后续遍历输出" << endl;
//	postOrder(T);*/
//	return 0;
//}